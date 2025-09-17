//lberry4@my.athens.edu
//Assignment04.cpp
//Incomplete: Was under the impression last week's lecture would be posted by now. Apologies if this is incorrect.

//Add the Stack and Queue classes to your class library, using the code presented in lecture.

// The Josephus problem is the following game: N people,  numbered 1 to N, are sitting in a circle. 
// Starting at person 1, a hot  potato is passed. After M passes, the person holding the hot potato  
// is eliminated, the circle closes ranks, and the game continues with  the person who was sitting 
// after the eliminated person picking up the  hot potato. 
// The last remaining person wins.

//Thus, if M = 0 and N = 5,   players are eliminated in order, and player 5 wins. 
// If M = 1 and N =  5, the order of elimination is 2, 4, 1, 5.  
// Write a program that solves the Josephus problem for any input values of M and N.    
// Try  to make your program as efficient as possible if you used a a list,  stack, or queue in this problem.

//Note: I am aware that there is a closed form solution of this problem that can give you an answer in a single computation.   
//In this case, I'm wanting you get some more practice using lists and queues.

//Write a function that,  given an argument of the number of players, solves the Josephus problem for that many players.