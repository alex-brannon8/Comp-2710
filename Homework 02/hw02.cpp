// name: Alexander Brannon, adb0056
// partner: Derrick Turner, det0009
// filename: hw02.cpp
// due date: 09/07/2018
// collaboration: We looked up a way to correctly print out properly.
// problem: The program will tell you how many months it will take 
// to pay off this loan or any loan in particular.

#include <iostream>
#include <iomanip>

using namespace std;

double loanAmount;
double yearIntRate;
double monthlyPayment;
double balance;
int counter;
double rate;
double interest;
double principal;
double totalInterest;

int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "Loan Amount: ";
   cin >> loanAmount;
   cout << "Interest Rate (% per year): ";
   cin >> yearIntRate;
   cout << "Monthly Payments: ";
   cin >> monthlyPayment;
   
   
   cout << "\n*********************************"
      "*********************\n";
   cout << "\t\t\tAmortization Table\n";
   cout << "************************************"
      "******************\n";
      
   cout << left << setw(8) << "Month" 
      << left << setw(15)
      << "Balance" << left << setw(8)
      << "Payment" << left << setw(8)
      << "Rate" << left << setw(8) 
      << "Interest" << right << setw(10)
      << "Principal" << endl;
      
   cout << left << setw(8) << "0" 
      << left << "$" << setw(15) 
      << loanAmount << left << setw(8)
      << "N/A" << left << setw(8)
      << "N/A" << left << setw(8)
      << "N/A" << left << setw(8)
      << "N/A" << right << setw(10)
      << endl;
   
   balance = loanAmount; 
   interest = (rate / 100) * balance;
   principal = monthlyPayment - ((rate / 100) * balance);
   rate = yearIntRate / 12;
   
   
      
   while (balance >= monthlyPayment) {
      
      if (principal < 0 ) {
         cout << "*********************************"
            "*********************\n";
         cout << "\nYou cannot pay off this loan.";
         balance = -1;
      }
      else {
         counter++;
         interest = (rate / 100) * balance;
         principal = monthlyPayment - ((rate / 100) * balance);
      
         cout << left << setw(8) << counter
            << left << "$" << setw(15)
            << balance - principal << left << "$" << setw(8)
            << monthlyPayment << left << setw(8)
            << rate << left << "$" << setw(8)
            << interest << left << "$" << setw(8)
            << principal << endl;
         
         balance = balance - monthlyPayment + (((yearIntRate / 12) / 100) * balance);
         totalInterest += interest;
      }
   }
   
   if (balance >= 0) {
      interest = (rate / 100) * balance;
      principal = balance - interest;
      totalInterest += interest;
   
      cout << left << setw(8) << counter + 1
         << left << setw(16) 
         << "$0.00" << left << "$" << setw(8)
         << balance + interest << left << setw(8)
         << rate << left << "$" << setw(8)
         << interest << left << "$" << setw(8)
         << balance << endl;
      
      cout << "*********************************"
         "*********************\n";
      cout << "\nIt takes " << counter + 1 << " months to pay off the loan.";
      cout << "\nTotal interest paid is: " << "$" << totalInterest;
   }
}

