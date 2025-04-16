#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Error: no input file.\n";
    return 1;
  }
  BitcoinExchange exchange("data.csv");
  exchange.exchangeBitcoin(argv[1]);
  return 0;
}
