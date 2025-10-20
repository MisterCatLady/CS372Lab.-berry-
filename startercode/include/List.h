

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
		setupList();
	}
	List(T newData)		// constructor
	{
		setupList();
		head->data = newData;
	}
	List(List& rhs)		//copy constructor
	{
		deleteListContents();
		
		head = rhs.head;
		tail = rhs.tail;
	}
	~List()		//destructor
	{
		deleteListContents();
	}
	bool empty();
	void push_front(T data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = head;
		newNode->prev = nullptr;
		head = newNode;
	}
	void push_back(T data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = tail;
		tail = newNode;
	}
	T front() { return(head->data); }
	T back() { return(tail->data); }
	void pop_back()
	{
		Node* lastNode = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete lastNode;
	}
	void pop_front()
	{
		Node* firstNode = head;
		head = head->next;
		head->prev = nullptr;
		delete firstNode;
	}
	void printTheList()
	{
		Node* current = head;
		while (current != tail) { std::cout << current->data << " "; }
		std::cout << std::endl;
	}
	void traverse(function<void(T &)>(doIt));
};