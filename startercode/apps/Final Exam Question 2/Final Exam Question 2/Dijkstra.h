//I consulted with ChatGPT when writing this code
#pragma once
#include <vector>
#include <queue>
#include <limits>
#include <map>
#include "ALWGraph.hpp"

template<typename N>
std::vector<int> dijkstra(WeightedAdjListGraph<N>& g, N source)
{
    std::map<N, bool> visited;
    std::vector<N> nodes;
    std::queue<N> q;

    q.push(source);
    visited[source] = true;
    nodes.push_back(source);

    while (!q.empty()) {
        N u = q.front();
        q.pop();
        std::vector<N> neighs = g.neighbors(u);

        for (N v : neighs) {
            if (!visited[v]) {
                visited[v] = true;
                nodes.push_back(v);
                q.push(v);
            }
        }
    }

    const int INF = std::numeric_limits<int>::max();
    std::map<N, int> dist;

    for (N v : nodes)
        dist[v] = INF;

    dist[source] = 0;

    typedef std::pair<int, N> PQItem;
    std::priority_queue<PQItem, std::vector<PQItem>, std::greater<PQItem>> pq;

    pq.push(PQItem(0, source));

    while (!pq.empty()) {
        PQItem top = pq.top();
        pq.pop();
        int d = top.first;
        N u = top.second;

        if (d > dist[u]) continue;

        std::vector<N> neighs = g.neighbors(u);
        for (N v : neighs) {
            int w = g.getEdgeWeight(u, v);
            int alt = dist[u] + w;

            if (alt < dist[v]) {
                dist[v] = alt;
                pq.push(PQItem(alt, v));
            }
        }
    }

    int maxNode = 0;
    for (auto it : dist)
        if (it.first > maxNode)
            maxNode = it.first;

    std::vector<int> result(maxNode + 1, INF);

    for (auto it : dist)
        result[it.first] = it.second;

    return result;
}