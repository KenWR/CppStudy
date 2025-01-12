#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : name_(name), grade_(grade) {
	if (grade_ < kHighestGrade_) {
		throw GradeTooHighException();
	} else if (grade_ > kLowestGrade_) {
		throw GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::setName(const std::string& name) {
	name_ = name;
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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

