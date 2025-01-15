#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int requiredGradeToSign,
           const int requiredGradeToExecute)
    : name_(name),
      requiredGradeToSign_(requiredGradeToSign),
      requiredGradeToExecute_(requiredGradeToExecute),
      isSigned_(false) {
  if (requiredGradeToExecute < Bureaucrat::kHighestGrade_) {
    throw GradeTooHighException();
  } else if (requiredGradeToExecute > Bureaucrat::kLowestGrade_) {
    throw GradeTooLowException();
  }
}

Form::~Form() {}

std::string Form::getName() const { return name_; }
int Form::getRequiredGradeToSign() const { return requiredGradeToSign_; }
int Form::getRequiredGradeToExecute() const { return requiredGradeToExecute_; }
bool Form::getIsSigned() const { return isSigned_; }

void Form::beSigned(const Bureaucrat& Bureaucrat) {
  if (Bureaucrat.getGrade() <= requiredGradeToSign_) {
    isSigned_ = true;
  } else if (isSigned_) {
    std::cout << Bureaucrat.getName() << " couldn’t sign " << name_
              << " because the form is already signed" << std::endl;
  } else {
    throw GradeTooLowException();
  }
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high to get signed";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low to get signed";
}

std::ostream& operator<<(std::ostream& o, const Form& rhs) {
  o << "Form: " << rhs.getName()
    << ", Grade to sign: " << rhs.getRequiredGradeToSign()
    << ", Grade to execute: " << rhs.getRequiredGradeToExecute()
    << ", Signed: " << rhs.getIsSigned();
  return o;
}