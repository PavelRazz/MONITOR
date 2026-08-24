#include "cpu/linux_cpu_monitor.hpp"

#include <fstream>
#include <sstream>

linuxCPUMonitor::linuxCPUMonitor() { parseCPUInfo(); }

void linuxCPUMonitor::parseCPUInfo() {
  std::ifstream stat("/proc/cpuinfo");
  std::string line;

  cores = 0;

  while (std::getline(stat, line)) {
    if (line.find("model name") != std::string::npos) {
      auto pos = line.find(':');
      model = line.substr(pos + 1);
      model.erase(0, model.find_first_not_of("\t"));
    }

    if (line.find("processor") != std::string::npos) {
      cores++;
    }
  }
}

std::string linuxCPUMonitor::getModel() { return model; }
int linuxCPUMonitor::getCores() { return cores; }

double linuxCPUMonitor::getUsage() {
  std::ifstream stat("/proc/stat");
  std::string cpu;

  static long prev_idle = 0, prev_total = 0;

  long user;
  long nice;
  long system;
  long idle;
  long iowait;
  long irq;
  long softirq;
  long steal;

  stat >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >>
      steal;
  long cur_idle = idle + iowait;
  long cur_total = user + nice + system + idle + iowait + irq + softirq + steal;

  long idle_diff = cur_idle - prev_idle;
  long total_diff = cur_total - prev_total;

  prev_idle = cur_idle;
  prev_total = cur_total;
  if (total_diff == 0) return 0.0;
  return 100.0 * (total_diff - idle_diff) / total_diff;
}

int linuxCPUMonitor::getThreads() {
  return 0;  // TODO: реализовать
}

double linuxCPUMonitor::getFrequency() {
  return 0.0;  // TODO: реализовать
}

std::vector<double> linuxCPUMonitor::getPerCoreUsage() {
  return {};  // TODO: реализовать
}

double linuxCPUMonitor::getTemperature() {
  return 0.0;  // TODO: реализовать
}