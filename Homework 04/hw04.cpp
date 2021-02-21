// name: Alexander Brannon, adb0056
// partner: Derrick Turner, det0009
// filename: hw04.cpp
// due date: 09/21/2018
// collaboration:
// problem: Read in two files to combine and sort the contents into one array
// in an empty file.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

using namespace std;

string fileName1;
string fileName2;
const int MAX_SIZE = 100;

int readFile(int inputArray[], ifstream& inStream);
int sort(int inputArray1[],int inputArray1_size,
int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size, string output_file);


int readFile(int inputArray[], ifstream& inStream) {

   int index;
   inStream >> inputArray[index];

   while (! inStream.eof()) {
      cout << inputArray[index] << endl;
      index++;
      inStream >> inputArray[index];
   }
   return index;
}

int sort(int inputArray1[], int inputArray1_size,
int inputArray2[], int inputArray2_size, int outputArray[]) {

   int a1, a2, i, j = 0;

   while (i < inputArray1_size +  inputArray2_size) {
   
      if ((a1 < inputArray1_size && a2 < inputArray2_size) && (inputArray1[a1] < inputArray2[a2])) {
         outputArray[i] = inputArray1[a1];
         a1++;
      }
      
      else if (inputArray2[a2] < inputArray1[a1]){
         outputArray[i] = inputArray2[a2];
         a2++;
      }
      
      else {
         outputArray[i] = inputArray1[a1];
         a1++;
      }
   }
}

void writefile(int outputArray[], int outputArray_size, string output_file) {
   ofstream output;

   output.open("output3.txt");
   if (output.fail()) {
      cout << "This file has failed to open" << endl;
      exit(1);
   }
   for (int i = 0; i < outputArray_size; i++) {
      output << outputArray[i] << "\n";
   }
   output.close();
 
}

void test_readfile(void) {
   test_array[MAX_SIZE];
   
   ifstream input;
    
   cout << "*** Unit Test Cases ***" << endl;
   cout << "Unit Test Case 1: readFile(int inputArray[], ifstream& inStream)." << endl;
   cout << "\tCase 1.1: Reading in text file (input1.txt)" << endll;
   cout << "\tCase 1.1 passed." << endl;
   input.open("input1.txt");
   int a = readfile(test_array, input);
   assert((0 <= a));
   input.close();
   cout << "\tCase 1.2: Reading";
   
     
}



int main() {

   
   
   
   cout << "*** Welcome to Alex's sorting program ***"
      "\nEnter the first input file name: ";
   cin >> fileName1;
   
   



}
