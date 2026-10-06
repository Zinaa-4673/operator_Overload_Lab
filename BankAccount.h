#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
private:
    char*_accountHolder;
    double _balance;
    int _accountNumber;


public:
    BankAccount();
    BankAccount(const char* accountHolder, double balance, int accountNumber);
    ~BankAccount();

    BankAccount(const BankAccount& other);

    BankAccount& operator=(const BankAccount& other);

    const char* getAccountHolder() const;
    double getBalance() const;
    int getAccountNumber() const;
     
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    static void  printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
};

#endif // BankAccount_H