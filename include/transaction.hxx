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
};

#endif
