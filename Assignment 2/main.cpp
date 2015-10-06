#include <iostream>
#include <cstdlib>
#include "Assignment2.h"

using namespace std;

int main()
{
	Array myArray(6);
	// << myArray.lowerBound() << " Lower bound " << endl;

	myArray.set(0, 1);
	myArray.set(1, 2);
	myArray.set(2, 3);
	myArray.set(3, 4);
	myArray.set(4, 5);
	myArray.set(5, 6);
	myArray.set(6, 7);

	for (int i = 0; i <7; i++)
		cout<<myArray.get(i)<< endl;
	cout << myArray.size();
	return 0; 
}