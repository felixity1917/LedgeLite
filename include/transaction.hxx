#ifndef TRANSACTION_HXX
#define TRANSACTION_HXX

#include <string>
//#include <vector>
#include <sqlite3.h>
class Transaction {
private:
    sqlite3* db = nullptr;              
    std::string currentUser;            
    std::string currentTable;           

public:
    void connectDatabase(const std::string& filePath); 
    bool signup();                                     
    bool login();                                      
    bool isLoggedIn() const { return !currentUser.empty(); } 

    void addEntry();
    void removeEntry();
    void editEntry();
    void showPrevious();
    void search();
    void executeSQL(const std::string& sql);

private:
    void editField(int field, int serialNo);
};
#endif // !TRANSACTION_HXX
