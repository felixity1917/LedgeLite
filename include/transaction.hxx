#ifndef TRANSACTION_HXX
#define TRANSACTION_HXX

#include <string>

class Transaction {
private:

public:
	void addEntry();
	void showPrevious();
	void fetchData(const std::string& filePath);
};

#endif
