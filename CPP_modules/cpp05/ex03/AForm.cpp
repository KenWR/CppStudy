#include "AForm.hpp"

#include <iostream>
#include <typeinfo>

#include "Bureaucrat.hpp"
#include "Config.hpp"

AForm::AForm(const std::string name, const int requiredGradeToSign,
             const int requiredGradeToExecute)
    : name_(name), requiredGradeToSign_(requiredGradeToSign),
      requiredGradeToExecute_(requiredGradeToExecute), isSigned_(false) {
  if (requiredGradeToExecute < Bureaucrat::kHighestGrade_) {
    throw GradeTooHighException();
  } else if (requiredGradeToExecute > Bureaucrat::kLowestGrade_) {
    throw GradeTooLowException();
  }
}

AForm::~AForm() {}

std::string AForm::getName() const { return name_; }
int AForm::getRequiredGradeToSign() const { return requiredGradeToSign_; }
int AForm::getRequiredGradeToExecute() const { return requiredGradeToExecute_; }
bool AForm::getIsSigned() const { return isSigned_; }

void AForm::beSigned(const Bureaucrat &Bureaucrat) {
  if (Bureaucrat.getGrade() > requiredGradeToSign_) {
    throw GradeTooLowException();
  }

  isSigned_ = true;
}

void AForm::execute(const Bureaucrat &executor) const {
  if (isSigned_ == false) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > requiredGradeToExecute_) {
    throw GradeTooLowException();
  }

  executeConcrete();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Too high to sign/execute this Aform";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Too low to sign/execute this Aform";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs) {
  o << "-------------------------------------------\n"
    << "|Form:             |" << rhs.getName() << '\n'
    << "|Grade to sign:    |" << rhs.getRequiredGradeToSign() << '\n'
    << "|Grade to execute: |" << rhs.getRequiredGradeToExecute() << '\n'
    << "|Signed:           |" << (rhs.getIsSigned() ? "Yes" : "No") << '\n'
    << "-------------------------------------------\n";

  return o;
}