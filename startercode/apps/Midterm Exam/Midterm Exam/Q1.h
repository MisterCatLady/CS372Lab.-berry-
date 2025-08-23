//lberry@my.athens.edu
//Midterm Exam: Programming Question 1
//Sources: cppreference.com, chatgpt.com
#pragma once
#include <functional>
#include <iostream>

template <typename T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node* prev{ nullptr };
		Node* next{ nullptr };
		bool isHiddenNode = false;
		bool isDeleted = false;
	};
	Node* head;
	Node* tail;

	int activeCount = 0;
	int deletedCount = 0;

	void cleanUp()
	{
		Node* current = head->next;
		while (current != tail)
		{
			Node* nextNode = current->next;
			if (current->isDeleted)
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
				delete current;
				deletedCount--;
			}
			current = nextNode;
		}
	}
	void lazyDelete(Node* node)
	{
		if (node == nullptr || node == head || node == tail || node->isDeleted)
			return;

		node->isDeleted = true;
		activeCount--;
		deletedCount++;

		if (deletedCount >= activeCount)
			cleanUp();
	}
	void resetEmpty()
	{
		head = new Node();
		head->isHiddenNode = true;
		tail = new Node();
		tail->isHiddenNode = true;
		head->next = tail;
		tail->prev = head;
		head->prev = nullptr;
		tail->next = nullptr;
		activeCount = 0;
		deletedCount = 0;
	}
public:
	//default constructors
	List()
	{
		//reinitialize rhs into an empty list
		resetEmpty();
	};

	List(T newData) : List()
	{
		push_back(newData);
	}
	//rule of 5
	List(const List& rhs) : List() // copy constructor
	{
		for (Node* curr = rhs.head->next; curr != rhs.tail; curr = curr->next)
		{
			if (!curr->isDeleted)
			{
				push_back(curr->data); 
			}
		}
	}

	List& operator=(const List& rhs) // assignment operator
	{
		if (this != &rhs)
		{
			//lazy delete
			Node* curr = head->next;
			while (curr != tail) {
				Node* next = curr->next;
				lazyDelete(curr);
				curr = next;
			}
			// copy from rhs
			for (Node* node = rhs.head->next; node != rhs.tail; node = node->next)
			{
				if (!node->isDeleted)
					push_back(node->data);
			}
		}
		return *this;
	}

	List(List&& rhs) //move constructor
	{
		head = rhs.head;
		tail = rhs.tail;
		//move values for lazy delete counters
		activeCount = rhs.activeCount;
		deletedCount = rhs.deletedCount;
		//reinitialize rhs into an empty list
		rhs.resetEmpty();
	}
	List& operator=(List&& rhs) //move assignment operator
	{
		if (this != &rhs)
		{
			//lazy delete
			Node* curr = head->next;
			while (curr != tail)
			{
				Node* nextNode = curr->next;  // save first
				lazyDelete(curr);
				curr = nextNode;
			}
			//ensure deletion of copied nodes
			cleanUp();
			delete head;
			delete tail;

			head = rhs.head;
			tail = rhs.tail;
			//copy values from prev location for counters
			activeCount = rhs.activeCount;
			deletedCount = rhs.deletedCount;
			//reinitialize rhs into an empty list
			resetEmpty();
		}
		return *this;
	}

	virtual ~List() //destructor
	{
		Node* curr = head->next;
		//lazy delete
		while (curr != tail)
		{
			Node* nextNode = curr->next; 
			lazyDelete(curr);
			curr = nextNode;
		}
		//ensure deletion of any missed nodes
		cleanUp();
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
	}

	bool empty() const
	{
		return (activeCount == 0);
	}

	void push_front(T data)
	{
		Node* first = head->next;
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = first;
		newNode->prev = head;
		head->next = newNode;
		first->prev = newNode;

		activeCount++;
	}

	void push_back(const T& data)
	{
		Node* beforeTail = tail->prev;
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = tail;
		newNode->prev = beforeTail;
		beforeTail->next = newNode;
		tail->prev = newNode;

		activeCount++;
	}
	T front()
	{
		if (empty()) throw std::runtime_error("List is empty");
		Node* curr = head->next;
		while (curr != tail && curr->isDeleted) curr = curr->next;
		return curr->data;
	}
	T back()
	{
		if (empty()) throw std::runtime_error("List is empty");
		Node* curr = tail->prev;
		while (curr != head && curr->isDeleted) curr = curr->prev;
		return curr->data;
	}
	void pop_back()
	{
		if (!empty())
		{
			lazyDelete(tail->prev);
		}
	}
	void pop_front()
	{
		if (!empty())
		{
			lazyDelete(head->next);
		}
	}
	void printTheList()
	{
		Node* current = head->next;
		while (current != tail)
		{
			if (!current->isDeleted)
				std::cout << current->data << " ";
			current = current->next;
		}
	}
	void traverse(void (*doIt)(T data))
	{
		Node* current = head->next;
		while (current != tail)
		{
			if (!current->isDeleted)
			{
				doIt(current->data);
			}
			current = current->next;
		}
	}
};
