template <typename T>
class List 
{
private:
	class Node
	{
		public T data;
		Node* prev;
		Node* next;
		bool isHiddenNode = false;
	};
	Node* head;
	Node* tail;
public:
	class const_iterator
	{
	protected:
		Node* current;
		T& retrieve() const { return current->data;}
		const_iterator(Node *p): current(p){}
		friend class List<T>;
	public:
		const_iterator(): current(nullptr) {}

		virtual const T& operator*() const
		{
			return retrieve();
		}
		const_iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		const_iterator& operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		bool operator==(const const_iterator& rhs) const { return current == rhs.current; }
		bool operator!=(const const_iterator& rhs) const { return !(*this == rhs); }
	};
public:
	class iterator : public const_iterator
	{
	protected:
		iterator(Node *p): const_iterator(p) {}
		friend class List<T>;

	public:
		T& operator*() { return const_iterator::retrieve(); }
		iterator& operator++()
		{
			this->current = const_iterator::current->next;
			return *this;
		}
		iterator& operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
	};
private:
	void setupList()
	{
		Node* newNode = new Node();
		newNode->next = nullptr;
		newNode->prev = nullptr;
		head = newNode;
		tail = newNode;
	}
	void deleteListContents()
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr)
		{
			temp = current.next;
			delete current;
			current = temp;
		}
	}
public:
	List()		//default constructor
	{
		head = newNode();
		head->isHiddenNode = true;
		tail = new Node();
		tail->isHiddenNode = true;
		head->prev = nullptr;
		head->next = tail;
		tail->prev = head;
		tail->next = nullptr;
	}
	List(T newData)		
	{
		setupList();
		(head->next)->data = newData;
	}
	List(const List& rhs): List()		//copy constructor
	{
		for (Node* curr = rhs.head->next; curr != rhs.tail; curr = curr->next) 
		{ push_back(curr->data); }
	}
	List& operator=(const List& rhs) // assignment operator
	{
		if (this != &rhs)
		{
			deleteListContents();
			head = rhs.head;
			tail = rhs.tail;
			rhs.head = nullptr;
			rhs.tail = nullptr;
		}
		return *this;
	}
	List(List&& rhs) //move constructor
	{
		deleteListContents();
		head = rhs.head;
		tail = rhs.tail;
		rhs.head = nullptr;
		rhs.tail = nullptr;
	}
	List& operator=(List&& rhs) //move assignment operator
	{
		if (this != &rhs)
		{
			deleteListContents();
			head = rhs.head;
			tail = rhs.tail;
			rhs.head = nullptr;
			rhs.tail = nullptr;
		}
		return *this;
	}
	virtual ~List()  //destructor	
	{
		deleteListContents();
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	bool empty() const { return (head->next == tail); }
	//iterator related methods
	iterator begin() const { return iterator{ head->next }; }
	iterator end() const { return iterator{ tail }; }
	iterator cbegin() const { return iterator{ head->next }; }
	iterator cend() const { return iterator{ tail }; }
	iterator insert(iterator itr, const T& x)
	{
		Node* p = itr.current;
		Node* newNode = new Node{ x, p->prev, p };
		p->prev = p->prev->next = newNode;
		return iterator{ newNode };
	}
	iterator erase(iterator itr)
	{
		Node* p = itr.current;
		Node* iterToReturn{ p->next };
		p->prev->next = p->next;
		p->next->prev = p->prev;

	}
	void push_front(T data)
	{
		if (this->empty())
		{
			setUpList();
			Node* actualHead = head->next;
			actualHead->data = data;
		}
		else
		{
			Node* actualHead = head->next;
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = actualHead;
			actualHead->prev = newNode;
			newNode->prev = head;
			head->next = newNode;
		}
	}
	void push_back(T data)
	{
		if (this->empty())
		{
			setUpList();
			Node* actualTail = tail->prev;
			actualHead->data = data;
		}
		else
		{
			Node* actualTail = tail->prev;
			Node* newNode = new Node();
			newNode->data = data;
			newNode->prev = actualTail;
			actualTail->next = newNode;
			newNode->next = tail;
			tail->prev = newNode;
		}
	}
	T front() 
	{ 
		Node* actualHead = head->next;
		return(actualHead->data); 
	}
	T back() 
	{ 
		Node* actualTail = tail->prev;
		return(actualTail->data); 
	}
	void pop_back()
	{
		if (!empty())
		{
			Node* lastNode = tail->prev;
			tail->prev = lastNode->prev;
			Node* newLastNode = tail->prev;
			newLastNode->next = tail;
			delete lastNode;
			lastNode = nullptr;
		}
		else { std::cerr << "pop_back(): Attempt to pop from empty list" << std::endl; }
	}
	void pop_front()
	{
		if (!empty())
		{
			Node* firstNode = head->next;
			head->next = firstNode.next;
			Node* newFirstNode = head.next;
			newFirstNode.prev = head;
			delete firstNode;
			firstNode = nullptr;
		}
		else { std::cerr << "pop_front(): Attempt to pop from empty list" << std::endl; }
	}
	void printTheList()
	{
		Node* current = head;
		while (current != tail) { std::cout << current->data << " "; }
		std::cout << std::endl;
	}
	void traverse(function<void(T&)>(doIt))
	{
		Node* current = head->next;
		while (current != tail)
		{
			doIt(current->data);
			current = current->next;
		}
	}
};