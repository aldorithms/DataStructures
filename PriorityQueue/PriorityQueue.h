#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "book.h"
#include "compare.h"

template< typename E, typename Comp> class PriorityQueue {
private:
	E*objectID;
	E*priority;
	int totalElements;
	int maxsize;

	void bubbleDown(int pos)
	{
		while (!isLeaf(pos))
		{
			int left = leftChild(pos);
			int right = rightChild(pos);
			if ((right < totalElements) && Comp::prior(objectID[right], objectID[left]))
				left = right;
			if (Comp::prior(objectID[pos], objectID[left])) return;
			swap(objectID, pos, left);
			swap(priority, pos, left);
			pos = left;
		}
	}

public:
	PriorityQueue(E * val, int num, int size, E* it)
	{
		objectID = val;
		totalElements = num;
		maxsize = size;
		priority = it;
	}
	int size() const
	{
		return totalElements;
	}
	bool isLeaf(int pos) const
	{
		return (pos >= totalElements / 2) && (pos < totalElements);
	}
	int leftChild(int pos) const
	{
		return 2 * pos + 1;
	}
	int rightChild(int pos) const
	{
		return 2 * pos + 2;
	}
	int parent(int pos) const
	{
		return (pos - 1) / 2;
	}
	void priorityBuild()
	{
		for (int i = totalElements / 2 - 1; i >= 0; i--) bubbleDown(i);
	}
	void clear() {
		objectID = 0;
		priority = 0;
		maxsize = 0;
		totalElements = 0;
	}
	void enqueue(const E& val, const E& it)
	{
		Assert(totalElements < maxsize, "Heap is full");
		int curr = totalElements++;
		objectID[curr] = val;
		priority[curr] = it;
		while ((curr != 0) && (Comp::prior(objectID[curr], objectID[parent(curr)])))
		{
			swap(objectID, curr, parent(curr));
			swap(priority, curr, parent(curr));
			curr = parent(curr);
		}
	}

	E dequeue()
	{
		Assert(totalElements > 0, "Heap is empty");
		swap(objectID, 0, --totalElements);
		if (totalElements != 0) bubbleDown(0);
		return objectID[totalElements];
	}

	void printObjectID()
	{
		int numToPrint = 1;
		int alreadyPrinted = 0;  // Count number of elements have been printed at this level 
		cout << "ObjectID Level by level: " << endl;
		for (int i = 0; i < size(); i++) {
			cout << objectID[i] << " ";
			alreadyPrinted++;

			if (alreadyPrinted == numToPrint) {
				cout << endl;
				numToPrint = numToPrint << 1;  // Double elements to print on next level
				alreadyPrinted = 0;  // Clear counter 
			}
		}
		cout << endl;
	}
	void printPriority() {
		int numToPrint = 1;
		int alreadyPrinted = 0;  // Count number of elements have been printed at this level 
		cout << "Prioriy level by level: " << endl;
		for (int i = 0; i < size(); i++) {
			cout << priority[i] << " ";
			alreadyPrinted++;

			if (alreadyPrinted == numToPrint) {
				cout << endl;
				numToPrint = numToPrint << 1;  // Double elements to print on next level
				alreadyPrinted = 0;  // Clear counter 
			}
		}
		cout << endl;
	}

};
#endif // !PRIORITYQUEUE_H
