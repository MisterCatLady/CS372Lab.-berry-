//lberry4@my.athens.edu
//Assignment02.cpp
//Purpose: Hi this is essentially a blank solution currently. 
//I have a handful of excuses but I understand if my earned credit is affected.
//If this message does not change, know that I am more disappointed in myself than you could ever be.

#include <vector>
#include <iostream>
//Question 1: Creating a Vector
// Write a program that uses your Vector class and the chrono library to determine the size of the problem. 
// Add progressively larger numbers of integers to an instance of your vector class 
// increasing in size by powers of two (2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, …). 
// Time, in milliseconds, how long it takes to add these elements to the underlying dynamic array 
// that is keeping the data inside the object (following the pattern we used to time the Towers of Hanoi).

//Then try the following by defining subclasses of Vector that use polymorphism to override the capacity method
// of the base class.In the first case, replace the for - loop with a call to the STL copy algorithm.
// In the second case, override the capacity method with a new version that starts the doubling process with 
// larger values(say start at 128 and increase the size of the new array by 4 rather than 2).
// Report the times required for each of these changes.

//HINT: If you take advantage of polymorphism correctly, you will not have to make any major changes in your 
// timing program to use the derived classes.

//Question 2: A better array
//The STL provides an Array template class that is just a wrapper around the base C++ array data type. Why? 
// Twofold, cohesion and type safety. The Cohesion Principle is a software design principle that refers 
// to the degree in which the elements inside a module belong together. Having an Array class as a companion to 
// Vector increases cohesion in the library. For type safety, wrapping the base C++ array type in a class allows 
// one to avoid the type safety issues with arrays.

//Add an Array template class to your class library.Use the same convention as the STL and parameterize the your 
// Array class by the data type stored and size of the Array.The public interface for this class should be the 
// same as the Vector class, including the array index operator (without adding any of the Vector member functions 
// specific to that class).Modify the constructors to include a size_t parameter that specifies the size of the array.

//Question 3: Bags with Receipts
//Suppose we adjust the definition of the Bag class to implement a bag with receipts. 
//This bag operates in the same matter as with regular bags except the insert function returns a unique integer 
// known as a receipt. On deletion, you must pass the remove function a copy of this receipt. 
// The function removes the item matching the receipt and returns a reference to the removed item. 
//Implement the ReceiptBag class, with appropriate test scripts, in your library that implements this ADT

//(HINTS: (1) think about using parallel arrays or vectors, 
//		(2) you will need to determine what to do when you pull something from the bag, 
//		(3) This needs to be a separate class than the existing Bag class, don’t modify the existing class to do this,
//		(4) You can do this with a dictionary object like the STL map class, but let’s assume you don’t have that available.)