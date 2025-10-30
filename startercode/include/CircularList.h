// File:   CicrularList.h
// Author: Dr Adam Lewis
// Purpose:
// Build a cicuular list using the classic double linked version of a linked list.
//
#pragma once
#include <iostream>
#include <functional>
template <typename T>
class CircularList: public List<T>
{
private:
    class Node 
    {
    public:
        T  data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    void setupList() {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    void deleteListContents() {
        Node* temp = nullptr;
        Node* current = head;
        while (current != tail) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }
public:
    CircularList() : List<T> {} //default constructor

    CircularList(T newData) : List<T> {} //parameterized constructor

    CircularList(const CircularList<T>& rhs) : List<T>(rhs) {} // copy constructor

    CircularList(CircularList<T>&& rhs) noexcept : List<T>(std::move(rhs)) {} //move constructor

    CircularList<T>& operator=(const CircularList<T>& rhs)  // Copy assignment
    {
        List<T>::operator=(rhs);
        return *this;
    }

    CircularList<T>& operator=(CircularList<T>&& rhs) noexcept     // Move assignment
    {
        List<T>::operator=(std::move(rhs));
        return *this;
    }

    virtual ~CircularList() = default; //destructor

//We inherit public functions from List<> but we need to override traverse()
    //Chatgpt helped me write this
    void traverse(std::function<void(T&)> doIt, typename List<T>::iterator start)
    {
        if (this->empty() || start == this->end())
        {
            std::cout << "(List is empty or invalid start)" << std::endl;
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
};




