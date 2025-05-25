#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include "transaction.hxx"

void Transaction::getInput(std::string &counterparty, std::string &date, std::string &time, std::string &category, std::string &item, double &amount, char &choice){
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
    std::cout << "counterparty: ";
    std::getline(std::cin, counterparty);
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
    std::cout << "Amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    std::cout << "Counterparty: " << counterparty << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Time: " << time << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Item/(s): " << item << std::endl;
    std::cout << "Amount: Rs." << amount << std::endl;
}
  

void Transaction::addEntry() {
    std::string counterparty, date, time, category, item;
    double amount;
    char choice;
    getInput(counterparty, date, time, category, item, amount,choice);
    /*test sample*/
}

void Transaction::showPrevious() {
	std::cout << "Previous Transactions:" << std::endl;
	std::cout << std::endl;
	for (const auto& row : data) {
		for (const auto& cell : row) {
			std::cout << cell << " ";
		}
	std::cout << "\n";
	}
	std::cout << std::endl;
}

void Transaction::fetchData(const std::string& filePath) {
	std::cout << "Database Address: " << filePath << std::endl;
	std::cout << "Processing data..." << std::endl;
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Error: File could not be opened." << std::endl;
		/* Extend this further to include further user operation in case of file error. */
	}
	std::string line;
	while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;
        int columnCount = 0;

        while (std::getline(ss, cell, ',')) {
			std::cout << cell << " " << std::endl;
            row.push_back(cell);
            columnCount++;
        }

        if (columnCount != 6) {
            std::cerr << "Warning: Skipping malformed line (expected 6 columns): " << line << std::endl;
            continue;
        }

        data.push_back(row);
		std::cout << "\n";
    }

    file.close();
}
