
//
// Assignment  :  #2
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  Assignment2.h
//
//
// Description :  Declarations for the Array and SafeArray classes.
//




#include  <cstdlib>
#include <iostream>

#ifndef  Assignment2_H
#define  Assignment2_H

using  namespace  std;


typedef int  ELEMENT_TYPE;

class Array
{
	public :
		Array(int upper, int lower=0);
		Array(const Array &c);
		~Array();
		void set(const ELEMENT_TYPE &index, int value);
		ELEMENT_TYPE get(ELEMENT_TYPE index) const;
		int lowerBound() const;
		int upperBound() const;
		int size() const;
		int numElements() const
		{
			return abs(upperBound() - lowerBound()) + 1;
		}

	private :
		const int m_upper;
		const int m_lower;
		ELEMENT_TYPE *m_index; // pointer to the data 
		

};
// ------------------------------------ SafeArray -------------------------------------------
class SafeArray : public Array
{
	public:
		SafeArray(int upper, int lower = 0);
		void set(const ELEMENT_TYPE &index, int value);
		ELEMENT_TYPE get(ELEMENT_TYPE index) const;

	private:

	 void  m_checkRange(int index) const 
		{
			if (index < lowerBound() || index > upperBound())
			{
				cout << "Index out of range " << endl;
				exit(EXIT_FAILURE);
			}
		}
};

#endif