#ifndef SHUBBERYCREATIONFORM_HPP
#define SHUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm();

  const std::string &getTarget() const;

  void executeConcrete() const;

private:
  const std::string target_;

  ShrubberyCreationForm(const ShrubberyCreationForm &);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
};

#endif