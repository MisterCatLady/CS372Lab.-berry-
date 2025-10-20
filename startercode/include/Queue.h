#include "List.h"
template<typename T>
class Queue: public List
{
private: 
	List<T> queueList;
public:
	Queue(): List() {}
	Queue(Queue &rhs): List(rhs){}
	~Queue();

	bool empty() { return queueList.empty(); }
	void push(T data) { queueList.push_front(data); }
	T front() { return queueList.front(); }
	T back() { return queueList.back(); }
	void pop() { queueList.pop_back(); }
};

