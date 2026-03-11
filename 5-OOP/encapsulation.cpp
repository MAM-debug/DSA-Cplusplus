#include <iostream>
using namespace std;
#include <string>

// Encapsulation: wrapping data members and member functions together in a single unit called class
//helps in data hiding and abstraction
class Account {
    private:
    int password;
    double balance;

    public:
    string accountHolderName;
    string bankname;

    void setPassword(int pwd) {
        password = pwd;
    }
    bool verifyPassword(int pwd) {
        return pwd == password;
    }
    

}
