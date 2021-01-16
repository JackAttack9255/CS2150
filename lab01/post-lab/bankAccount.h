//Sam Townsend
//sft3hy
//9/9/2020
//bankAccount.h

using namespace std;

class bankAccount {
public:
  bankAccount();
  bankAccount(double amount);
  ~bankAccount();
  
  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();

 private:
  double balance;

};
