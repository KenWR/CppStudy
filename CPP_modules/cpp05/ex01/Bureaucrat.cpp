#include "Bureaucrat.hpp"

#include <iostream>

#include "Config.hpp"
#include "Form.hpp"

<<<<<<< HEAD
Bureaucrat::Bureaucrat(const std::string &name, const int grade)
    : name_(name), grade_(grade) {
  validateGrade(grade_);
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return name_; }

const int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::setGrade(const int grade) {
  validateGrade(grade);

  grade_ = grade;
=======
Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name_(name), grade_(grade)
{
    validateGrade(grade_);
    std::cout << O_YELLOW << "Created Bureaucrats successfully\n" << O_RESET;
}

Bureaucrat::~Bureaucrat()
{
>>>>>>> 479d114753cba58f6ee434eb558808859178f5ae
}

const std::string &Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}

void Bureaucrat::setGrade(const int grade)
{
    validateGrade(grade);

    grade_ = grade;
}

<<<<<<< HEAD
void Bureaucrat::signForm(class Form &form) {
  if (form.getIsSigned()) {
    std::cout << name_ << " couldn't sign " << form.getName()
              << " because the form is already signed" << std::endl;
  } else {
    std::cout << name_ << " signen " << form.getName() << std::endl;
    form.beSigned(*this);
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
=======
void Bureaucrat::incrementGrade()
{
    if (grade_ == kHighestGrade_)
    {
        throw GradeTooHighException();
    }

    grade_--;
}

void Bureaucrat::decrementGrade()
{
    if (grade_ == kLowestGrade_)
    {
        throw GradeTooLowException();
    }

    grade_++;
}

void Bureaucrat::validateGrade(int grade) const
{
    if (grade < kHighestGrade_)
    {
        throw GradeTooHighException();
    }
    else if (grade > kLowestGrade_)
    {
        throw GradeTooLowException();
    }
}

void Bureaucrat::signForm(const Form& form)
{
    if (form.getIsSigned())
    {
        std::cout << *this << " signed " << form;
    }
    else
    {
        std::cout << *this << " couldn’t sign " << form << " because the form is already signed\n";
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
>>>>>>> 479d114753cba58f6ee434eb558808859178f5ae
}
