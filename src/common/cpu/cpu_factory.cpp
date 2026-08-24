#include "cpu/cpu_factory.hpp"
#ifdef __linux__
#include "cpu/linux_cpu_monitor.hpp"
#endif

std::unique_ptr<CPUMonitor> CPUFactory::create() {
#ifdef __linux__
  return std::make_unique<linuxCPUMonitor>();
#else
  throw std::runtime_error("Unsupported platform");
#endif
}