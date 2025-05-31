#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "transaction.hxx"


void Transaction::addEntry() {
	std::string counterparty{""}, date{""}, time{""}, category{""}, notes{""},amount{""};
	char choice{'\0'};
	std::cout << "Payment or Reception? [S/R]: " << std::flush;
	std::cin >> choice;
	std::cin.ignore();
	std::cout << "\n";

	while (choice != 'S' && choice != 'R' && choice != 's' && choice != 'r') {
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
	std::getline(std::cin, amount);
	std::cout << "Date of Transaction: " << std::flush;
	std::getline(std::cin, date);
	std::cout << "Time of Transaction: " << std::flush;
	std::getline(std::cin, time);
	std::cout << "Transaction Category: " << std::flush;
	std::getline(std::cin, category);
	std::cout << "Additional Notes: " << std::flush;
	std::getline(std::cin, notes);
	std::cout << "\n";

	std::cout
		<< "Entry has been added..."
		<< "\nSummary:"
		<< "\nName of Counterparty: " << counterparty
		<< "\nTransacted Amount: " << amount
		<< "\nDate of Transaction: " << date
		<< "\nTime of Transaction: " << time
		<< "\nTransaction Category: " << category
		<< "\nAdditional Notes: " << notes
		<< "\n" << std::endl;

	Transaction::dataRow tempData = {counterparty, date, time, category, notes, amount};
	database.push_back(tempData);
}

void Transaction::removeEntry() {
	int serialNo{0};
	std::cout << "Enter the serial number of the transaction you would like to remove: " << std::flush;
	std::cin >> serialNo;

	while (serialNo > (int)database.size() || serialNo < 1){
		std::cout << "Enter a valid serial number: " << std::flush;
		std::cin >> serialNo;
	}

	database.erase(database.begin() + (serialNo - 1));
	std::cout<<"Data at serial no. " << serialNo << " has been erased successfully.\n" << std::endl;

	Transaction::showPrevious();
}

void Transaction::editField(int field, int serialNo){
	std::string newData{""};
	std::cout<<"Enter the new data: "<<std::flush;
	std::getline(std::cin,newData);
	switch (field){
		case 0:
			database[serialNo-1].counterparty = newData;
			break;
		case 1:
			database[serialNo-1].date = newData;
			break;
		case 2:
			database[serialNo-1].time = newData;
			break;
		case 3:
			database[serialNo-1].category = newData;
			break;
		case 4:
			database[serialNo-1].notes = newData;
			break;
		case 5:
			database[serialNo-1].amount = newData;
			break;
		default:
			std::cout<<"Invalid choice\n";
	}
}

void Transaction::editEntry() {
	std::string serialNo{""};
	std::cout<<"Enter the serial no. of the entry you would like to edit: "<<std::flush;
	std::getline(std::cin,serialNo);

	while (std::stoi(serialNo)>(int)database.size() || std::stoi(serialNo)<1 || !std::all_of(serialNo.begin(), serialNo.end(), ::isdigit) ){
		std::cout<<"Enter a valid serial number: "<<std::flush;
		std::cin>>serialNo;
	}

	std::string field;
	std::cout<<"Enter the name of field you want to edit (counterparty, date, time, category, notes, amount): "<<std::flush;
	std::getline(std::cin,field);

	std::transform(field.begin(), field.end(), field.begin(), ::tolower);
	int temp = std::stoi(serialNo);
	if(field==std::string("counterparty")) editField(0,temp);
	else if(field==std::string("date")) editField(1,temp);
	else if(field==std::string("time")) editField(2,temp);
	else if(field==std::string("category")) editField(3,temp);
	else if(field==std::string("notes")) editField(4,temp);
	else if(field==std::string("amount")) editField(5,temp);
	else std::cout<<"Invalid choice\n";

}

void Transaction::showPrevious() {
	std::cout
		<< "Previous Transactions:\n"
		<< "S. No. | Payer/Payee | Amount | Date | Time | Category | Notes\n";
	int i{1};
	for (const auto& row : database) {
		std::cout
			<< i++ << ". | "
			<< row.counterparty << " | "
			<< row.amount << " | "
			<< row.date << " | "
			<< row.time << " | "
			<< row.category << " | "
			<< row.notes << '\n';
	}
	std::cout << "\n";
}

void Transaction::fetchData(const std::string& filePath) {
	std::cout << "Database Address: " << filePath << std::endl;
	std::cout << "Processing data..." << std::endl;
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Error: File could not be opened." << std::endl;
		/* Extend this further to include further user operation in case of file error. */
	}
	std::string line{""};
	while (std::getline(file, line)) {
		Transaction::dataRow row;
		std::stringstream ss(line);
		std::string amountStr{""};

		if (!std::getline(ss, row.counterparty, ',')) continue;
		if (!std::getline(ss, amountStr, ',')) continue;
		try {
			row.amount = std::stod(amountStr);
		} catch (...) {
			// If amount conversion fails, skip this row
			continue;
		}
		if (!std::getline(ss, row.date, ',')) continue;
		if (!std::getline(ss, row.time, ',')) continue;
		if (!std::getline(ss, row.category, ',')) continue;
		if (!std::getline(ss, row.notes, ',')) continue;
		/* Implement actionable measures for corrupt databases */

		database.push_back(row);
	}
	std::cout << "\n";

	Transaction::showPrevious();

	file.close();
}
