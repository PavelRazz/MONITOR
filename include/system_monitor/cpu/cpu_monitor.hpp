#pragma once
#include <string>
#include <vector>

class CPUMonitor {
 public:
  virtual ~CPUMonitor() = default;

  // Статическая информация
  virtual std::string getModel() = 0;
  virtual int getCores() = 0;
  virtual int getThreads() = 0;
  virtual double getFrequency() = 0;

  // Динамическая информация
  virtual double getUsage() = 0;
  virtual std::vector<double> getPerCoreUsage() = 0;
  virtual double getTemperature() = 0;
};