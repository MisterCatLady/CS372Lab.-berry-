#include "List.h"
template<typename T>
class Stack 
{
private:
	List<T> stackList;
public:
	Stack() {}
	Stack(Stack &rhs) {}
	~Stack(){}

	bool empty() { return stackList.empty(); }
	void push(T data) { stackList.push_front(data); }
	T front() { return stackList.front(); }
	T back() { return stackList.back(); }
	
};