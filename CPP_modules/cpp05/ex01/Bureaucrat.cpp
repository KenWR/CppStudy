#include "Bureaucrat.hpp"

#include <iostream>

#include "Config.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, const int grade)
    : name_(name), grade_(grade) {
  validateGrade(grade_);
  std::cout << O_YELLOW << "Created " << *this << " successfully\n" << O_RESET;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::setGrade(const int grade) {
  validateGrade(grade);

  grade_ = grade;
}

void Bureaucrat::incrementGrade() {
  if (grade_ == kHighestGrade_) {
    throw GradeTooHighException();
  }

  grade_--;
}

void Bureaucrat::decrementGrade() {
  if (grade_ == kLowestGrade_) {
    throw GradeTooLowException();
  }

  grade_++;
}

void Bureaucrat::validateGrade(int grade) const {
  if (grade < kHighestGrade_) {
    throw GradeTooHighException();
  } else if (grade > kLowestGrade_) {
    throw GradeTooLowException();
  }
}

void Bureaucrat::signForm(Form &form) {
  if (form.getIsSigned()) {
    std::cout << *this << " couldn’t sign " << form
              << " because the form is already signed\n";
    return;
  }

  try {
    form.beSigned(*this);
    std::cout << *this << " signed\n" << form << '\n';
  } catch (const GradeTooHighException &e) {
    std::cout << *this << " couldn't sign\n"
              << form << " because " << e.what() << '\n';
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs) {
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
  return o;
}
