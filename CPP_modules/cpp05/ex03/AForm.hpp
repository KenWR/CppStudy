#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string name_;           // A constant name
  const int requiredGradeToSign_;    // A constant grade required to sign it.
  const int requiredGradeToExecute_; // A constant grade required to execute it.
  bool isSigned_; // A boolean indicating whether it is signed (at construction,
                  // it’s not).

  AForm(const AForm &rhs);
  AForm &operator=(const AForm &rhs);

protected:
  virtual void executeConcrete() const = 0;

public:
  AForm(const std::string name, const int requiredGradeToSign,
        const int requiredGradeToExecute);
  ~AForm();

  // getters
  std::string getName() const;
  int getRequiredGradeToSign() const;
  int getRequiredGradeToExecute() const;
  bool getIsSigned() const;

  // member functions
  void beSigned(const Bureaucrat &Bureaucrat);
  void execute(const Bureaucrat &executor) const;

  // factory pattern
  virtual AForm *create(const std::string &target) const = 0;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif