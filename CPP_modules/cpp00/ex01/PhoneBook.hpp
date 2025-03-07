#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

#define OTHERS 0
#define FIRST_NAME 1
#define LAST_NAME 2
#define NICKNAME 3
#define PHONE_NUMBER 4
#define DARKEST_SECRET 5
#define PHONE_BOOK_SIZE 8
#define HEADER_INFO_SIZE 4

class PhoneBook {
public:
  // add & search
  void Add();
  void Search();

  // Default constructor
  PhoneBook();
  // Copy constructor
  PhoneBook(const PhoneBook &src);
  // Copy assignment operator
  PhoneBook &operator=(const PhoneBook &src);
  // DESTRUCTOR
  ~PhoneBook();

  bool IsInputGood(std::string input, const int type);

private:
  // Private member variables here
  Contact phone_book_[PHONE_BOOK_SIZE];
  std::string header_info_[HEADER_INFO_SIZE];
  unsigned int phone_book_index_;

  // Private member functions here
  void PrintPhoneBook();
  void PrintLine();
  void PrintHeader();
  void PrintContact();
};

#endif