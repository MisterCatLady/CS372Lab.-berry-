#include <iostream>
using namespace std;
//Add the Stack and Queue classes to your class library, using the code presented in lecture.
#include "Stack.h"
#include "Queue.h"
// The Josephus problem is the following game: N people,  numbered 1 to N, are sitting in a circle. 
// Starting at person 1, a hot  potato is passed. After M passes, the person holding the hot potato  
// is eliminated, the circle closes ranks, and the game continues with  the person who was sitting 
// after the eliminated person picking up the  hot potato. 
// The last remaining person wins.
void josephus(int N, int M)
{
    Queue<int> players;

    // Enqueue all players
    for (int i = 1; i <= N; ++i)
        players.push(i);

    cout << "Order of elimination: ";

    // Continue until one remains
    while (true)
    {
        // Pass the potato M times
        for (int i = 0; i < M; ++i)
        {
            int frontPlayer = players.back();   // since push() pushes to front, use back() to simulate queue behavior
            players.pop();                      // remove from back (oldest)
            players.push(frontPlayer);          // push to front (youngest)
        }

        // Eliminate next player
        int eliminated = players.back();
        players.pop();

        if (players.empty())
        {
            cout << eliminated << endl;
            cout << "No winner, last eliminated player was #" << eliminated << endl;
            break;
        }

        if (players.empty() == false)
            cout << eliminated << " ";

        // Check for last remaining
        if (players.empty())
            break;
        if (players.back() == players.front()) // just a sanity check
            break;
        if (players.empty())
            break;
        if (players.empty() == false && players.front() == players.back())
            break;

        // Check winner
        if (players.empty() == false && players.front() == players.back())
            break;

        if (players.empty())
            break;

        if (players.empty())
            break;
    }

    if (!players.empty())
    {
        cout << "\nWinner: Player #" << players.back() << endl;
    }
}

int main()
{
    int N, M;
    cout << "Enter number of players (N): ";
    cin >> N;
    cout << "Enter number of passes (M): ";
    cin >> M;

    josephus(N, M);

    return 0;
}
//Thus, if M = 0 and N = 5,   players are eliminated in order, and player 5 wins. 
// If M = 1 and N =  5, the order of elimination is 2, 4, 1, 5.  
// Write a program that solves the Josephus problem for any input values of M and N.    
// Try  to make your program as efficient as possible if you used a a list,  stack, or queue in this problem.

//Note: I am aware that there is a closed form solution of this problem that can give you an answer in a single computation.   
//In this case, I'm wanting you get some more practice using lists and queues.

//Write a function that,  given an argument of the number of players, solves the Josephus problem for that many players.