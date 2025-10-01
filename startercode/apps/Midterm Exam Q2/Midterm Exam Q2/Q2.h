//lberry4@my.asu.edu
//Midterm Exam Question 2 header file
#include<iostream>
template <typename T>
class Vector
{
private:
	T* data;
	size_t numElem;
	size_t capacity;

	void resize(size_t newCapacity)
	{
		T* newData = new T[newCapacity];
		for (size_t i = 0; i < numElem; ++i)
			newData[i] = data[i];
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

public:
	//Constructors
	Vector():data(nullptr), numElem(0), capacity(0){}

	Vector(const Vector& rhs) :numElem(rhs.numElem), capacity(rhs.capacity)
	{
		data = new T[capacity];
		for (size_t i = 0; i < numElem; ++i)
			data[i] = rhs.data[i];
	}

	Vector(Vector&& rhs) noexcept : data(rhs.data), numElem(rhs.numElem), capacity(rhs.capacity)
	{
		rhs.data = nullptr;
		rhs.numElem = 0;
		rhs.capacity = 0;
	}
	//assignment operators
	Vector& operator=(const Vector& rhs) 
	{
		if (this != &rhs) 
		{
			delete[] data;
			numElem = rhs.numElem;
			capacity = rhs.capacity;
			data = new T[capacity];
			for (size_t i = 0; i < numElem; ++i)
				data[i] = rhs.data[i];
		}
		return *this;
	}

	Vector& operator=(Vector&& rhs) noexcept 
	{
		if (this != &rhs) {
			delete[] data;
			data = rhs.data;
			numElem = rhs.numElem;
			capacity = rhs.capacity;
			rhs.data = nullptr;
			rhs.numElem = 0;
			rhs.capacity = 0;
		}
		return *this;
	}
	//Destructor
	~Vector() 
	{
		delete[] data;
	}
	//Index Access
	T& operator[](size_t index) 
	{
		if (index >= numElem) std::cout << "Index out of range\n";
		return data[index];
	}

	const T& operator[](size_t index) const 
	{
		if (index >= numElem) std::cout << "Index out of range\n";
		return data[index];
	}

	T& front() { return data[0]; }
	T& back() { return data[numElem - 1]; }
	const T& front() const { return data[0]; }
	const T& back() const { return data[numElem - 1]; }

	//capacity
	size_t size() const { return numElem; }
	bool empty() const { return numElem == 0; }

	//Mutators
	void push_back(const T& value)
	{
		if (numElem == capacity) {
			resize(capacity == 0 ? 1 : capacity * 2);
		}
		data[numElem++] = value;
	}

	void pop_back()
	{
		if (numElem == 0) std::cout << "Vector is empty\n";
		--numElem;
	}
	void clear()
	{
		numElem = 0;
	}

	class iterator 
	{
		T* ptr;
	public:
		iterator(T* p) : ptr(p) {}
		T& operator*() { return *ptr; }
		iterator& operator++() { ++ptr; return *this; }
		iterator operator++(int) { iterator old = *this; ++ptr; return old; }
		bool operator==(const iterator& rhs) const { return ptr == rhs.ptr; }
		bool operator!=(const iterator& rhs) const { return ptr != rhs.ptr; }
	};
	iterator begin() { return iterator(data); }
	iterator end() { return iterator(data + numElem); }
};
