#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
public:
  static const int kHighestGrade_ = 1;
  static const int kLowestGrade_ = 150;

  Bureaucrat(const std::string &name, const int grade);
  ~Bureaucrat();

  // getters
  const std::string &getName() const;
  const int getGrade() const;

  // setters
  void setGrade(const int grade);

  // member functions
  void incrementGrade();
  void decrementGrade();
  void validateGrade(int grade) const;

  // exceptions
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  const std::string name_;
  int grade_; // 1 to 150, 1 is the highest grade, 150 is the lowest

  Bureaucrat(const Bureaucrat &rhs);
  Bureaucrat &operator=(const Bureaucrat &rhs);
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif