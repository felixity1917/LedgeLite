#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include "transaction.hxx"

void Transaction::addEntry() {
    std::string beneficiary, date, time, category, item;
    double amount;
    char choice;
    std::cout << "Input S for expense and R for earning: ";
    std::cin >> choice;
	std::cin.ignore();
    std::cout << std::endl;
    while(choice != 'S' && choice != 'R' && choice != 's' && choice != 'r') {
        std::cout << "Invalid input, enter S or R: ";
        std::cin >> choice;
		if (std::cin.eof()) {
			std::cout << "\nEnd of input detected. Exiting.\n";
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
    }
    std::cout << "Input the fields: " << std::endl;
    std::cout << "Beneficiary: ";
    std::getline(std::cin, beneficiary);
    std::cout << std::endl;
    std::cout << "Date: ";
    std::getline(std::cin, date);
    std::cout << std::endl;
    std::cout << "Time: ";
    std::getline(std::cin, time);
    std::cout << std::endl;
    std::cout << "Category: ";
    std::getline(std::cin, category);
    std::cout << std::endl;
    std::cout << "Item/(s): ";
    std::getline(std::cin, item);
    std::cout << std::endl;

    std::cout << "Beneficiary: " << beneficiary << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Time: " << time << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Item/(s): " << item << std::endl;
}

void Transaction::showPrevious() {
	std::cout << "Previous Transactions:" << std::endl;
	std::cout << std::endl;
	for (const auto& row : data) {
		for (const auto& elem : row) {
			std::cout << elem << " ";
		}
	std::cout << "\n";
	}
	std::cout << std::endl;
}

void Transaction::fetchData(const std::string& filePath) {
	std::cout << "Database Address: " << filePath << std::endl;
	/* Will use fstream to take the .csv file via a relative address and process it and store it into a 2d vector -> `Transaction::data` */
}
