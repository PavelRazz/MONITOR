#include <chrono>
#include <iostream>
#include <thread>

#include "cpu/cpu_factory.hpp"

int main() {
  try {
    auto monitor = CPUFactory::create();

    std::cout << "CPU Model " << monitor->getModel() << std::endl;
    std::cout << "Cores " << monitor->getCores() << std::endl;
    while (true) {
      std::cout << "Usage " << monitor->getUsage() << "%" << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}