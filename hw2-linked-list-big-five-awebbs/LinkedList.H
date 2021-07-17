/*
 *    LinkedList.h - implements a LinkedList ADT
 *
 *    Contributors:
 *      Adam Carter : Initial creator
 *      Aaron S. Crandall <acrandal@wsu.edu>
 *       Copyright 2017 - Instructional use only
       Amber Paige Webber : Student Project
 *
 *  LL class designed to implement the C++11 BigFive
 *  These interfaces are explicitly coded for instruction
 *
 */

#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <stdexcept>
#include <initializer_list>
#include <utility>
#include <iostream>

#include "Indexed.h"
#include "ListNode.h"

using namespace std;


/** ***************************************************************************
 *  Main LinkedList class
 */
template <typename T>
class LinkedList : public Indexed < T >
{

// ****************************************************************************
// Member variable declarations
private:

    ListNode<T> *_front = nullptr;              // Head of list pointer
    ListNode<T> *_end = nullptr;                // End of list pointer
    int _size = 0;                              // Running count of nodes in list

    int _last_accessed_index = 0;               // Tracking accesses for some functions
    ListNode<T> *_last_accessed_node = nullptr; // Tracking last accessed node for copies

    bool _debug = false;                        // debug_on() debug_off() - cout output control


// ****************************************************************************
// Constructors and initializer zone
public:

    // Basic Linked List constructor
    //  Other initializers are done at the class level
    LinkedList()
    {
        _front = nullptr;
        _end = _front;
        _debug = false;     // Default is no detailed out - see debug_on()
    }

// **************************************************************************//
// START Microassigment zone - all code you need to change is here

    // Copy constructor
    //  MA TODO: Implement!
    LinkedList(const LinkedList<T> &other) 
    {

        // Copy every element in other to ourselves
	ListNode<T> *copy_List = other._front;
	while(copy_List != nullptr)
	{
		addElement(copy_List->getValue());
		copy_List = copy_List->getNext();
	}
	
        cout << " [x] Copy Constructor executed. " << endl;
    }


    // Move constructor
    //  MA TODO: Implement!
    LinkedList(LinkedList<T> &&other) noexcept : _front(nullptr), _end(nullptr), _size(0)
    {
        cout << " [x] Move Constructor executed. " << endl;
        // Copy the pointers within other to ourselves
        //  Also copy their class varibles (_last_accessed_index, etc)
	_size = other._size;
	other._size = 0;
	_front = other._front;
	other._front = nullptr;
	_end = other._end;
	other._end = nullptr;
       
    }


    // Initializer list constructor
    // std::initializer_list documentation: https://en.cppreference.com/w/cpp/utility/initializer_list
    //  MA TODO: Implement!

    LinkedList(initializer_list<T> values) 
    {
        cout << " [x] Initializer List Constructor executed. " << endl;
        // Add a copy of every element in values to ourselves

	_size = 0;
	_front = nullptr;
	_end = nullptr;
	for(auto item : values) {
		addElement(item);
	}		

    }


    // Destructor: Always remeber to clean up pointers in destructor!
    //  MA TODO: Implement!
    virtual ~LinkedList()
    {
    
        if( _debug ) {
            cout << "  [x] LinkedList Destructor executed. " << endl;
        }
        // Delete every node in our internal linked list
	ListNode<T> *_delete_This_Node = _front;
        while(_delete_This_Node != nullptr)
        {
		ListNode<T> *temp = _delete_This_Node->getNext();
		delete _delete_This_Node;
		_delete_This_Node = temp;    
        }
        
       _size = 0;
       _front = nullptr;
       _end = nullptr;
    }


    // Copy assignment operator
    //  MA TODO: Implement!
    virtual LinkedList<T> &operator=(const LinkedList<T> &other)
    {
        cout << " [x] Copy *assignment* operator called. " << endl;
        // Note: might want to make sure we don't copy ourselves!
        // Delete our own elements
        // COPY their data for ourselves
        
	if(&other != this) {

		ListNode<T> *copy_List = other._front;
	 	while(copy_List != nullptr) {
			addElement(copy_List->getValue());
			copy_List = copy_List->getNext();
		}
	}
        // The operators must return a dereferenced value of this object
        return *this;
      
    }


    // Move assignment operator
    //  MA TODO: Implement!
    virtual LinkedList<T> &operator=(LinkedList<T> &&other)
    {
        cout << " [x] Move *assignment* operator called. " << endl;
        // Delete our own elements
        // Grab other data for ourselves
        // Reset their pointers to nullptr
        swap(_front, other._front);
        swap(_end, other._end);
        swap(_size, other._size);
        swap(_last_accessed_index, other._last_accessed_index);
        swap(_last_accessed_node, other._last_accessed_node);

        return *this;
        // The operators must return a dereferenced value of this object
 
    }



//***************************************************************************//
// End Microassignment zone - Sections below are complete LL APIs
//***************************************************************************//


//*****************************************************************************
// List internal pointer manipulation interfaces
//  Protected so we can inherit and do testing with them
//*****************************************************************************
protected:
    // Returns last node in Linked List
    ListNode<T> *getEnd()
    {
        return _end;
    }

    // Creates a new node (effectively a Factory interface)
    virtual ListNode<T> *createNode(T value)
    {
        return new ListNode < T > { value };
    }

