
#include <iostream>
using namespace std;

string headHurt;


void youGotThis() {

   cout << "Hey baby! I'm just checking up on you :)" << endl;
   cout << "Does your head hurt? It doesn't seem like it does right now. Which is GREAT!\n" << endl;
   cin >> headHurt;
   if (headHurt == "yes" || headHurt == "Yes" || headHurt == "Ya" || headHurt == "ya" || headHurt == "Yeah" || headHurt == "yeah") {
      cout << "\nI'm sorry Giovanna /:\nI can tell you're stressed\nBut don't worry!" << endl;
      cout << "This week is almost over and I am going to TREAT you this weekend when we're not busy :)" << endl;
   }
   else if (headHurt == "No" || headHurt == "Nope" || headHurt == "no" || headHurt == "nope") {
      cout << "\nThat's great! <3\nI'm super glad!" << endl;
   }
   else {
      cout << "\nSorry!\nThis program has no idea what you inputed because you put one of your weird misspelled words." << endl;
   }
   cout << "\nAnyways, I am so very proud of you Mi Reina Boricua!\n\nYou have a lot going on in your life and you give everything your all." << endl;
   cout << "\nI am a better person because you are in my life and I cannot be more thankful." << endl;
   cout << "\nYou are an amazing, powerful woman who does not back down to anything. That's part of why I fell in love with you." << endl;
   cout << "\nI admire and adore you oh so much. I know you will succeed in anything and everything you want to do." << endl;
}

int main() {

   youGotThis();
   cout << "\nP.S.\nYou don't have bags under your eyes." << endl;
   cout << "\nP.S.S\nI like when you teach me about what you're learning in class." << endl;
   cout << "\nP.S.S.S\nPut your feet on my lap if you want a massage. Feel free to move them around too ;) haha" << endl;
}
