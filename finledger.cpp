#include "finledger.hpp"
using namespace std;
Transaction::Transaction(string payer,float amount,const vector<string>&participants):payer(payer),amount(amount),participants(participants){}
void FinLedger::addTransaction(const string&payer,float amount,const vector<string>&participants)
{
    if(participants.empty()) return;
    float share=amount/participants.size();
    for(const auto&person:participants)
    {
        if(person!=payer)
        {
            balances[person]-=share;
            balances[payer]+=share;
        }
    }
    history.emplace_back(payer,amount,participants);
    cout<<"Transaction added successfully.\n";
}
void FinLedger::showBalances() const
{
    cout<<"\nCurrent Balances:\n";
    for(const auto& entry:balances)
    {
        cout<<entry.first<<": "<<entry.second<<"\n";
    }
}
void FinLedger::showTransactionHistory() const
{
    cout<<"\nTransaction History:\n";
    for(const auto&tx:history)
    {
        cout<<tx.payer<<" paid "<<tx.amount<<" for [ ";
        for(const auto&p:tx.participants) cout<<p<<" ";
        cout<<"]\n";
    }
}
