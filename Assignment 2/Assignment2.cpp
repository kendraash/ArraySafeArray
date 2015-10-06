//
// Assignment  :  #2
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  Assignment2.cpp
//
//
// Description :  Member function declarations.
//

#include "Assignment2.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor Array, allocating memory 

Array::Array(int upper, int lower) : m_upper(upper), m_lower(lower), m_index(new ELEMENT_TYPE[numElements()])
{
	if (!m_index)
	{
		cout << "Error allocating memory" << endl;
		exit(EXIT_FAILURE);
	}
	
}
// Copy constructor
Array::Array(const Array &c) : m_upper(c.m_upper), m_lower(c.m_lower), m_index(new ELEMENT_TYPE[numElements()])
{
	if (!m_index)
	{
		cout << "Error allocating memory" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < numElements(); i++)
		m_index[i] = c.m_index[i];
	
}
// Destructor
Array:: ~Array()
{
	delete[] m_index;
}
// Set function that takes index and sets it to the specified value
void Array :: set(const ELEMENT_TYPE &index, int value)
{
	m_index[index-m_lower] = value;

}
ELEMENT_TYPE Array::get(ELEMENT_TYPE index) const
{
	return m_index[index-m_lower]; // returns the value stored in the array m_index at that index

}
int Array::lowerBound() const
{
	return m_lower;
}
int Array::upperBound()const
{	
	return m_upper; 
}
int Array::size() const
{
	// number of elements times the number of bytes for the ELEMENT_TYPE  
	return sizeof(ELEMENT_TYPE)*numElements();
}

// ------------------------------------ SafeArray -------------------------------------------
// Allocating memory
SafeArray::SafeArray(int upper, int lower) : Array(upper, lower)
{
}

// Set function that includes bound checking
void SafeArray::set(const ELEMENT_TYPE &index, int value)
{
	m_checkRange(index);
	Array::set(index, value);

}
// Get function that includes bound checking 
ELEMENT_TYPE SafeArray::get(ELEMENT_TYPE index) const
{
	m_checkRange(index);
	
	return Array::get(index);
}
