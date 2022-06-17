#ifndef ARRAY_LIST_TYPE_H
#define ARRAY_LIST_TYPE_H
#include <iostream>

/*
	CLASS INVARIANTS:
		The array implemented list points to valid memory.
		The array elements will be contiguous
*/

//FORWARD DECLARATIONS
template<typename type> class array_list_t;
template<typename type> std::ostream& operator <<(std::ostream& outs, const array_list_t<type>& obj);

template<typename type> class array_list_t
{
	friend std::ostream& operator << <>(std::ostream& outs, const array_list_t<type>& obj);
	public:
		array_list_t(int capacity = 0);
		array_list_t(const array_list_t& obj);
		~array_list_t();
	
		//ACCESSORS
		int get_length() const;
		/*
			Returns the number of elements
		*/

		int get_capacity() const;
		/*
			Returns the amount of currently allocated memory.
		*/		

		//MUTATORS
		void set_capacity(int capacity);
		/*
			Sets the size of the array. If < current length, values are truncated. 
		*/
		void set_reservation(int scalar);
		/*
			Sets the scalar by which the capacity is scalled when automatically resizing.
		*/
		void append(type element);
		/*
			Appends an element to the end of the array.
		*/
		void insert(int index, type element);
		/*
			Insert an element at the specified index.
			If the index is out of range appends to the end.
		*/
		void remove(int index);
		/*
			Remove an element at the specified index.	
		*/
		
		void clear();
		/*
			Erase all elements in the list.
		*/

		//MISC
		bool is_empty() const;
		bool is_full() const;
		int search(const type& element) const;	
		//OVERLOADED OPERATORS FUNCTIONS
		array_list_t& operator =(const array_list_t& obj);			
		type& operator [](int index) const;

	protected:
		void resize();	
		int length;
		int reservation_scalar;
		int capacity;
		type * array;

	private:
};

#include "array_list_t.c++"
#endif //LIST_DATA_STRUCTURE_H
