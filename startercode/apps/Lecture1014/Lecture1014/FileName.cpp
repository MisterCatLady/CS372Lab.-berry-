#include <memory>
#include <functional>
#include <cassert>
#include <initializer_list>

template<typename T>
class Tree
{
	struct Node
	{
		Node(std::shared_ptr<const Node> lft, 
			 T val, 
			 std::shared_ptr<const Node> rgt): _lft(lft),_val(val), _rgt(rgt){}

		std::shared_ptr<const Node>;
	};
};