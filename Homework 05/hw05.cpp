// name: Alexander Brannon, adb0056
// partner: Derrick Turner, det0009
// filename: hw05.cpp
// due date: 10/05/2018
// collaboration: We looked up how to switch from testing to main on stackoverflow.com. We also received advice and help
//                from Jordan Martindale.
// problem: Write a program that allows users to input a question and answer.
//          Then allow them to answer them correctly for points.

#include <iostream>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <cstddef>
using namespace std;

struct triviaNode {

   string question;
   string answer;
   int awardPoints;
   triviaNode *nextQuestion;
};

class triviaList {

public:
   int counter;
   triviaNode *head;
   triviaNode *root;
   
   triviaList() {
   
      counter = 0;
      head = NULL;
      root = NULL;
   }
};

void initiateList(triviaList &list) {

   triviaNode *question1 = new triviaNode;
   triviaNode *question2 = new triviaNode;
   triviaNode *question3 = new triviaNode;

   //Built in question 1
   question1 -> question = "How long was "
      "the shortest war on record? (Hint: How many minutes?)";
   question1 -> answer = "38";
   question1 -> awardPoints = 100;
   question1 -> nextQuestion = question2;

   //Built in question 2
   question2 -> question = "What was Bank of America's original name? "
      "(Hint: Bank of Italy or Bank of Germany?)";
   question2 -> answer = "Bank of Italy";
   question2 -> awardPoints = 50;
   question2 -> nextQuestion = question3;
   
   //Built in question 3
   question3 -> question = "What is the best-selling video game of all time? "
      "(Hint: Call of Duty or Wii Sports?)";
   question3 -> answer = "Wii Sports";
   question3 -> awardPoints = 20;
   question3 -> nextQuestion = NULL;
   
   
   list.head = question1;
   list.root = question3;
   list.counter += 3;
}

int askTrivia(triviaList list, int i, int &totalPoints) {

   triviaNode *question_1 = list.head;
   //Makes sure that the question asked for is equal to one or greater
   if (i < 1) {
   
      cout << "\nWarning - The number of trivia to be asked must equal "
         "to or larger than 1.";
      return 1;
   }
   //Makes sure that the question asked for does not exceed the list
   if (i > list.counter) {
   
      cout << "\nWarning - There are only " << list.counter << " trivia questions "
         "in the list.";
      return 0;
   }
   
   string answer1;
   totalPoints = 0;
   
   for (int j = 0; j < i; j++) {
   
      cout << "\nQuestion: " << question_1 -> question << "\nAnswer: ";
      getline(cin, answer1);
      
      if (question_1 -> answer == answer1) {
      
         cout << "Your answer is correct. You receive " << question_1 -> awardPoints << " points.";
         totalPoints += question_1 -> awardPoints;
      }
      
      else {
      
         cout << "Your answer is wrong. The correct answer is: " << question_1 -> answer;
      }
      
      cout << "\nYour Total Points: " << totalPoints << endl;
      question_1 = question_1 -> nextQuestion;
   }
   
   return 0;
}

void addTrivia(triviaList &list) {

   string input;

   do {
      //increases amount of questions by one
      list.counter++;
      triviaNode *temp = new triviaNode;
      //prompts for new question
      cout << "Enter a question: ";
      getline(cin, temp -> question);
      //prompts for answer to new question
      cout << "Enter an answer: ";
      getline(cin, temp -> answer);
      //prompts for points for answering question correctly
      cout << "Enter award points: ";
      cin >> temp -> awardPoints;
      //asks if user wants to add another question or move on
      cout << "Continue? (Yes/No): ";
      getline(cin.ignore(), input);
      //adds the new question, answer, and points to the list
      list.root -> nextQuestion = temp;
      list.root = temp;
   }
   while (input.find("No") != string :: npos);
}

void test_askTrivia() {

   triviaList list;
   int totalPoints;

   initiateList(list);

   cout << "\nFunction to test: int askTrivia"
      "(triviaList& list, int i, int &totalPoints)\n";
   
   cout << "Unit Test Case 1: Ask no questions. The program "
      "should give a warning message.\n";
   assert(1 == askTrivia(list, 0, totalPoints));
   cout << "\nCase 1 passed...\n";
   
   cout << "\nUnit Test Case 2.1: Ask 1 question in the linked "
      "list. The tester enters an incorrect answer.\n";
   assert(0 == askTrivia(list, 1, totalPoints));
   assert(0 == totalPoints);
   cout << "\nCase 2.1 passed...\n";
   
   cout << "\nUnit Test Case 2.2: Ask 1 question in the linked "
      "list. The tester enters a correct answer.\n";
   assert(0 == askTrivia(list, 1, totalPoints));
   assert(100 == totalPoints);
   cout << "\nCase 2.2 passed...\n";
   
   cout << "\nUnit Test Case 3.1: Ask all the questions of the last "
      "trivia in the linked list. The tester enters the correct answer.\n";
   assert(0 == askTrivia(list, 3, totalPoints));
   assert(170 == totalPoints);
   cout << "Case 3.1 passed...\n";
   
   cout << "\nUnit Test Case 3.2: Ask all the questions of the last "
      "trivia in the linked list. The tester enters the incorrect answer.\n";
   assert(0 == askTrivia(list, 3, totalPoints));
   cout << "Case 3.2 passed...\n";
   
   cout << "\nUnit Test Case 4: Attempt to ask 5 questions in the linked list. "
      "Program should give a warning message.\n";
   assert(0 == askTrivia(list, 5, totalPoints));
   cout << "\nCase 4 passed...\n";
}

#ifdef UNIT_TESTING
      void test_askTrivia(void);
#endif

int main() {

#ifdef UNIT_TESTING

   cout << "*** This is a debugging version ***\n";
   test_askTrivia();
   cout << "\n*** End of the debugging version ***\n";

#else

   cout << "*** Welcome to Alex's and Derrick's trivia quiz game ***" << endl;
   triviaList game;
   int totalPoints;

   initiateList(game);
   addTrivia(game);

   askTrivia(game, game.counter, totalPoints);

   cout << "\n***Thank you for playing the trivia quiz game. Goodbye! ***" << endl;

#endif
   return 0;
}

   
   

