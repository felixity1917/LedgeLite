#ifndef TRANSACTION_HXX
#define TRANSACTION_HXX

#include <string>
#include <vector>

class Transaction {
private:
	struct dataRow {
		std::string counterparty, date, time, category, notes;
		double amount;
	};
	std::vector<dataRow> database;

public:
	void addEntry();
	void removeEntry();
	void editEntry();
	void showPrevious();
	void fetchData(const std::string& filePath);

private:
	void getInput(std::string counterparty, double amount, std::string date, std::string time, std::string category, std::string notes);
	void addToSource(std::string counterparty, double amount, std::string date, std::string time, std::string category, std::string notes);
};

#endif
