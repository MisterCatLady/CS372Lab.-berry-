#pragma once
#include "C:\Users\Lindsey\Desktop\CS318\CS372Lab.-berry-\startercode\include\List.h"
#include <iostream>
#include <functional>
//We need a “circular list”, where such a thing differs from a regular 
// list in that attempts to traverse the list will return you back to the front of the list and continue. 
//This can be built by inheriting from your existing list class.
template <typename T>
class CircularList : public List<T>
{
public:
    CircularList() : List<T>() {}

    // Copy constructor
    CircularList(const CircularList<T>& rhs) : List<T>(rhs) {}

    // Move constructor
    CircularList(CircularList<T>&& rhs) noexcept : List<T>(std::move(rhs)) {}

    // Copy assignment
    CircularList<T>& operator=(const CircularList<T>& rhs)
    {
        List<T>::operator=(rhs);
        return *this;
    }

    // Move assignment
    CircularList<T>& operator=(CircularList<T>&& rhs) noexcept
    {
        List<T>::operator=(std::move(rhs));
        return *this;
    }
    //destructor
    virtual ~CircularList() = default;
//You’ll need a starting point in the list (an additional parameter to the traverse) and then the traverse will stop when you get back to the starting point. 
//Your submission will need to document how you interpret the different requirements, document what you need to override + what needs to change (if anything) 
//in the base class in your design, and provide the new class and test code for your work.
    void traverse(std::function<void(T&)> doIt, typename List<T>::iterator start)
    {
        if (this->empty())
        {
            std::cout << "(List is empty)" << std::endl;
            return;
        }

        auto current = start;
        do
        {
            doIt(*current);
            ++current;
            if (current == this->end()) 
                current = this->begin();
        } while (current != start);
    }

    void printCircular(typename List<T>::iterator start)
    {
        traverse([](T& val) { std::cout << val << " "; }, start);
        std::cout << std::endl;
    }
};