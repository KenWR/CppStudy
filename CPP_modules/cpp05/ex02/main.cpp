#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Config.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  std::cout << O_BOLD << "=========== CPP MODULE 05 / EX 00 ===========\n\n"
            << O_RESET;

  try {
    std::cout << O_BOLD << "============= Bureaucrats =============\n"
              << O_RESET;
    Bureaucrat trump("President", 1);
    Bureaucrat elon("minister", 30);
    Bureaucrat bob("clerk", 150);
    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

    std::cout << O_BOLD << "============= Forms =============\n" << O_RESET;
    ShrubberyCreationForm shrubbery_creation("home");
    RobotomyRequestForm robotomy_request("Jack");
    PresidentialPardonForm presidential_pardon("Jack");
    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

    std::cout << O_BOLD << "============= Not signed =============\n"
              << O_RESET;
    trump.executeForm(shrubbery_creation);
    elon.executeForm(robotomy_request);
    bob.executeForm(presidential_pardon);
    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

    std::cout << O_BOLD << "============= Sign form =============\n" << O_RESET;
    trump.signForm(shrubbery_creation);
    elon.signForm(robotomy_request);
    bob.signForm(presidential_pardon);
    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

    std::cout << O_BOLD << "============= Execute form =============\n" << O_RESET;
    trump.executeForm(shrubbery_creation);
    elon.executeForm(robotomy_request);
    bob.executeForm(presidential_pardon);
    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}
