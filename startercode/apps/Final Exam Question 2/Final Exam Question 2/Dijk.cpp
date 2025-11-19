//I consulted with ChatGPT when writing this code
#include <iostream>
#include <iomanip>
#include "ALWGraph.hpp"
#include "Dijkstra.h"

int main()
{
    WeightedAdjListGraph<int> g;

    // ---- Build example graph ----
    // Add nodes 0..4
    for (int i = 0; i < 5; i++)
        g.addNode(i);

    // Add undirected weighted edges
    auto addUndirected = [&](int u, int v, int w) {
        g.addEdgeWithWeight(u, v, w);
        g.addEdgeWithWeight(v, u, w);  // because graph is undirected
        };

    addUndirected(0, 1, 4);
    addUndirected(0, 2, 1);
    addUndirected(2, 1, 2);
    addUndirected(1, 3, 1);
    addUndirected(2, 3, 5);
    addUndirected(3, 4, 3);

    int source;
    std::cout << "Enter source vertex: ";
    std::cin >> source;

    // ---- Run Dijkstra ----
    vector<int> dist = dijkstra(g, source);

    // ---- Output results ----
    std::cout << "\nShortest-path distances from vertex " << source << ":\n";
    std::cout << "-------------------------------------------\n";
    std::cout << " Node | Distance\n";
    std::cout << "-------------------------------------------\n";

    for (size_t i = 0; i < dist.size(); i++) {
        if (dist[i] == std::numeric_limits<int>::max())
            std::cout << "  " << i << "   | unreachable\n";
        else
            std::cout << "  " << i << "   | " << dist[i] << "\n";
    }

    return 0;
}