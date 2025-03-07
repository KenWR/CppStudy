#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  // getters & setters
  std::string const GetFirstName() const;
  std::string const GetLastName() const;
  std::string const GetNickName() const;
  std::string const GetPhoneNumber() const;
  std::string const GetDarkestSecret() const;
  void SetFirstName(std::string first_name);
  void SetLastName(std::string last_name);
  void SetNickName(std::string nickname);
  void SetPhoneNumber(std::string phone_number);
  void SetDarkestSecret(std::string darkest_secret);

  // Default constructor
  Contact();
  // Copy constructor
  Contact(const Contact &src);
  // Copy assignment operator
  Contact &operator=(const Contact &src);
  // DESTRUCTOR
  ~Contact();

private:
  // Private member variables here
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
  std::string darkest_secret_;
};

#endif