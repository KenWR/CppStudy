#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <limits>
#include "PhoneBook.hpp"

void	PhoneBook::Add() {
	Contact 	contact;
	std::string input;

	// Set first name
	std::cout << "ENTER FIRST NAME: ";
	std::getline(std::cin, input);
	while (IsInputGood(input, FIRST_NAME) == false) {
		std::cout << "ENTER FIRST NAME AGAIN: ";
		std::getline(std::cin, input);
	}
	contact.SetFirstName(input);

	// Set last name
	std::cout << "ENTER LAST NAME: ";
	std::getline(std::cin, input);
	while (IsInputGood(input, LAST_NAME) == false) {
		std::cout << "ENTER LAST NAME AGAIN: ";
		std::getline(std::cin, input);
	}
	contact.SetLastName(input);

	// Set nickname
	std::cout << "ENTER NICKNAME: ";
	std::getline(std::cin, input);
	while (IsInputGood(input, NICKNAME) == false) {
		std::cout << "ENTER NICKNAME AGAIN: ";
		std::getline(std::cin, input);
	}
	contact.SetNickName(input);

	// Set phone number
	std::cout << "ENTER PHONE NUMBER: ";
	std::getline(std::cin, input);
	while (IsInputGood(input, PHONE_NUMBER) == false) {
		std::cout << "ENTER PHONE NUMBER AGAIN: ";
		std::getline(std::cin, input);
	}
	contact.SetPhoneNumber(input);

	// Set darkest secret
	std::cout << "ENTER DARKEST SECRET: ";
	std::getline(std::cin, input);
	while (IsInputGood(input, DARKEST_SECRET) == false) {
		std::cout << "ENTER DARKEST SECRET AGAIN: ";
		std::getline(std::cin, input);
	}
	contact.SetDarkestSecret(input);

	this->phone_book_[this->phone_book_index_ % PHONE_BOOK_SIZE] = contact;
	this->phone_book_index_++;
}

bool	PhoneBook::IsInputGood(std::string input, const int type) {
	if (std::cin.eof()) {
		std::cout << "EOF DETECTED" << std::endl;
		std::clearerr(stdin);
		std::cin.clear();
		return false;
	} else if (std::cin.fail()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		std::cout << "FAIL DETECTED" << std::endl;
		return false;
	} else if (input.length() == 0) {
		std::cout << "EMPTY INPUT DETECTED" << std::endl;
		return false;
	}

	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == '\t') {
			std::cout << "NO TAB" << std::endl;
			return false;
		}
	}

	if (type == PHONE_NUMBER) {
		for (size_t i = 0; i < input.length(); i++) {
			if (input[i] < '0' || input[i] > '9') {
				std::cout << "YOU MUST TYPE NUMBER" << std::endl;
				return false;
			}
		}
	}
	return true;
}

void	PhoneBook::Search() {
	PrintPhoneBook();
	PrintContact();
}

void	PhoneBook::PrintPhoneBook() {
	PrintLine();
	PrintHeader();
	PrintLine();
	for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
		std::cout << "|";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << i;
		std::cout << "|";
		if (this->phone_book_[i].GetFirstName().length() > 10) {
			std::cout << this->phone_book_[i].GetFirstName().substr(0, 9) << ".|";
		} else {
			std::cout << std::setw(10) << std::setfill(' ') << std::right << this->phone_book_[i].GetFirstName();
			std::cout << "|";
		}
		if (this->phone_book_[i].GetLastName().length() > 10) {
			std::cout << this->phone_book_[i].GetLastName().substr(0, 9) << ".|";
		} else {
			std::cout << std::setw(10) << std::setfill(' ') << std::right << this->phone_book_[i].GetLastName();
			std::cout << "|";
		}
		if (this->phone_book_[i].GetNickName().length() > 10) {
			std::cout << this->phone_book_[i].GetNickName().substr(0, 9) << ".|";
		} else {
			std::cout << std::setw(10) << std::setfill(' ') << std::right << this->phone_book_[i].GetNickName();
			std::cout << "|";
		}
		std::cout << std::endl;
		PrintLine();
	}
}

void	PhoneBook::PrintLine() {
	std::cout << std::setw(45) << std::setfill('-') << "" << std::endl;
}

void	PhoneBook::PrintHeader() {
	std::cout << "|";
	std::cout << std::setfill(' ');
	for (int i = 0; i < HEADER_INFO_SIZE; i++) {
		std::cout << std::setw(10) << std::right << this->header_info_[i];
		std::cout << "|";
	}
	std::cout << std::endl;
}

void	PhoneBook::PrintContact() {
	std::string input;

	std::cout << std::endl << "ENTER INDEX: ";
	std::getline(std::cin, input);
	while (IsInputGood(input, OTHERS) == false) {
		std::cout << std::endl << "ENTER INDEX AGAIN: ";
		std::getline(std::cin, input);
	}
	int index = input[0] - '0';
	if (0 <= index && index <= PHONE_BOOK_SIZE - 1) {
		std::cout << "First name: " << this->phone_book_[index].GetFirstName() << std::endl;
		std::cout << "Last name: " << this->phone_book_[index].GetLastName() << std::endl;
		std::cout << "Nickname: " << this->phone_book_[index].GetNickName() << std::endl;
		std::cout << "Phone number: " << this->phone_book_[index].GetPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << this->phone_book_[index].GetDarkestSecret() << std::endl;
	}
	else {
		std::cout << "INVALID INDEX" << std::endl;
	}
}

PhoneBook::PhoneBook() {
	phone_book_index_ = 0;
	header_info_[0] = "index";
	header_info_[1] = "first name";
	header_info_[2] = "last name";
	header_info_[3] = "nickname";
}

PhoneBook::PhoneBook(const PhoneBook& src) {
	phone_book_index_ = src.phone_book_index_;
	header_info_[0] = src.header_info_[0];
	header_info_[1] = src.header_info_[1];
	header_info_[2] = src.header_info_[2];
	header_info_[3] = src.header_info_[3];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& src) {
	phone_book_index_ = src.phone_book_index_;
	header_info_[0] = src.header_info_[0];
	header_info_[1] = src.header_info_[1];
	header_info_[2] = src.header_info_[2];
	header_info_[3] = src.header_info_[3];
	return *this;
}

PhoneBook::~PhoneBook() {

}
