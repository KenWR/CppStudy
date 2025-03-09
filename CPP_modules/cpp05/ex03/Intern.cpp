#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <string>

static const std::map<std::string, AForm> formMap_ = {
    {"ShrubberyCreation", ShrubberyCreationForm("target")},
    {"RobotomyRequest", RobotomyRequestForm("target")},
    {"PresidentialPardon", PresidentialPardonForm("target")},
};

Intern::Intern() {}

Intern::~Intern() {}

/**
 * @brief Create a form
 * @todo Need to implement Prototype pattern
 */
AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {
  if (formMap_.find(formName) != formMap_.end()) {
    return new formMap_[formName];
  } else {
    throw FormNotFoundException();
  }
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found";
}