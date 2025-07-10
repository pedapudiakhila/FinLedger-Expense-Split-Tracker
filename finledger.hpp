#ifndef FINLEDGER_HPP
#define FINLEDGER_HPP
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Transaction
{
public:
    string payer;
    float amount;
    vector<string>participants;
    Transaction(string payer,float amount,const vector<string>&participants);
};
class FinLedger
{
private:
    unordered_map<string,float>balances;
    vector<Transaction>history;
public:
    void addTransaction(const string&payer,float amount,const vector<string>&participants);
    void showBalances() const;
    void showTransactionHistory() const;
};
#endif