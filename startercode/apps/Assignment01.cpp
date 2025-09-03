#include <iostream>
#include <chrono>
#include <stack>
#include <cmath>
using namespace std;

//recursive function initialization
void moveDisksRec(int, int, int, int);
void printItRec(int, int, int);
//iterative function initialization
void moveDisksIt(int, stack<int>&, stack<int>&, stack<int>&);
void printItIt(int, char, char);
void MoveDisksHelper(stack<int>&, stack<int>&, char, char);

int main()
{
    //recursive local variables
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 3;
    //Recursive timing
    for (auto numdisks : { 3,5,6 }) {
        cout << "Numdisks: " << numdisks << endl;
        auto start = std::chrono::steady_clock::now();
        moveDisksRec(numdisks, FROMPEG, TOPEG, TEMPPEG);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = end - start;
        cout << "Moved " << NUMDISKS << " pegs in " << elapsedSeconds.count() << "seconds, recursively\n";
    }
    //iterative local variables
    stack<int> source;
    stack<int> dest;
    stack<int> aux;
    //Iterative timing
    for (auto numdisks : { 3,5,6 })
    {
        stack<int> source;
        stack<int> dest;
        stack<int> aux;
        cout << "Numdisks: " << numdisks << endl;
        auto start = std::chrono::steady_clock::now();
        moveDisksIt(numdisks, source, aux, dest);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = end - start;
        cout << "Moved " << numdisks << " pegs in " << elapsedSeconds.count() << "seconds, iteratively\n";
    }
    return 0;
}


//recursive functions
void moveDisksRec(int num, int fromPeg, int toPeg, int tempPeg)
{
    if (num > 0)
    {
        moveDisksRec(num - 1, fromPeg, tempPeg, toPeg);
        printItRec(num, fromPeg, toPeg);
        moveDisksRec(num - 1, tempPeg, toPeg, fromPeg);
    }
}
void printItRec(int disk, int fromPeg, int toPeg)
{
    // Do nothing for timing test, but otherwise
    cout << "Move disk " << disk
        << " from peg " << fromPeg
        << " to peg " << toPeg << endl;
}
//iterative functions
void moveDisksIt(int num, stack<int>& fromPeg, stack<int>& tempPeg, stack<int>& toPeg) {
    char s = 'S', d = 'D', a = 'A';
    if (num % 2 == 0) { // Swap in num disks is even.
        char temp = d;
        d = a;
        a = temp;
    }
    int numberOfMoves = pow(2, num) - 1;
    for (int i = num; i >= 1; i--) {
        fromPeg.push(i);
    }
    // now do moves:
    for (int i = 1; i <= numberOfMoves; i++) {
        if (i % 3 == 0) {
            MoveDisksHelper(tempPeg, toPeg, a, d);
        }
        else if (i % 3 == 2) {
            MoveDisksHelper(fromPeg, tempPeg, s, a);
        }
        else if (i % 3 == 1) {
            MoveDisksHelper(fromPeg, toPeg, s, d);
        }
    }
}

void MoveDisksHelper(stack<int>& source, stack<int>& dest, char s, char d) {
    int top1;
    int top2;
    if (source.empty()) {
        top2 = dest.top();
        dest.pop();
        source.push(top2);
        printItIt(top2, d, s);
    }
    else if (dest.empty()) {
        top1 = source.top();
        source.pop();
        dest.push(top1);
        printItIt(top1, s, d);
    }
    else if (source.top() > dest.top()) {
        top1 = source.top();
        source.pop();
        top2 = dest.top();
        dest.pop();
        source.push(top1);
        source.push(top2);
        printItIt(top2, d, s);
    }
    else {
        top2 = dest.top();
        dest.pop();
        top1 = source.top();
        source.pop();
        dest.push(top2);
        dest.push(top1);
        printItIt(top1, s, d);
    }
}
void printItIt(int disk, char fromPeg, char toPeg) {
    // Do nothing for timing test, but otherwise
    std::cout << "Move disk " << disk
        << " from peg " << fromPeg
        << " to peg " << toPeg << std::endl;
}