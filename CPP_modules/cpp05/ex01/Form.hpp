#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
  public:
    Form(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute);
    ~Form();

    // getters
    std::string getName() const;
    int getRequiredGradeToSign() const;
    int getRequiredGradeToExecute() const;
    bool getIsSigned() const;

    // member functions
    void beSigned(const Bureaucrat &Bureaucrat);

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
    const std::string name_;           // A constant name
    const int requiredGradeToSign_;    // A constant grade required to sign it.
    const int requiredGradeToExecute_; // A constant grade required to execute it.
    bool isSigned_;                    // A boolean indicating whether it is signed (at construction, it’s not).

    Form(const Form &rhs);
    Form &operator=(const Form &rhs);
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif