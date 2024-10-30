#include "FtSed.hpp"
#include <fstream>
#include <string>
#include <iostream>

#define REPLACE ".replace"

int	main( int argc, char** argv ) {
	if (argc != 4) {
		std::cout << "NEED ONLY 3 ARGUMENTS" << std::endl;
		return (0);
	}
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	if (s1.empty()) {
		std::cout << "Empty string detected" << std::endl;
		return 1;
	}
	std::string s2(argv[3]);
	FtSed ft_sed( s1, s2 );

	std::ifstream 	inputFile(filename.c_str());
	std::ofstream 	outputFile((filename + REPLACE).c_str());
	if (!inputFile.is_open() || inputFile.fail()) {
		std::cout << "FAILED TO OPEN FILE!!" << std::endl;
		return (0);
	}
	while (inputFile.eof() == false) {
		std::string line;
		std::getline(inputFile, line);
		if (inputFile.eof() == false)
			line += '\n';
		ft_sed.srcToDest(line);
		outputFile << line ;
	}
}

