#ifndef TRANSACTION_HXX
#define TRANSACTION_HXX

#include <string>
#include <vector>

class Transaction {
private:
	std::vector<std::vector<std::string>> data;

public:
	void addEntry();
	void showPrevious();
	void fetchData(const std::string& filePath);

private:
	void getInput(std::string counterparty, double amount, std::string date, std::string time, std::string category, std::string notes);
};

#endif
