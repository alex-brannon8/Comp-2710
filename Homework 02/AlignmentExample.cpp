#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{

   float float_a = 10.53;
   float float_b = 6329.07;

   cout << "No setw() ..." << endl;
   cout << float_a << " " << float_a << endl;
   cout << float_b << " " << float_b << endl;

   cout << "Add left and setw() ..." << endl;
   cout << left << setw(10) << float_a << float_a << endl;
   cout << left << setw(10) << float_b << float_b << endl;

   return 0;
}