    // Wrapped method to properly delete a passed in node
    virtual void deleteNode(ListNode<T> *node)
    {
        delete node;
    }

    // Can be used to return a ListNode<T> at a specific index.
    ListNode<T> *getNodeAtIndex(int index)
    {
        // Check to see if index is valid
        if (index < 0 || index >= getSize())
        {
            throw out_of_range("Invalid index.");
        }

        // Which is closer: last accessed, the end, or the front?
        int counter = 0;
        ListNode<T> *starting_node = _front;
        if (index >= _last_accessed_index && _last_accessed_node != nullptr)
        {
            starting_node = _last_accessed_node;
            counter = _last_accessed_index;
        }
        if (index == _size - 1)
        {
            starting_node = _end;
            counter = _size - 1;
        }

        // Keeps track of where we're at in our LL
        ListNode<T> *current = starting_node;
        while (counter < index && current != nullptr)
        {
            current = current->getNext();
            counter++;
        }

        _last_accessed_index = index;
        _last_accessed_node = current;

        // Return desired node
        return current;
    }

    // Note: cannot set last indexed node in const version of the above code
    const ListNode<T> *getNodeAtIndex(int index) const
    {
        // Check to see if index is valid
        if (index < 0 || index >= getSize())
        {
            throw out_of_range("Invalid index.");
        }

        // Which is closer: last accessed, the end, or the front?
        int counter = 0;
        ListNode<T> *starting_node = _front;
        if (index >= _last_accessed_index && _last_accessed_node != nullptr)
        {
            starting_node = _last_accessed_node;
            counter = _last_accessed_index;
        }
        if (index == _size - 1)
        {
            starting_node = _end;
            counter = _size - 1;
        }

        // Keeps track of where we're at in our LL
        ListNode<T> *current = starting_node;
        while (counter < index && current != nullptr)
        {
            current = current->getNext();
            counter++;
        }

        return current;
    }


// ************************************************************************* //
// ** General Linked List Public API *************************************** //
// ************************************************************************* //
public:
    // Interfaces to set debugging
    void debug_off()
        { _debug = false; }
    void debug_on()
        { _debug = true; }

    // Returns pointer to front of list - THIS IS DANGEROUS
    // Should be protected:, but I need it here for testing the destructor
    // To fix this, I should inherit from LinkedList and create this interface for testing
    ListNode<T> *getFront() const
    {
        return _front;
    }

    // Will return true if the LL is empty.
    virtual bool isEmpty() const
    {
        return _size == 0;
    }

    // Returns the size of the LL.
    virtual int getSize() const
    {
        return _size;
    }

    // Appends the supplied item to the end of our LL
    virtual void addElement(T value)
    {
        addElementAt(value, getSize());
    }


    // Returns the value at the specified index
    virtual T& getElementAt(int location)
    {
        //explicit way
        //ListNode<T> *result = getNodeAtIndex(location);
        //return result->getValue();

        //shortcut
        //this is called "method chaining" and can go on forever:
        //getNodeAtIndex(location)->getNext()->getNext()->getNext()
        //usually, not the best idea
        return getNodeAtIndex(location)->getValue();
    }


    // Returns a reference to the element at a given index/location
    virtual const T &getElementAt(int location) const
    {
        return getNodeAtIndex(location)->getValue();
    }


    // Sets the value at the specified index
    virtual void setElementAt(T value, int location)
    {
        getNodeAtIndex(location)->setValue(value);
    }


    // Inserts the specified value in a new Node at the specified index and 
    //  shifts everything else to the "right" by one.
    virtual void addElementAt(T value, int location)
    {
        ListNode<T> *new_value = createNode(value);

        // When adding to a LL, we have to consider three possibilities:
        //  Option #1: are we adding this to the front
        if (location == 0)
        {
            new_value->setNext(_front);
            _front = new_value;
        }
        else if (location == _size)
        {
            // Option #2: Adding to the end of the list
            _end->setNext(new_value);
            _end = _end->getNext();
        }
        else
        {
            // Option #3: Adding somewhere else
            ListNode<T> *before = getNodeAtIndex(location - 1);
            new_value->setNext(before->getNext());
            before->setNext(new_value);
        }

        if (_size == 0)      // Is size 0? -> set end to front
        {
            _end = _front;
        }

        _size++;             // Remember to increment size counter

    }


    // Removes the element at the specified index.
    virtual void removeElementAt(int index)
    {
        // Make sure index is in bounds
        if (index < 0 || index >= getSize())
        {
            throw out_of_range("Invalid index.");
        }

        // Two possibilities:
        //  1) Index is 0 (first item in LL)
        if (index == 0)
        {
            ListNode<T> *old_front = _front;
            _front = _front->getNext();
            deleteNode(old_front);
        }
        else
        {
            // 2) Index is greater than 0 (not the first item in LL)
            ListNode<T> *before = getNodeAtIndex(index - 1);
            ListNode<T> *to_delete = before->getNext();
            before->setNext(to_delete->getNext());
            deleteNode(to_delete);

            // Check to see if we removed the last element
            if (index == _size - 1)
            {
                _end = before;
            }
        }

        if (_size == 1)       // Is our size 1?
        {
            _end = _front;
        }

        _size--;              // Remember to decrement size
    }

};  // End of LinkedList class

#endif // !LINKED_LIST_H
