#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"
#include "Config.hpp"

Form::Form(const std::string name, const int requiredGradeToSign,
           const int requiredGradeToExecute)
    : name_(name), requiredGradeToSign_(requiredGradeToSign),
      requiredGradeToExecute_(requiredGradeToExecute), isSigned_(false) {
  if (requiredGradeToExecute < Bureaucrat::kHighestGrade_) {
    throw GradeTooHighException();
  } else if (requiredGradeToExecute > Bureaucrat::kLowestGrade_) {
    throw GradeTooLowException();
  }

  std::cout << O_YELLOW << "Created Form successfully\n" << O_RESET;
}

Form::~Form() {}

std::string Form::getName() const { return name_; }
int Form::getRequiredGradeToSign() const { return requiredGradeToSign_; }
int Form::getRequiredGradeToExecute() const { return requiredGradeToExecute_; }
bool Form::getIsSigned() const { return isSigned_; }

void Form::beSigned(const Bureaucrat &Bureaucrat) {
  if (Bureaucrat.getGrade() > requiredGradeToSign_) {
    throw GradeTooLowException();
  }

  isSigned_ = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high to get signed";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low to get signed";
}

std::ostream &operator<<(std::ostream &o, const Form &rhs) {
  o << "================================="
    << "Form: " << rhs.getName() << '\n'
    << "Grade to sign: " << rhs.getRequiredGradeToSign() << '\n'
    << "Grade to execute: " << rhs.getRequiredGradeToExecute() << '\n'
    << "Signed: " << rhs.getIsSigned();

  return o;
}