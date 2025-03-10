#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Config.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  std::cout << O_BOLD << "=========== CPP MODULE 05 / EX 00 ===========\n\n"
            << O_RESET;

  AForm *shrubberyCreation = NULL;
  AForm *robotomyRequest = NULL;
  AForm *presidentialPardon = NULL;
  AForm *wrongForm = NULL;

  try {
    std::cout << O_BOLD << "============= Bureaucrat, Intern =============\n"
              << O_RESET;
    Bureaucrat trump("President", 1);
    Intern intern;

    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

    std::cout << O_BOLD << "============= Forms =============\n" << O_RESET;

    shrubberyCreation = intern.makeForm("ShrubberyCreationForm", "home");
    robotomyRequest = intern.makeForm("RobotomyRequestForm", "Jack");
    presidentialPardon = intern.makeForm("PresidentialPardonForm", "Jack");
    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

    std::cout << O_BOLD << "============= Sign form =============\n" << O_RESET;
    trump.signForm(*shrubberyCreation);
    trump.signForm(*robotomyRequest);
    trump.signForm(*presidentialPardon);
    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

    std::cout << O_BOLD << "============= Execute form =============\n"
              << O_RESET;
    trump.executeForm(*shrubberyCreation);
    trump.executeForm(*robotomyRequest);
    trump.executeForm(*presidentialPardon);
    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

    std::cout << O_BOLD << "============= Create wrong form =============\n"
              << O_RESET;
    wrongForm = intern.makeForm("worng name", "Jack");
    std::cout << O_BOLD << "========================================\n"
              << O_RESET;

  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  delete shrubberyCreation;
  delete robotomyRequest;
  delete presidentialPardon;
  delete wrongForm;
}
