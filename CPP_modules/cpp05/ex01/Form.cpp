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

  std::cout << O_YELLOW << "Created Form successfully\n " << *this << O_RESET;
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
  return "Too high to sign/execute this form";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Too low to sign/execute this form";
}

std::ostream &operator<<(std::ostream &o, const Form &rhs) {
  o << "-------------------------------------------\n"
    << "|Form:             |" << rhs.getName() << '\n'
    << "|Grade to sign:    |" << rhs.getRequiredGradeToSign() << '\n'
    << "|Grade to execute: |" << rhs.getRequiredGradeToExecute() << '\n'
    << "|Signed:           |" << (rhs.getIsSigned() ? "Yes" : "No") << '\n'
    << "-------------------------------------------\n";

  return o;
}