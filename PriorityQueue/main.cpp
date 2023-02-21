#include "PriorityQueue.h"
#include <iostream>
#include "book.h"

using namespace std;

int main() {
	cout << "Priority Queue\n";
	cout << "This program implements a priority queue using max heap.\n";
	cout << "List data is as follows: { 12, 22, 32, 45, 99, 8, 44, 65, 20, 72, 80, 68, 57, 55, 7 }" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Sifting by highest priority" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	Int objectID[200] = { 12 };
	Int priority[200] = { 1 };
	PriorityQueue<Int, maxIntCompare> queue(objectID, 1, 100, priority);

	queue.enqueue(22, 2);
	queue.enqueue(32, 3);
	queue.enqueue(45, 4);
	queue.enqueue(99, 5);
	queue.enqueue(8, 6);
	queue.enqueue(44, 7);
	queue.enqueue(65, 8);
	queue.enqueue(20, 9);
	queue.enqueue(72, 10);
	queue.enqueue(80, 11);
	queue.enqueue(68, 12);
	queue.enqueue(57, 13);
	queue.enqueue(55, 14);
	queue.enqueue(7, 15);
	queue.printObjectID();
	queue.printPriority();
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Dequeueing the highest priority\n";
	cout << "------------------------------------------------------------------------------------------" << endl;
	queue.dequeue();
	queue.printObjectID();
	queue.printPriority();
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Dequeueing the highest priority\n";
	cout << "------------------------------------------------------------------------------------------" << endl;
	queue.dequeue();
	queue.printObjectID();
	queue.printPriority();
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Dequeueing the highest priority\n";
	cout << "------------------------------------------------------------------------------------------" << endl;
	queue.dequeue();
	queue.printObjectID();
	queue.printPriority();
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Clearing queue...\n";
	cout << "------------------------------------------------------------------------------------------" << endl;
	queue.clear();
	queue.printObjectID();
	queue.printPriority();
	cout << endl;

	system("pause");
	return 0;
}
