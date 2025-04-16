#include "BitcoinExchange.hpp"

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

std::string formatFloat(float value);
static bool isDateValid(const std::string &date);
static bool isFormatValid(const std::string &line,
                          const std::string &delimiter);
int getDemicalPlaceCount(const float num);

BitcoinExchange::BitcoinExchange(const std::string &filename) {
  setDatabase(filename);
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::setDatabase(const std::string &filename) {
  std::ifstream file(filename.c_str(), std::ios::in);
  if (file.is_open() == false) {
    std::cerr << "There is no database file.";
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    if (isFormatValid(line, ",") == false) {
      std::cerr << "Error: bad data.\n";
      continue;
    }

    std::istringstream iss(line);
    std::string date;
    float value;
    if (std::getline(iss, date, ',') && iss >> value) {
      if (iss.fail() == true || std::isinf(value) == true ||
          isDateValid(date) == false) {
        std::cerr << "Error: bad data.\n";
        continue;
      }
      database_[date] = value;
    }
  }
  file.close();
}

void BitcoinExchange::exchangeBitcoin(const std::string &filename) const {
  std::ifstream file(filename.c_str());
  if (file.fail() == true) {
    std::cerr << "Error: could not open file.\n";
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    if (isFormatValid(line, " | ") == false) {
      std::cerr << "Error: bad input => " << line << '\n';
      continue;
    }

    std::string date;
    float input_value;
    std::istringstream iss(line);

    std::getline(iss, date, ' ');
    iss.ignore(2);
    iss >> input_value;
    if (std::isinf(input_value) || input_value > 1000.0f) {
      std::cerr << "Error: too large a number.\n";
      continue;
    } else if (iss.fail() == false && input_value < 0.0f) {
      std::cerr << "Error: not a positive number.\n";
      continue;
    }

    float database_value = getValueByDateFromDB(date);
    float exchanged_value = input_value * database_value;
    if (std::isinf(exchanged_value) == true) {
      std::cerr << "Error: too large a number.\n";
      continue;
    }
    std::cout << date << " => " << formatFloat(input_value) << " = "
              << formatFloat(exchanged_value) << '\n';
  }
}

float BitcoinExchange::getValueByDateFromDB(const std::string &date) const {
  std::map<std::string, float>::const_iterator const_it =
      database_.upper_bound(date);

  return (--const_it)->second;
}

std::string formatFloat(float value) {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << value;
  std::string s = oss.str();

  size_t dotPos = s.find('.');
  if (dotPos != std::string::npos) {
    while (s.size() > 0 && s[s.size() - 1] == '0') {
      s.erase(s.size() - 1, 1);
    }
    if (s.size() > 0 && s[s.size() - 1] == '.') {
      s.erase(s.size() - 1, 1);
    }
  }
  return s;
}

static bool isFormatValid(const std::string &line,
                          const std::string &delimiter) {
  size_t pos = line.find(delimiter);
  if (pos == std::string::npos) {
    return false;
  }
  std::string value_str = line.substr(pos + delimiter.size());
  if (value_str.empty()) {
    return false;
  }
  return true;
}

static bool isDateValid(const std::string &date) {
  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  int year, month, day;
  char dash1, dash2;
  std::istringstream iss(date);
  if (!(iss >> year >> dash1 >> month >> dash2 >> day)) {
    return false;
  }
  if (dash1 != '-' || dash2 != '-') {
    return false;
  }
  if (month < 1 || month > 12) {
    return false;
  }

  int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    mdays[2] = 29;

  if (day < 1 || day > mdays[month]) {
    return false;
  }

  return true;
}