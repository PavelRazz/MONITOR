#pragma once
#include "cpu/cpu_monitor.hpp"

class linuxCPUMonitor : public CPUMonitor {
 private:
  std::string model;
  int cores;

  void parseCPUInfo();

 public:
  linuxCPUMonitor();

  // Статическая информация
  std::string getModel() override;
  int getCores() override;
  int getThreads() override;
  double getFrequency() override;

  // Динамическая информация
  double getUsage() override;
  std::vector<double> getPerCoreUsage() override;
  double getTemperature() override;
};