#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include "transaction.hxx"

void Transaction::getInput() {
	std::string counterparty, date, time, category, notes;
	double amount;
	char choice;

    std::cout << "Payment or Reception? [S/R]: " << std::flush;
    std::cin >> choice;
    std::cin.ignore();
    std::cout << "\n";

    while(choice != 'S' && choice != 'R' && choice != 's' && choice != 'r') {
        std::cerr << "Invalid input, please enter either S or R: ";
        std::cin >> choice;
        if (std::cin.eof()) {
            std::cerr << "\nEnd of input detected. Exiting.\n";
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n";
    }

    std::cout << "Please input the following fields..." << std::endl;
	std::cout << "Name of Counterparty: " << std::flush;
    std::getline(std::cin, counterparty);
    std::cout << "Transacted Amount: " << std::flush;
    std::cin >> amount;
	std::cin.ignore();
    std::cout << "Date of Transaction: " << std::flush;
    std::getline(std::cin, date);
    std::cout << "Time of Transaction: " << std::flush;
    std::getline(std::cin, time);
    std::cout << "Transaction Category: " << std::flush;
    std::getline(std::cin, category);
    std::cout << "Additional Notes: " << std::flush;
    std::getline(std::cin, notes);
	std::cout << "\n";

	std::cout << "Please Verify the following details: \n";
    std::cout << "Name of Counterparty: " << counterparty << "\n";
    std::cout << "Transacted Amount: " << amount << "\n";
    std::cout << "Date of Transaction: " << date << "\n";
    std::cout << "Time of Transaction: " << time << "\n";
    std::cout << "Transaction Category: " << category << "\n";
    std::cout << "Additional Notes: " << notes << "\n";
	std::cout << "\n";
}
  

void Transaction::addEntry() {
	Transaction::getInput();
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
