#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include "transaction.hxx"

int main(int argc, char** argv) {
	std::cout << "Welcome to LedgeLite." << std::endl;
	Transaction transaction;
	std::cout << "Enter path to authentication database (e.g., users.db): ";
	std::string authDbPath;
	std::getline(std::cin, authDbPath);
	transaction.connectDatabase(authDbPath);

	while (true) {
		std::cout << "1. Login\n2. Signup\n3. Exit\nChoose: ";
		std::string choice;
		std::getline(std::cin, choice);

		switch (choice[0]) {
			case '1':
				if (transaction.login()) goto logged_in;
				break;
				//continue;
			case '2':
				if (transaction.signup()) goto logged_in;
				break;
				//continue;
			case '3':
				return 0;
			default:
				std::cout << "Invalid input.\n";
			}
	}
	logged_in:
	std::cout << "Enter path to ledger database (e.g., ledger.db): ";
	std::string ledgerdb;
	std::getline(std::cin, ledgerdb);
	transaction.connectDatabase(ledgerdb);

	while (true) {
		std::cout
			<< "Enter Choice\n"
			<< "1 - Show Previous Transactions\n"
			<< "2 - Add new entry\n"
			<< "3 - Remove an Entry\n"
			<< "4 - Edit an Entry\n"
			<< "5 - Search\n"
			<< "6 - Exit\n"
			<< std::flush;
		char choice;
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice) {
		case '1':
			transaction.showPrevious();
			break;
		case '2':
			transaction.addEntry();
			break;
		case '3':
			transaction.removeEntry();
			break;
		case '4':
			transaction.editEntry();
			break;
		case '5':
			transaction.search();
			break;
		case '6':
			std::cout << "Thanks for using LedgeLite." << std::endl;
			return 0;
		default:
			std::cout << "Invalid Choice!" << std::endl;
		}
	}

	return 0;
}






