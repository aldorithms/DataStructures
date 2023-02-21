// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Header.h"
#include "Header1.h"

using namespace std;

void userMenu() {
	int n1 = 0, b = 0, l1, l2, l3;
	double n2 = 0;
	char n3 = 0;

	cout << "Your turn. Choose the data type for your array-based queue:\n1. int\n2. double\n3. char\n\n>> ";
	cin >> b;

	if (b == 1) {
		AQueue<int> Q1(10);
		cout << "Input data elements (-1 to end)." << endl;
		while (true) {
			cin >> n1;
			if (n1 != -1) {
				Q1.enqueue(n1);
			}
			else
				break;
		}
		l1 = Q1.length();
		cout << endl << "Queue is of length " << Q1.length() << ". Starting from the front to the rear, the elements are listed as follows: " << endl << "< ";
		for (int i = 0; i < l1; i++) {
			cout << Q1.frontValue() << " ";
			Q1.dequeue();
		}
		cout << ">" << endl;
		Q1.clear();
		cout << endl << "Queue has been cleared and is of length " << Q1.length() << ". Retrieving elements results in..." << endl;
		if (Q1.length() == 0)
			cout << "Queue is empty." << endl;
	}
	else if (b == 2) {
		AQueue<double> Q2(10);
		cout << "Input data elements (-1 to end)." << endl;
		while (true) {
			cin >> n2;
			if (n2 != -1) {
				Q2.enqueue(n2);
			}
			else
				break;
		}
		l2 = Q2.length();
		cout << endl << "Queue is of length " << Q2.length() << ". Starting from the front to the rear, the elements are listed as follows: " << endl << "< ";
		for (int i = 0; i < l2; i++) {
			cout << Q2.frontValue() << " ";
			Q2.dequeue();
		}
		cout << ">" << endl;
		Q2.clear();
		cout << endl << "Queue has been cleared and is of length " << Q2.length() << ". Retrieving elements results in..." << endl;
		if (Q2.length() == 0)
			cout << "Queue is empty." << endl;
	}
	else if (b == 3) {
		AQueue<char> Q3(10);
		cout << "Input data elements (-1 to end)." << endl;
		while (true) {
			cin >> n3;
			if (n3 != -1) {
				Q3.enqueue(n3);
			}
			else
				break;
		}
		l3 = Q3.length();
		cout << endl << "Queue is of length " << Q3.length() << ". Starting from the front to the rear, the elements are listed as follows: " << endl << "< ";
		for (int i = 0; i < l3; i++) {
			cout << Q3.frontValue() << " ";
			Q3.dequeue();
		}
		cout << ">" << endl;
		Q3.clear();
		cout << endl << "Queue has been cleared and is of length " << Q3.length() << ". Retrieving elements results in..." << endl;
		if (Q3.length() == 0)
			cout << "Queue is empty." << endl;
	}
}



int main()
{
	AQueue<int> Q(10), Q1(8);
	AQueue<double> Q2(8);
	AQueue<char> Q3(8);

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < 10; i++)
		Q.enqueue(arr[i]);

	cout << "This is the demo of an array-based queue- Q1. Queue is of length " << Q.length() << "." << endl;
	cout << "Starting from the front to the rear, they are listed as follows: " << endl << "< ";
	for (int i = 0; i < 10; i++) {
		cout << Q.frontValue() << " ";
		Q.dequeue();
	}
	cout << ">" << endl;

	userMenu();

	system("pause");
	return 0;

}





