#include "BankAccount.h"
#include <iostream>

int main() {
    BankAccount account1;
    BankAccount account2;
    bool hasaccount1 = false;
    bool hasaccount2 = false;

    int choice = -1;
    while (choice != 0) {
        std::cout << "\nBank Account Management system\n'";
        std::cout << "1. create Primary account\n";
        std::cout << "2. create secondary account\n";
        std::cout << "3. deposit tp primary account\n";
        std::cout << "4. withdraw from primary account\n";
        std::cout << "5. print primary account details\n";
        std::cout << "6. compare balance\n";
        std::cout << "7. check equality\n";
        std::cout << "8. exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
              std::cout << "\nCreating primary Account:\n";
              account1 = BankAccount::createAccountFromInput();
              hasaccount1 = true;
              break;
            case 2 :
                std::cout << " \nCreating secondary Account:\n";
                account2 = BankAccount::createAccountFromInput();
                hasaccount2 = true;
                break;
            case 3:
                if (hasaccount1) {
                    std::cout << " Create primary account first\n";
                    break;
                }
                double depositAmount;
                std::cout << "Enter deposite amount;";
                std::cin >> depositAmount;
                account1 += depositAmount;
                break;
            case 4: 
                if (hasaccount1) {
                    std::cout << " create primary account first\n";
                    break;
                }
                double Amount;
                std::cout << "Enter withdrawal amount:";
                std::cin >> Amount;
                account1 -= Amount;
                break;
            case 5:
                if (hasaccount1) {
                    std::cout << " No primary account created yet\n'";
                } else {
                    BankAccount::printAccount(account1);
                } 
                break;

            case 6: 
                 if (hasaccount1 && hasaccount2) {
                    std::cout << " you must create both accounts first\n";
                }else {
                    if (account1 > account2) {
                        std::cout << " priimary account has a giher balnace  then secondary account\n";
                    } else if (account1 < account2) {
                        std::cout << " secondary account has a higher balance then primary acocunt \n";
                    } else {
                        std::cout << " both accounts have the same balance\n";
                    }
                }
                    break;
                
            case 7: 
                if (hasaccount1 && hasaccount2) {
                    std:: cout << " you must create both accounts\n";
                }else {
                    if (account1 == account2) {
                        std::cout << " both accounts have the same balance\n";
                    }else {
                        std::cout << " both accounts have different balance\n";
                    }
                }
                break;
            case 8:
                std::cout << "exiting the program...\n";
                break;
            default:
                std::cout << " Invalid choice. Please try agian.\n";
                break;
                    
            }


        }
        return 0;
}