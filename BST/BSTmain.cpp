// Vik Sirivong, Dany Flores, Peter Huang, Aldo Avalos

/*
5.3 Implement a city database using a BST to store the database records. Each
database record contains the name of the city (a string of arbitrary length)
and the coordinates of the city expressed as integer x- and y-coordinates.
The BST should be organized by city name. Your database should allow
records to be inserted, deleted by name or coordinate, and searched by name
or coordinate. Another operation that should be supported is to print all
records within a given distance of a specified point. Collect running-time
statistics for each operation. Which operations can be implemented reasonably
efficiently (i.e., in (log n) time in the average case) using a BST? Can
the database system be made more efficient by using one or more additional
BSTs to organize the records by location?
*/

#include <iostream>
#include <string>
#include "book.h"
#include "BST.h"
using namespace std;

//  Simple object type (city) to store the data, such as city names and locations
class city {
private:
	int val;
	string cityName;
	int cityCoordX;
	int cityCoordY;
public:
	city(int key, string name, int X, int Y)
	{
		val = key;
		cityName = name;
		cityCoordX = X;
		cityCoordY = Y;
	}

	int key() const { return val; }
	string nameOfCity() const { return cityName; }
	int coordX() const { return cityCoordX; }
	int coordY() const { return cityCoordY; }
};
ostream& operator<<(ostream& s, const city* i)
{
	return s << i->nameOfCity() << " (" << i->coordX() << ", " << i->coordY() << ")";
}

// Name input
void inputName(string &name)
{
	cout << "\n\tName >> ";
	cin.ignore();
	getline(cin, name);
}

// Converting the first two lettersof the name string to ASCII values
// and add them together as a Key of the node
int ascii(string name)
{
	int key = 0;
	for (int j = 0; j < 2; j++)
	{
		key = key + (int)name[j];
	}
	return key;
}

// Coordinate Input
void inputCoord(int &x, int &y)
{
	cout << "X-coordinate >> ";
	cin >> x;
	cout << "Y-coordinate >> ";
	cin >> y;
}

// Menu Selection for BST functions 
template<typename E>
void menuSelect(BST<int, E> &tree, int &choice, bool &inloop) 
{
	string name;
	int x = 0, y = 0;
	cout << "\n>> ";
	cin >> choice;
	switch (choice)
	{
	case 1: 
		cout << "\nInsert: ";
		inputName(name);
		
		inputCoord(x, y);
		tree.insert(ascii(name), new city(ascii(name), name, x, y));
		break;
	case 2: 
		inputName(name);
		delete tree.find(ascii(name));
		tree.remove(ascii(name));
		break;
	case 3: 
		cout << "Cleared.\n";
		tree.clear();
		break;
	case 4: 
		cout << "Number of Cities: " << tree.size() << endl;
		break;
	default: inloop = false;
		break;
	}
	cout << "\n\tInorder List:\n";
	tree.printInorder();
}


int main()
{
	BST<int, city*> Cities;
	int choice = 0;
	bool inloop = true;
	while (inloop)
	{
		cout << "\tMenu\n";
		cout << "1. Insert the city.\n";
		cout << "2. Remove the city by name.\n";
		cout << "3. Clear all the data.\n";
		cout << "4. Number of cities.\n";
		cout << "5. Exit.\n";
		menuSelect(Cities, choice, inloop);
		cout << "\n-------------------------------------------------\n";
	}

  return 0;
}
