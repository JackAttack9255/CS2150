//Sam Townsend
//sft3hy
//9/9/2020
//bankAccount.cpp

#include <iostream>
#include "bankAccount.h"
using namespace std;

bankAccount::bankAccount() {
  balance = 0;
}

bankAccount::bankAccount(double amount) {
  balance = amount;
}

bankAccount::~bankAccount() {  
}

double bankAccount::withdraw(double amount) {
  if(amount > balance){
    return balance;
  } else {
    balance -= amount;
    return balance;
  }
}

double bankAccount::deposit(double amount){
  balance += amount;
  return balance;
}

double bankAccount::getBalance() {
  return balance;
}




