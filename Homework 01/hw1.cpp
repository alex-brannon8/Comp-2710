// name: Alexander Brannon, adb0056
// partner: NONE
// filename: hw01.cpp
// due date: 8/31/2018
// collaboration: I used cplusplus.com to help learn the basics
//    of C++. Like printing output and accepting input. 
// problem: determine how much diet soda it is possible to drink
//    without dying as a result

#include <iostream>

double deathAmount;
double mouseWeight;
double dieterWeight;
double sodaAmount;
const double RATE = 0.001;


int main()
{
   std::cout << "What is the amount of artificial sweetener needed "
      "to kill a mouse:\n"; 
   std::cin >> deathAmount;
   std::cout << "\n";
   std::cout << "What is the weight of the mouse: ";
   std::cin >> mouseWeight;
   std::cout << "\n";
   std::cout << "What is the weight of the dieter: ";
   std::cin >> dieterWeight;
   sodaAmount = (deathAmount / mouseWeight)* (dieterWeight / RATE);
   
   
   std::cout << "\nYou can drink " << sodaAmount << " diet soda without dying "
      "as a result.";
   
}
