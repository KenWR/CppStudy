#ifndef INTERN_HPP
#define INTERN_HPP

#include <map>
#include <string>

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern {
private:
  static const std::map<std::string, AForm > formMap_;
  
  Intern(const Intern &);
  Intern &operator=(const Intern &);

public:
  Intern();
  ~Intern();

  AForm *makeForm(const std::string &formName, const std::string &target);

  class FormNotFoundException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

#endif