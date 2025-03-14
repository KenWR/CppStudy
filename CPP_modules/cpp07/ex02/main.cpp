#include "Array.hpp"

#include <cstddef>
#include <iostream>
#include <string>

int main() {
  {
    const Array<std::string> constArr(10);
    Array<std::string> originalArr(5);
    Array<std::string> copiedArr;
    Array<std::string> allocatedArr(originalArr);

    copiedArr = originalArr;
    for (size_t i = 0; i < originalArr.size(); ++i) {
      originalArr[i] = "abcde" + i;
      if (i == originalArr.size() / 2) {
        copiedArr = originalArr;
      }
    }

    std::cout << "originalArr:\n";
    for (size_t i = 0; i < originalArr.size(); ++i) {
      if (originalArr[i].size()) {
        std::cout << originalArr[i] << " ";
      } else {
        std::cout << "empty" << " ";
      }
    }
    std::cout << "\n";

    std::cout << "copiedArr:\n";
    for (size_t i = 0; i < copiedArr.size(); ++i) {
      if (copiedArr[i].size()) {
        std::cout << copiedArr[i] << " ";
      } else {
        std::cout << "empty" << " ";
      }
    }
    std::cout << "\n";

    std::cout << "allocatedArr:\n";
    for (size_t i = 0; i < allocatedArr.size(); ++i) {
      if (allocatedArr[i].size()) {
        std::cout << allocatedArr[i] << " ";
      } else {
        std::cout << "empty" << " ";
      }
    }
    std::cout << "\n";
  }

  std::cout << "\n===============================\n\n";

  {
    Array<std::string> *pointerArr = new Array<std::string>(3);
    for (size_t i = 0; i < pointerArr->size(); ++i) {
      (*pointerArr)[i] = "abcde" + i;
      std::cout << (*pointerArr)[i] << '\n';
    }
    delete pointerArr;
  }
}