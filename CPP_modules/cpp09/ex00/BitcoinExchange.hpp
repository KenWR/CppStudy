#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, float> database_;

  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);

  void setDatabase(const std::string &filename);
  float getValueByDateFromDB(const std::string &date) const;

public:
  BitcoinExchange(const std::string &filename);
  ~BitcoinExchange();

  void exchangeBitcoin(const std::string &filename) const;
};

#endif // BITCOINEXCHANGE_HPP