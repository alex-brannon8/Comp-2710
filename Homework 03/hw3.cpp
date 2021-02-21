// name: Derrick Turner, det0009
// partner: Alex Brannon, adb0056
// filename: hw03.ccp
// due date: 9/14/2018
// collaboration:
// problem: Determine and count how many duels 
// would be won between three shooters.

# include <iostream> 
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>

using namespace std;



bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void test_at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);

void Aaron_shoots (bool&, bool&);
void test_Aaron_shoots ();

void Bob_shoots (bool&, bool&);
void test_Bob_shoots();

void Charlie_shoots (bool&, bool&);
void test_Charlie_shoots();

void Aaron_shoots2(bool&, bool&);
void test_Aaron_shoots2();


int percentageShot = rand()%100;
const double Aaron_Shot = 1/3;
const double Bob_Shot = 1/2;
const double Charlie_Shot = 1;
bool first_shot = true;
bool Aaron, Bob, Charlie = true;
const double NUM_DUELS = 10000;
const double PERCENT = 100; 


   
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   return A_alive && B_alive || A_alive && C_alive || B_alive && C_alive;
}

void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   cout << "\t\t\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout <<"\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\t\t\tCase passed ...\n";
}
 
void Aaron_shoots(bool& Bob_alive, bool& Charlie_alive) {
  
   double quickscope;
   quickscope = rand() % 100;
   if (quickscope <= Aaron_Shot) {
      if (Charlie_alive) {
         Charlie_alive = false;
         cout << "\t\t\t\tCharlie is dead.\n";
      }
      
      else {
         Bob_alive = false;
         cout << "\t\t\t\tBob is dead.\n";
      }
   
   }
   else {
      cout << "\t\t\t\tAaron misses.\n";
   }
}


void test_Aaron_shoots (void) {
   bool B_alive;
   bool C_alive;
   
   cout << "Unit Testing 2: Function Aaron_shoots(Bob_Alive, Charlie_alive)\n";
   cout << "\t\t\tCase 1: Bob alive, Charlie alive\n";
   
   B_alive = true;
   C_alive = true;
   cout << "\t\t\t\t\t\tAaron is shooting at Charlie.\n\t\t";
   Aaron_shoots(B_alive, C_alive);
   
   cout << "\t\t\tCase 2: Bob dead, Charlie alive\n";
                  
   B_alive = false;
   C_alive = true;
   cout << "\t\t\t\t\t\tAaron is shooting at Charlie.\n\t\t";
   Aaron_shoots(B_alive, C_alive);

   cout << "\t\t\tCase 3: Bob alive, Charlie dead\n";
   B_alive = true;
   C_alive = false;
   cout << "\t\t\t\t\t\tAaron is shooting at Bob.\n";
   Aaron_shoots(B_alive, C_alive);
}

void Bob_shoots(bool& Aaron_alive, bool& Charlie_alive) {
  
   double quickscope;
   quickscope = rand() % 100;
   if (quickscope <= Bob_Shot) {
      if (Charlie_alive) {
         Charlie_alive = false;
         cout << "\n\t\t\t\tCharlie is dead.";
      }
      else {
         Aaron_alive = false;
         cout << "\n\t\t\t\tAaron is dead.";
      }
   }
   else {
      cout << "\n\t\t\t\t\t\tBob misses.";
   }
}

void test_Bob_shoots(void) {
   bool A_alive;
   bool C_alive;
   
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_Alive, Charlie_alive)";
   cout << "\n\t\t\tCase 1: Aaron alive, Charlie alive";
   A_alive = true;
   C_alive = true;
   cout << "\n\t\t\t\t\t\tBob is shooting at Charlie\t\t";
   Bob_shoots(A_alive, C_alive);
   cout << "\n\t\t\tCase 2: Aaron dead, Charlie alive";
   A_alive = false;
   C_alive = true;
   cout << "\n\t\t\t\t\t\tBob is shooting at Charlie\t\t";
   Bob_shoots(A_alive, C_alive);
   cout << "\n\t\t\tCase 3: Aaron alive, Charlie dead";
   A_alive = true;
   C_alive = false;
   cout << "\n\t\t\t\t\t\tBob is shooting at Aaron";
   Bob_shoots(A_alive, C_alive);
}



