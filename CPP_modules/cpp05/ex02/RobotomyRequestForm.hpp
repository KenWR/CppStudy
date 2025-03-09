#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(const std::string &target);
  ~RobotomyRequestForm();

  const std::string &getTarget() const;

  void executeConcrete() const;

private:
  std::string target_;

  RobotomyRequestForm(const RobotomyRequestForm &);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &);
};

#endif