#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm(const std::string &target);
  ~PresidentialPardonForm();

  const std::string &getTarget() const;

  void executeConcrete() const;

  // factory pattern
  AForm *create(const std::string &target) const;

private:
  std::string target_;

  PresidentialPardonForm(const PresidentialPardonForm &);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &);
};

#endif