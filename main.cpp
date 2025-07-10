#include "finledger.hpp"
#include <iostream>
using namespace std;
int main()
{
    FinLedger ledger;
    int choice;
    do{
        cout << "\n--- FinLedger Menu ---\n";
        cout << "1. Add Transaction\n";
        cout << "2. Show Balances\n";
        cout << "3. Show Transaction History\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                string payer;
                float amount;
                int n;
                vector<string> participants;
                cout << "Enter payer name: ";
                cin >> payer;
                cout << "Enter amount paid: ";
                cin >> amount;
                cout << "Enter number of participants: ";
                cin >> n;
                cout << "Enter names of participants:\n";
                for (int i = 0; i < n; ++i)
                {
                    string name;
                    cin >> name;
                    participants.push_back(name);
                }
                ledger.addTransaction(payer, amount, participants);
                break;
            }
            case 2:
                ledger.showBalances();
                break;
            case 3:
                ledger.showTransactionHistory();
                break;
            case 4:
                cout << "Exiting FinLedger...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }while (choice != 4);
    return 0;
}
