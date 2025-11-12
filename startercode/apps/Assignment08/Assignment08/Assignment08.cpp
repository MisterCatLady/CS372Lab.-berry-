#include "AdjListGraph.hpp"
#include "AdjMatrixGraph.hpp"
#include "ALWGraph.hpp"
#include "AMWGraph.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <unordered_set>
#include <string>
//ChatGPT helped me write this code

//Write a function, and test scripts for that function, that given a reference to a graph and a vector of integers that defines a path through the graph, 
//returns a boolean value of true if the path is a simple cycle in the graph.NOTE : remember that a cycle is a path that begins and ends at the same node 
//in the graph and has no loops within the cycle(visits each node at least once.So, you have to verify it’s a valid path and that the path never visits a node more than once. 
// (HINT: As Fred Rogers once said, “Won’t you be my neighbor ? ”)
bool isSimpleCycle(Graph<int>& g, const vector<int>& path);
bool findKevinBaconPath(AdjListGraph<string>& g, const string& start,
	const string& target, list<string>& path);
void buildSocialGraph(AdjListGraph<string>& g);

class GraphTest
{
protected:
	AdjListGraph<int> testALG;
	AdjMatrixGraph<int> testAMG;

	void setUp()
	{
		testALG.addNode(0);
		testALG.addNode(1);
		testALG.addNode(2);
		testALG.addNode(3);

		testALG.addEdge(0, 1);
		testALG.addEdge(0, 2);
		testALG.addEdge(0, 3);

		testALG.addEdge(1, 0);
		testALG.addEdge(1, 2);
		testALG.addEdge(1, 3);

		testALG.addEdge(2, 0);
		testALG.addEdge(2, 1);
		testALG.addEdge(2, 3);

		testALG.addEdge(3, 0);
		testALG.addEdge(3, 1);
		testALG.addEdge(3, 2);

		testAMG.addNode(0);
		testAMG.addNode(1);
		testAMG.addNode(2);
		testAMG.addNode(3);

		testAMG.addEdge(0, 1);
		testAMG.addEdge(0, 2);
		testAMG.addEdge(0, 3);

		testAMG.addEdge(1, 0);
		testAMG.addEdge(1, 2);
		testAMG.addEdge(1, 3);

		testAMG.addEdge(2, 0);
		testAMG.addEdge(2, 1);
		testAMG.addEdge(2, 3);

		testAMG.addEdge(3, 0);
		testAMG.addEdge(3, 1);
		testAMG.addEdge(3, 2);
	}
public:
	void runTests() {
		setUp();

		// Simple cycle path example: 0 ? 1 ? 2 ? 0
		vector<int> path1 = { 0, 1, 2, 0 };
		vector<int> path2 = { 0, 1, 2, 3 }; // not a cycle

		cout << "AdjListGraph Simple Cycle (0-1-2-0): "
			<< (isSimpleCycle(testALG, path1) ? "TRUE" : "FALSE") << endl;

		cout << "AdjListGraph Non-Cycle (0-1-2-3): "
			<< (isSimpleCycle(testALG, path2) ? "TRUE" : "FALSE") << endl;

		cout << "AdjMatrixGraph Simple Cycle (0-1-2-0): "
			<< (isSimpleCycle(testAMG, path1) ? "TRUE" : "FALSE") << endl;

		cout << "AdjMatrixGraph Non-Cycle (0-1-2-3): "
			<< (isSimpleCycle(testAMG, path2) ? "TRUE" : "FALSE") << endl;
	}
};

int main() {
	cout << "===== GRAPH FUNCTION TESTS =====" << endl << endl;

	GraphTest tester;
	tester.runTests();

	cout << "\n===== SOCIAL GRAPH (Kevin Bacon Game) =====" << endl;

	AdjListGraph<string> socialGraph;
	buildSocialGraph(socialGraph);

	list<string> path;
	if (findKevinBaconPath(socialGraph, "Lindsey Berry", "Kevin Bacon", path)) {
		cout << "Connected to Kevin Bacon!" << endl;
		cout << "Path: ";
		for (auto& person : path)
			cout << person << " ";
		cout << endl;
		cout << "Kevin Bacon number: " << (path.size() - 1) << endl;
	}
	else {
		cout << "No connection to Kevin Bacon found." << endl;
	}

	cout << "\n===== END OF TEST =====" << endl;
	return 0;
}
bool isSimpleCycle(Graph<int>& g, const vector<int>& path) {
	if (path.size() < 3) return false;
	if (path.front() != path.back()) return false;

	unordered_set<int> visited;
	for (size_t i = 0; i < path.size() - 1; i++) {
		int current = path[i];
		int next = path[i + 1];

		if (!g.adjacent(current, next)) return false;
		if (visited.count(current)) return false;

		visited.insert(current);
	}
	return true;
}
//	Social networking applications use one form of a graph to keep track of your connections.This is a social graph.
void buildSocialGraph(AdjListGraph<string>& g) {
	vector<string> people = {
		"Lindsey Berry", "Kevin Bacon", "Dolly Parton", "Jennifer Nettles",
		"Choir Teacher", "Dolly's Sister's First Husband", "Alice", "Bob",
		"Charlie", "Dana", "Eve", "Frank", "Grace", "Hank", "Isabel",
		"Jack", "Karen", "Liam", "Mona", "Nina"
	};

	for (auto& p : people)
		g.addNode(p);

	// Local network
	g.addEdge("Lindsey Berry", "Alice");
	g.addEdge("Alice", "Bob");
	g.addEdge("Bob", "Charlie");
	g.addEdge("Charlie", "Dana");
	g.addEdge("Dana", "Kevin Bacon");

	// Real-world connection (Dolly ? Jennifer ? Kevin)
	g.addEdge("Lindsey Berry", "Choir Teacher");
	g.addEdge("Choir Teacher", "Dolly's Sister's First Husband");
	g.addEdge("Dolly's Sister's First Husband", "Dolly Parton");
	g.addEdge("Dolly Parton", "Jennifer Nettles");
	g.addEdge("Jennifer Nettles", "Kevin Bacon");
}
//	Have you heard of the parlor game “Seven Degrees of Kevin Bacon” ? In the game, if you start with a bunch of friends, it will take you no more than 7 tries to find a path in your social graph that will lead you to Kevin Bacon.

//	Build a social graph for a group of 20 people including both you and Kevin Bacon.Write a function that given a reference to that social graph, tells you whether or not you are connected to Kevin Bacon.The function should return true if you are and also use a reference parameter to return a list of nodes that shows the path betwen you and Kevin Bacon if it exists or an empty list if it doesn’t.Your Kevin Bacon number is the length of that path.
bool findKevinBaconPath(AdjListGraph<string>& g, const string& start,
	const string& target, list<string>& path) {
	map<string, bool> visited;
	map<string, string> parent;
	queue<string> q;

	q.push(start);
	visited[start] = true;

	bool found = false;
	while (!q.empty()) {
		string current = q.front();
		q.pop();

		if (current == target) {
			found = true;
			break;
		}

		vector<string> neighbors = g.neighbors(current);
		for (auto neighbor : neighbors) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				parent[neighbor] = current;
				q.push(neighbor);
			}
		}
	}

	if (!found) return false;

	// Reconstruct path
	string cur = target;
	while (cur != start) {
		path.push_front(cur);
		cur = parent[cur];
	}
	path.push_front(start);
	return true;
}
