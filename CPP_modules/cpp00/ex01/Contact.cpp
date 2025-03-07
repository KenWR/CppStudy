#include "Contact.hpp"

std::string const Contact::GetFirstName() const { return this->first_name_; }

std::string const Contact::GetLastName() const { return this->last_name_; }

std::string const Contact::GetNickName() const { return this->nickname_; }

std::string const Contact::GetDarkestSecret() const {
  return this->darkest_secret_;
}

std::string const Contact::GetPhoneNumber() const {
  return this->phone_number_;
}

void Contact::SetFirstName(std::string first_name) {
  this->first_name_ = first_name;
}

void Contact::SetLastName(std::string last_name) {
  this->last_name_ = last_name;
}

void Contact::SetNickName(std::string nickname) { this->nickname_ = nickname; }

void Contact::SetPhoneNumber(std::string phone_number) {
  this->phone_number_ = phone_number;
}

void Contact::SetDarkestSecret(std::string darkest_secret) {
  this->darkest_secret_ = darkest_secret;
}

Contact::Contact() {
  first_name_ = "";
  last_name_ = "";
  nickname_ = "";
  phone_number_ = "";
  darkest_secret_ = "";
}

Contact::Contact(const Contact &src) {
  first_name_ = src.first_name_;
  last_name_ = src.last_name_;
  nickname_ = src.nickname_;
  phone_number_ = src.phone_number_;
  darkest_secret_ = src.darkest_secret_;
}

Contact &Contact::operator=(const Contact &src) {
  first_name_ = src.first_name_;
  last_name_ = src.last_name_;
  nickname_ = src.nickname_;
  phone_number_ = src.phone_number_;
  darkest_secret_ = src.darkest_secret_;
  return *this;
}

Contact::~Contact() {}
