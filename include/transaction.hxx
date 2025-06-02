#ifndef TRANSACTION_HXX
#define TRANSACTION_HXX

#include <string>
#include <vector>

class Transaction {
private:
	struct dataRow {
		std::string counterparty, amount, date, time, category, notes;
	};
	std::vector<dataRow> database;

public:
	void addEntry();
	void removeEntry();
	void editEntry();
	void showPrevious();
	void fetchData(const std::string& filePath);
	void writeData(const std::string& filePath);

private:
	void editField(int field, int serialNo);
};

#endif
