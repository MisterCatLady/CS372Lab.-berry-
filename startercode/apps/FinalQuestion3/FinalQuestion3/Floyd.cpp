//I consulted with ChatGPT to write this code
#include <iostream>
#include <iomanip>
#include "Floyd.h"

using namespace std;

// Pretty-print the matrix
void printMatrix(const vector<vector<int>>& M)
{
    for (const auto& row : M) {
        for (int val : row) {
            if (val >= INF / 2)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << val;
        }
        cout << "\n";
    }
}

int main()
{
    // Example weighted graph (adjacency matrix)
    // INF means no direct edge.

    vector<vector<int>> W = {
        { 0,   3,   INF, 7 },
        { 8,   0,   2,   INF },
        { 5,   INF, 0,   1 },
        { 2,   INF, INF, 0 }
    };

    cout << "Adjacency matrix W:\n";
    printMatrix(W);

    cout << "\nRunning Floyd...\n\n";

    vector<vector<int>> D = floyd(W);

    cout << "All-pairs shortest-path matrix D:\n";
    printMatrix(D);

    return 0;
}