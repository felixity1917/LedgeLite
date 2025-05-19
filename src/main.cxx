#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include "transaction.hxx"

int startAmount = 0;

int main(int argc, char **argv) {
	std::cout << "Welcome to LedgeLite." << std::endl;
	Transaction transaction;
	std::string filePath;
	std::cout << "Enter file address of database file: /path/to/database.csv" << std::endl;
	// getline(cin, filePath);
	filePath = "../testData/database.csv";
	transaction.fetchData(filePath);
	while (true) {
		std::cout << "Enter Choice" << std::endl;
		std::cout << "1 - Show Previous Transactions" << std::endl;
		std::cout << "2 - Add new entry" << std::endl;
		std::cout << "3 - Exit" << std::endl;
		char choice;
		std::cin >> choice;
		if (std::cin.eof()) {
			std::cout << "\nEnd of input detected. Exiting.\n";
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch(choice) {
			case '1': {
				transaction.showPrevious();
				break;
			}
			case '2': {
				transaction.addEntry();
				break;
			}
			case '3': {
				std::cout << "Thanks for using LedgeLite." << std::endl;
				return 0;
			}
			default: {
				std::cout << "Invalid Choice!" << std::endl;
			}
		}
	}
	return 0;
}
