#pragma once
#include <memory>

#include "cpu_monitor.hpp"

class CPUFactory {
 private:
  /* data */
 public:
  static std::unique_ptr<CPUMonitor> create();
};