void Charlie_shoots(bool& Aaron_alive, bool& Bob_alive) {
  
   double quickscope;
   quickscope = rand() % 100;
   if (Bob_alive) {
      Bob_alive = false;
      cout << "\n\t\t\t\t\t\tBob is dead.";
   }
   else {
      Aaron_alive = false;
      cout << "\n\t\t\t\t\t\tAaron is dead.";
   }
}
  
   


void test_Charlie_shoots(void) {
   bool A_alive;
   bool B_alive;
   
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_Alive, Bob_alive)\n";
   cout << "\t\t\tCase 1: Aaron alive, Bob alive";
   
   A_alive = true;
   B_alive = true;
   cout << "\n\t\t\t\t\t\tCharlie is shooting at Bob.\t\t";
   Charlie_shoots(A_alive, B_alive);
   
   cout << "\n\t\t\tCase 2: Aaron dead, Bob alive";
                  
   A_alive = false;
   B_alive = true;
   cout << "\n\t\t\t\t\t\tCharlie is shooting at Bob\t\t";
   Charlie_shoots(A_alive, B_alive);   
       
   cout << "\n\t\t\tCase 3: Aaron alive, Bob dead";
   A_alive = true;
   B_alive = false;
   cout << "\n\t\t\t\t\t\tCharlie is shooting at Aaron";
   Charlie_shoots(A_alive, B_alive);
      
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   int shoot;
   if (first_shot) {
      first_shot = false;
      cout << "\n\t\t\tBoth Bob and Charlie are alive.";
      return;
   }
   shoot = rand() % 100;
   if (shoot <= Aaron_Shot) {
      if ( C_alive) {
         C_alive = false;
         cout << "Charlie is dead.\n";
      }
      else {
         B_alive = false;
         cout << "Bob is dead.\n";
      }
   }
   else {
      cout << "Aaron misses.\n";
   }
}

void test_Aaron_shoots2() {
   cout << "Unit Testing 5: Function Aaraon_shoots2(Bob_Alive, Charlie_alive)";
   cout << "\n\t\t\tCase 1: Bob alive, Charlie alive";
   Bob = true;
   Charlie = true;
   cout << "\n\t\t\t\t\t\tAaron intentionally misses his first shot";
   cout << "\n\t\t\t\tBoth Bob and Charlie are alive";
   cout << "\n\t\t\tCase 2: Bob dead, Charlie alive";
   Bob = false;
   Charlie = true;
   cout << "\n\t\t\t\t\t\tAaron is shooting at Charlie";
   Aaron_shoots2(Bob, Charlie);
   cout << "\n\t\t\tCase 3: Bob alive, Charlie dead";
   Bob = true;
   Charlie = false;
   cout << "\n\t\t\t\t\t\tAaron is shooting at Bob";
   Aaron_shoots2(Bob, Charlie);
}
  

void press_any_key(void) {
  
   cout << "\nPress Enter to continue...";
   
   if (cin.get()) {
      cout << endl;
   }
} 


void Aaron_shoots_duel(bool& Bob_alive, bool& Charlie_alive) {
  
   double quickscope;
   quickscope = rand() % 100;
   if (quickscope <= Aaron_Shot) {
      if (Charlie_alive) {
         Charlie_alive = false;
      }
      else {
         Bob_alive = false;
      }
   }
}

void Bob_shoots_duel(bool& Aaron_alive, bool& Charlie_alive) {
  
   double quickscope;
   quickscope = rand() % 100;
   if (quickscope <= Bob_Shot) {
      if (Charlie_alive) {
         Charlie_alive = false;
      }
      else {
         Aaron_alive = false;
      }
   }
}

