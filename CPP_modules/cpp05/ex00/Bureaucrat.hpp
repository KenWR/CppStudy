#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

<<<<<<< HEAD
class Bureaucrat {
public:
  static const int kHighestGrade_ = 1;
  static const int kLowestGrade_ = 150;

  Bureaucrat(const std::string &name, const int grade);
  ~Bureaucrat();

  // getters
  const std::string &getName() const;
  const int getGrade() const;
=======
class Bureaucrat
{
  public:
    static const int kHighestGrade_ = 1;
    static const int kLowestGrade_ = 150;

    Bureaucrat(const std::string &name, const int grade);
    ~Bureaucrat();

    // getters
    const std::string &getName() const;
    int getGrade() const;
>>>>>>> 479d114753cba58f6ee434eb558808859178f5ae

    // setters
    void setGrade(const int grade);

    // member functions
    void incrementGrade();
    void decrementGrade();
    void validateGrade(int grade) const;

<<<<<<< HEAD
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
=======
    // exceptions
    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

  private:
    const std::string name_;
    int grade_; // 1 to 150, 1 is the highest grade, 150 is the lowest

    Bureaucrat(const Bureaucrat &rhs);
    Bureaucrat &operator=(const Bureaucrat &rhs);
>>>>>>> 479d114753cba58f6ee434eb558808859178f5ae
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif