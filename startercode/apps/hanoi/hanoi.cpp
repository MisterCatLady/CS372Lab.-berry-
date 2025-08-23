#include <iostream>
#include <chrono>
using namespace std;
<<<<<<< HEAD
=======
using namespace std::chrono;
>>>>>>> Early trial and error

void moveDisks(int, int, int, int);
void printIt(int , int , int );

<<<<<<< HEAD
int main() {
=======
int main() 
{
>>>>>>> Early trial and error
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 3;
<<<<<<< HEAD
    for (auto numdisks: {3,5,6}) {
      cout << "Numdisks: " << numdisks << endl;
      moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
      cout << "Moved " << numdisks << " pegs"
           << " from peg " << FROMPEG
           << " to peg " << TOPEG << endl;
    }
=======


    for (auto numdisks: {5,10,15}) 
    {
        //begin timing clock
        auto startTime = high_resolution_clock::now();
        cout << "Numdisks: " << numdisks << endl;
        moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
        printIt(numdisks, FROMPEG, TOPEG);
        //stop timing clock
        auto endTime = high_resolution_clock::now();
        //calculate duration
        auto durationTime = duration_cast<milliseconds>(endTime - startTime);
        cout << "Hanoi Towers puzzle with " << numdisks << " disks took " << durationTime.count() << " ms\n";
    }
    

   
    
>>>>>>> Early trial and error
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
     if (num > 0) {
        moveDisks(num -1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num-1, tempPeg, toPeg, fromPeg);
     }
}

void printIt(int disk, int fromPeg, int toPeg) {
  // Do nothing for timing test, but otherwise
  cout<< "Move disk " << disk
<<<<<<< HEAD
      << " from pef " << fromPeg
=======
      << " from peg " << fromPeg
>>>>>>> Early trial and error
      << " to peg " << toPeg << endl;
}
