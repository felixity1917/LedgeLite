#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "../include/transaction.hxx"

int startAmount = 0;

int main(int argc, char **argv) {
	std::cout << "Welcome to LedgeLite." << std::endl;
	Transaction transaction;
	/*string filePath;
	cout << "Enter file address of database file: /path/to/database.csv" << endl;
	// getline(cin, filePath);
	filePath = "../testData/database.csv";
	transaction.fetchData(filePath);*/
	bool termFlag = false;
	while (!termFlag) {
		std::cout << "Enter Choice" << std::endl;
		std::cout << "1 - Show Previous Transactions" << std::endl;
		std::cout << "2 - Add new entry" << std::endl;
		std::cout << "3 - Exit" << std::endl;
		int choice;
		std::cin >> choice;
		switch(choice) {
			case 1: {
				/*transaction.showPrevious();*/
				break;
			}
			case 2: {
				transaction.addEntry();
				break;
			}
			case 3: {
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
