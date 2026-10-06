 #include "BankAccount.h"
 #include <iostream>


 BankAccount::BankAccount() : _accountHolder(nullptr), _balance(0.0), _accountNumber(0) {}
 BankAccount::BankAccount(const char* accountHolder, double Balance, int accountNumber)
    : _accountHolder(nullptr),_balance(Balance), _accountNumber(accountNumber){

    if (accountHolder != nullptr) {
        int length = 0;
        while (accountHolder[length] != '\0') {
            length++;
        }
        
        _accountHolder = new char[length + 1];
        for (int i = 0; i < length; i++) {
            _accountHolder[i] = accountHolder[i];
        }
        _accountHolder[length] = '\0';
    } else {
         _accountHolder = nullptr;
    }  

 } 
 BankAccount::~BankAccount() {

    delete[] _accountHolder;
 }

 BankAccount::BankAccount(const BankAccount& other) 
   : _accountHolder(nullptr), _balance(other._balance), _accountNumber(other._accountNumber) {
     
    if (other._accountHolder != nullptr) {
        int length = 0;
        while (other._accountHolder[length] != '\0') {
            length++;
        }
        _accountHolder = new char[length + 1];
        for (int i = 0; i < length; i++) {
            _accountHolder[i] = other._accountHolder[i];
        }
        _accountHolder[length] = '\0';
    }else {
        _accountHolder = nullptr;
    }

}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if ( this == &other) {
        return *this;
    }
    delete[] _accountHolder;
    _balance = other._balance;
    _accountNumber = other._accountNumber;

    if(other._accountHolder != nullptr) {
        int length = 0;
        while (other._accountHolder[length] != '\0') {
            length++;
        }
        _accountHolder = new char[length + 1];
        for (int i = 0; i < length; i++) {
            _accountHolder[i] = other._accountHolder[i];
        }
        _accountHolder[length] = '\0';
    } else {
        _accountHolder = nullptr;
    }
    return *this;
}
int BankAccount::getAccountNumber() const {
    return _accountNumber;
}

const char* BankAccount::getAccountHolder() const {
    return _accountHolder  != nullptr ? _accountHolder :"";
}
double BankAccount::getBalance() const {
    return _balance;
}
BankAccount& BankAccount::operator+=(double amount) {
    if(amount > 0) {
        _balance += amount;
    } else {
        std::cout << " ERROR: Deposit must be positive"<< std::endl;
    }
    return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
    if (amount <= 0) {
        std::cout << "ERROR: withdrawal must be positive"<< std::endl;
    }else if (amount > _balance) {
        std::cout << " ERROR: insufficient funds.\n";
    }else {
            _balance -= amount;
    }
    return *this;
}
bool BankAccount::operator==(const BankAccount& other) const {
    return this->_accountNumber == other._accountNumber;    
}
bool BankAccount::operator<(const BankAccount& other) const {
    return this->_balance < other._balance;
}
bool BankAccount::operator>(const BankAccount& other) const {
    return this->_balance > other._balance;
}

void BankAccount::printAccount(const BankAccount& account) {
    std::cout << "\nAccount Number: " << account.getAccountNumber() << std::endl;
    std::cout << "Account Holder: " << account.getAccountHolder() << std::endl;
    std::cout << "Balance: $" << account.getBalance() << std::endl;
}
BankAccount BankAccount::createAccountFromInput() {
    int accountNumber;
    char accountHolder[256];
    double balance;

    std::cout << " Enter account number:";
    std::cin >> accountNumber;

    std::cout << " Enter account holder name: ";
    std::cin.ignore();
    std::cin.getline(accountHolder, 256);

    std::cout << " Enter initial balance: ";
    std::cin >> balance;

    return BankAccount(accountHolder, balance, accountNumber);
}