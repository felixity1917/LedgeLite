#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int startAmount = 0;

int main(int argc, char **argv[]) {
	cout << "Welcome to LedgeLite." << endl;
	bool termFlag = false;
	while (!termFlag) {
		cout << "Enter Choice" << endl;
		cout << "1 - Show Previous Transactions" << endl;
		cout << "2 - Add new entry" << endl;
		cout << "3 - Exit" << endl;
		int choice;
		cin >> choice;
		switch(choice) {
			case 1: {
				Transaction::showPrevious();
				break;
			}
			case 2: {
				Transaction::addEntry();
				break;
			}
			case 3: {
				cout << "Thanks for using LedgeLite." << endl;
				return 0;
			}
			default: {
				cout << "Invalid Choice!" << endl;
			}
		}
	}
	return 0;
}