void Charlie_shoots_duel(bool& Aaron_alive, bool& Bob_alive) {
  
   double quickscope;
   quickscope = rand() % 100;
   if (quickscope <= Charlie_Shot) {
      if (Bob_alive) {
         Bob_alive = false;
      }
      else {
         Aaron_alive = false;
      }
   }
}

void Aaron_shoots2_duel(bool& B_alive, bool& C_alive) {
   int shoot;
   if (first_shot) {
      first_shot = false;
   }
   shoot = rand() % 100;
   if (shoot <= Aaron_Shot) {
      if ( C_alive) {
         C_alive = false;
      }
      else {
         B_alive = false;
      }
   }
}



int main() {
   int awins = 0, bwins = 0, cwins = 0;
   srand(time(0)); 
    
   cout << "*** Welcome to Puzzlevania's Duel Simulator ***\n";
   test_at_least_two_alive();
   press_any_key(); //Press Any Key To Continue
   cout << endl;
   test_Aaron_shoots();
   press_any_key(); //Press Any Key To Continue
   cout << endl;
   test_Bob_shoots();
   press_any_key(); //Press Any Key To Continue
   cout << endl;
   test_Charlie_shoots();
   press_any_key(); //Press Any Key To Continue
   cout << endl;
   test_Aaron_shoots2();
   press_any_key(); //Press Any Key To Continue
   cout << endl;
  
   cout << "\nReady to test strategy 1 (run 10000 times):\n";
   press_any_key(); //Press Any Key To Continue
       
   for (int i = 0; i < NUM_DUELS; i++) {
      while (at_least_two_alive(Aaron, Bob, Charlie)) {
         if (Aaron) {
            Aaron_shoots_duel(Bob, Charlie);
         }
         if (Bob) {
            Bob_shoots_duel(Aaron, Charlie);
         }
         if (Charlie) {
            Charlie_shoots_duel(Aaron, Bob);  
         } 
      } 
      if (Aaron) {
         awins++;
      }
      if (Bob) {
         bwins++;
      } 
      if (Charlie) {
         cwins++;
      }
      Aaron = true;
      Bob = true;
      Charlie = true;
   }
   cout << "\nAaron won " << awins << " / 10000 duels or " << (awins / NUM_DUELS) * PERCENT << "%";
   cout << "\nBob won " << bwins << " / 10000 duels or " << (bwins / NUM_DUELS) * PERCENT << "%";
   cout << "\nCharlie won " << cwins << " / 10000 duels or " << (cwins / NUM_DUELS) * PERCENT << "%" << endl;
    
   cout << "\nReady to test strategy 2 (run 10000 times):\n";
   press_any_key();

   double awins2, bwins2, cwins2 = 0;

   for (int j = 0; j < NUM_DUELS; j++) {
      while (at_least_two_alive(Aaron, Bob, Charlie)) {
         if (Aaron) {
            Aaron_shoots2_duel(Bob, Charlie);
         }
         if (Bob) {
            Bob_shoots_duel(Aaron, Charlie);
         }
         if (Charlie) {
            Charlie_shoots_duel(Aaron, Bob);  
         } 
      }
      if (Aaron) {
         awins2++;
                
      }
      if (Bob) {
         bwins2++;
      } 
      if (Charlie) {
         cwins2++;
      }
      Aaron = true;
      Bob = true;
      Charlie = true;
   }        
   cout << "\nAaron won " << awins2 << " / 10000 duels or " << (awins2 / NUM_DUELS) * PERCENT << "%\n";
   cout << "Bob won " << bwins2 << " / 10000 duels or " << (bwins2 / NUM_DUELS) * PERCENT << "%\n";
   cout << "Charlie won " << cwins2 << " / 10000 duels or " << (cwins2 / NUM_DUELS) * PERCENT << "%" << endl;

   if (awins > awins2) {
      cout << "\nStrategy 1 is better than strategy 2.";
   }
   if (awins2 > awins) {
      cout << "\nStrategy 2 is better than strategy 1.";
   }
   return 0;   }


