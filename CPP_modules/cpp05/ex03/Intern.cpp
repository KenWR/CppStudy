#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <string>

std::map<std::string, AForm *> Intern::formMap_;

Intern::Intern() {
  if (formMap_.empty() == true) {
    formMap_["PresidentialPardonForm"] = new PresidentialPardonForm("target");
    formMap_["RobotomyRequestForm"] = new RobotomyRequestForm("target");
    formMap_["ShrubberyCreationForm"] = new ShrubberyCreationForm("target");
  }
}

Intern::~Intern() {
  if (formMap_.empty() == false) {
    delete formMap_["PresidentialPardonForm"];
    delete formMap_["RobotomyRequestForm"];
    delete formMap_["ShrubberyCreationForm"];
  }
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {
  if (formMap_.find(formName) != formMap_.end()) {
    AForm *newForm = formMap_[formName]->create(target);
    std::cout << "Intern creates\n" << newForm << '\n';
    return newForm;
  } else {
    throw FormNotFoundException();
  }
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found";
}