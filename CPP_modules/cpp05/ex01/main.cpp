#include "Bureaucrat.hpp"
#include "Config.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

int main() {
  {
    std::cout << O_BOLD
              << "======== Valid Bureaucrat and Form Creation ========\n"
              << O_RESET;
    try {
      Bureaucrat trump("President", 1);
      Form taxForm("Tax Form", 20, 50);

      trump.signForm(taxForm);
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    std::cout << O_BOLD << "==========================================\n\n"
              << O_RESET;
  }

  {
    std::cout << O_BOLD
              << "======== Bureaucrat signs Form successfully ========\n"
              << O_RESET;
    try {
      Bureaucrat alice("Manager", 15);
      Form report("Project Report", 20, 30);

      alice.signForm(report);
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    std::cout << O_BOLD << "==========================================\n\n"
              << O_RESET;
  }

  {
    std::cout
        << O_BOLD
        << "======== Bureaucrat fails to sign Form due to low grade ========\n"
        << O_RESET;
    try {
      Bureaucrat Bob("Clerk", 50);
      Form report("Confidential Report", 10, 20);

      Bob.signForm(report);
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    std::cout << O_BOLD << "==========================================\n\n"
              << O_RESET;
  }

  {
    std::cout << O_BOLD
              << "======== Bureaucrat signs an already signed Form ========\n"
              << O_RESET;
    try {
      Bureaucrat john("Genaral", 5);
      Form executiveOrder("Executive Order", 10, 20);

      john.signForm(executiveOrder);
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    std::cout << O_BOLD << "==========================================\n\n"
              << O_RESET;
  }

  {
    std::cout << O_BOLD << "======== Invalid Form Creation ========\n"
              << O_RESET;
    try {
      Form invalidForm("Invalid Form", 0, 200);
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    std::cout << O_BOLD << "==========================================\n\n"
              << O_RESET;
  }

  return 0;
}
