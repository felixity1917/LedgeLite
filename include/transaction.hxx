#ifndef TRANSACTION_HXX
#define TRANSACTION_HXX

#include <string>
#include <vector>

class Transaction {
private:
	std::vector<std::vector<std::string>> data;

private:
	void getInput(std::string &beneficiary, std::string &date, std::string &time, std::string &category, std::string &item, double &amount, char &choice);
	void addRow(const std::string &filePath, const std::vector<std::string> &row);
public:
	void addEntry(const std::string& filePath);
	void showPrevious();
	void fetchData(const std::string& filePath);

};

#endif
