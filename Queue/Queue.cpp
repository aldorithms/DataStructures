#pragma once
# include "stdafx.h"
# include <assert.h>
# include "Header1.h"
# include <iostream>

using namespace std;
// Array-based queue implementation 4.26
template <typename E> class AQueue : public Queue<E> {
private:
	int maxSize; // Maximum size of queue
	int front; // Index of front element
	int rear; // Index of rear element
	E *listArray; // Array holding queue elements
public:
	AQueue(int size = 10) { // Constructor
							// Make list array one position larger for empty slot
		maxSize = size + 1;
		rear = 0; front = 1;
		listArray = new E[maxSize];
	}
	~AQueue() { delete[] listArray; } // Destructor
	void clear() { rear = 0; front = 1; } // Reinitialize
	void enqueue(const E& it) { // Put "it" in queue
		assert(((rear + 2) % maxSize) != front, "Queue is full");
		rear = (rear + 1) % maxSize; // Circular increment
		listArray[rear] = it;
	}
	E dequeue() { // Take element out
		assert(length() != 0, "Queue is empty");
		E it = listArray[front];
		front = (front + 1) % maxSize; // Circular increment
		return it;
	}
	const E& frontValue() const { // Get front value
		assert(length() != 0, "Queue is empty");
		return listArray[front];
	}
	virtual int length() const // Return length
	{
		return ((rear + maxSize) - front + 1) % maxSize;
	}
};