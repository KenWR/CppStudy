#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

int main(void) {
  std::string command;
  PhoneBook phone_book;

  while (true) {
    std::cout << std::endl
              << "ENTER COMMAND: ADD, SEARCH, EXIT" << std::endl
              << std::endl;
    std::getline(std::cin, command);
    while (phone_book.IsInputGood(command, OTHERS) == false) {
      std::cout << "ENTER COMMAND[ ADD, SEARCH, EXIT ]: ";
      std::getline(std::cin, command);
    }
    if (command == "EXIT") {
      std::cout << std::endl << "EXITING PROGRAM" << std::endl << std::endl;
      break;
    } else if (command == "ADD") {
      phone_book.Add();
    } else if (command == "SEARCH") {
      phone_book.Search();
    } else {
      std::cout << std::endl << "INVALID COMMAND" << std::endl << std::endl;
    }
  }
}
