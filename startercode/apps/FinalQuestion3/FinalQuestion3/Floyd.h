//I consulted with ChatGPT to write this code
#pragma once
#include <vector>
#include <limits>

using std::vector;

const int INF = std::numeric_limits<int>::max() / 4;  

vector<vector<int>> floyd(const vector<vector<int>>& W)
{
    int n = W.size();

    // Step 1: Copy W ? D
    vector<vector<int>> D = W;

    // Step 2: Triple nested loop
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (D[i][k] == INF) continue;    
            for (int j = 0; j < n; j++) {
                if (D[k][j] == INF) continue; 

                // Core recurrence
                int throughK = D[i][k] + D[k][j];
                if (throughK < D[i][j]) {
                    D[i][j] = throughK;
                }
            }
        }
    }

    return D;
}