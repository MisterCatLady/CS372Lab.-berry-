#include "Graph.hpp"


//The Graph ADT is used to store data formatted as in a network. We have two ways to represent data in this form: an adjacency list and an adjacency matrix.
//
//Using the sample code found in the class GitHub repository, add support for both adjacency lists and adjacency matrix representations to your class library.
//
//Write a function, and test scripts for that function, that given a reference to a graph and a vector of integers that defines a path through the graph, 
//returns a boolean value of true if the path is a simple cycle in the graph.NOTE : remember that a cycle is a path that begins and ends at the same node 
//in the graph and has no loops within the cycle(visits each node at least once.So, you have to verify it’s a valid path and that the path never visits a node more than once. 
// (HINT: As Fred Rogers once said, “Won’t you be my neighbor ? ”)
//
//	Social networking applications use one form of a graph to keep track of your connections.This is a social graph.
//
//	Have you heard of the parlor game “Seven Degrees of Kevin Bacon” ? In the game, if you start with a bunch of friends, it will take you no more than 7 tries to find a path in your social graph that will lead you to Kevin Bacon.
//
//	Build a social graph for a group of 20 people including both you and Kevin Bacon.Write a function that given a reference to that social graph, tells you whether or not you are connected to Kevin Bacon.The function should return true if you are and also use a reference parameter to return a list of nodes that shows the path betwen you and Kevin Bacon if it exists or an empty list if it doesn’t.Your Kevin Bacon number is the length of that path.
//
