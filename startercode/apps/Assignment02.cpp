//lberry4@my.athens.edu
//Assignment02.cpp
//This is still incomplete but I think I made a breakthrough today. 

#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
//Question 1: Creating a Vector
// Write a program that uses your Vector class and the chrono library to determine the size of the problem. 
// Add progressively larger numbers of integers to an instance of your vector class 
// increasing in size by powers of two (2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, …). 
// Time, in milliseconds, how long it takes to add these elements to the underlying dynamic array 
// that is keeping the data inside the object (following the pattern we used to time the Towers of Hanoi).
template <typename T>
class Vector
{
public:
	Vector()
	{
		arr new T[1];
		vCapacity = 1;
		length = 0;
	}
	~Vector()
	{
		delete[] arr;
		arr = nullptr;
	}
	//copy constructor
	Vector(Vector& obj)
	{
		this->arr = new T[obj.capacity()];
		for (int i = 0; i < obj.size(); i++) { this->put(i, obj.at(i)); }
	}
	//assignment operator
	bool operator==(Vector& other) const
	{
		if (other.size() != length) { return false; }
		else 
		{
			for (int i = 0; i < length; i++)
			{
				if (arr[i] != other.get(i))
				{
					return false;
				}
			}
		}
		return true;
	}
	T& operator[](int i)
	{
		if ((i < 0) || (i >= length))
		{
			std::cerr << std::endl << "Vector index out of bounds" << std::endl;
		}
		return at(i);
	}
	Vector& operator=(const Vector& source)
	{
		if (this == &source) { return *this; }
		delete[] arr;
		arr = newT[1];
		vCapacity = 1;
		length = 1;
		for (int i = 0; i < source.size(); i++) { push_back(source.at(i)); }
		return *this;
	}
	void push_back()
	{
		if (length == vCapacity) { expand(2 * vCapacity); }
		arr[length] = data;
		length++;
	}
	void vector::put(T data, int pos)
	{
		if (index == vCapacity) { push_back(T data); }
		else { arr[index] = data; }
	}
	void traverse()
	{
		for (int i = 0; i < length; i++) { cout << arr[i] << endl; }
		cout << endl;
	}
	T& at(int index)
	{
		if (index < 0 || index > length)
		{
			std::cerr << "Vector: index out of bounds on access" << std::endl;
			exit(1);
		}
		else { return arr[index]; }
	}
	int size()
	{
		return length;
	}
	int capacity()
	{
		return vCapacity;
	}

private:
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 0;

	void expand(int newCapacity)
	{
		if (newCapacity > vCapacity)
		{
			T* temp = new T[newCapacity];
			for (int i = 0; i < length; i++) { temp[i] = arr[i]; }
			delete[] arr;
			vCapacity = newCapacity;
			arr = temp;
		}
		else
		{
			std::cerr << "vector::expand: new capacity is less than equal to current\n";
		}
	}
};
//Then try the following by defining subclasses of Vector that use polymorphism to override the capacity method
// of the base class.In the first case, replace the for - loop with a call to the STL copy algorithm.
// In the second case, override the capacity method with a new version that starts the doubling process with 
// larger values(say start at 128 and increase the size of the new array by 4 rather than 2).
// Report the times required for each of these changes.

//HINT: If you take advantage of polymorphism correctly, you will not have to make any major changes in your 
// timing program to use the derived classes.
class VecTester
{
private:
	Vector<int> testVector;
	void fillVector(size_t cap)
	{
		for (int i = 0; i < cap; ++i) { testVector[i]; }
	}
public:
	size_t oldCap = testVector.capacity();
};

int main()
{

	return 0;

}


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
//recursive function initialization
