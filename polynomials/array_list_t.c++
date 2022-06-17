template<typename type> array_list_t<type>::array_list_t(int capacity)
{
	this->capacity = capacity;	
	length = 0;
	array = new type[capacity];
	reservation_scalar = 2;
	if(array == NULL)
	{
		std::cout << "Array memory allocation failed." << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

template<typename type> array_list_t<type>::array_list_t(const array_list_t& obj)
{
	this->length = obj.length;
	this->reservation_scalar = obj.reservation_scalar;
	this->capacity = obj.capacity;
	type * temp_array = new type[capacity];
	if(temp_array == NULL)
	{
		std::cout << "Array memory allocation failed." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	for(int i = 0; i < length; ++i)
	{
		temp_array[i] = obj.array[i];
	}
	this->array = temp_array;
}

template<typename type> array_list_t<type>::~array_list_t()
{
	delete [] array;
}

template<typename type> array_list_t<type>& array_list_t<type>::operator =(const array_list_t& obj)
{
	delete [] this->array;
	this->length = obj.length;
	this->capacity = obj.capacity;
	this->reservation_scalar = obj.reservation_scalar;
	this->array = new type[capacity];
	if(this->array == NULL)
	{
		std::cout << "Array memory allocation failed." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	for(int i = 0; i < length; ++i)
	{
		this->array[i] = obj.array[i];
	}
	return *this;
}

template<typename type> int array_list_t<type>::get_length() const
{
	return length;
}

template<typename type> int array_list_t<type>::get_capacity() const
{
	return capacity;
}

template<typename type> void array_list_t<type>::resize()
{
		type * temp = new type[reservation_scalar * capacity];
		if(temp == NULL)
		{
			std::cout << "Array memory allocation failed." << std::endl;
			std::exit(EXIT_FAILURE);
		}
		for(int i = 0; i < length; ++i)
		{
			temp[i] = array[i];
		}
		delete [] array;
		array = temp;
		capacity = reservation_scalar * capacity;
}

template<typename type> std::ostream& operator <<(std::ostream& outs, const array_list_t<type> & obj)
{
	for( int i = 0; i < (obj.length)-1; ++i)
	{
		outs << obj.array[i] << ' ';
	}
	if(obj.length > 0)
	{
		outs << obj.array[(obj.length)-1];
	}
	return outs;
}

template<typename type> void array_list_t<type>::set_capacity(int capacity)
{
	type * temp_array = new type[capacity];
	(length > capacity) ? length = capacity : length;
	if(temp_array == NULL)
	{
		std::cout << "Array memory allocation failed." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	for(int i = 0; i < length; ++i)
	{
		temp_array[i] = array[i];
	}
	delete [] array;
	array = temp_array;
	this->capacity = capacity;
}

template<typename type> void array_list_t<type>::set_reservation(int scalar)
{
	reservation_scalar = scalar;
}

template<typename type> bool array_list_t<type>::is_empty() const
{
	return (!length);
}

template<typename type> bool array_list_t<type>::is_full() const
{
	return (length == capacity); 
}

template<typename type> void array_list_t<type>::insert(int index, type element)
{
	//If the index would produce a non contiguous list, force it to be contiguous. 
	//Negative indices will cause an element to be appended 
	//We know length-1 is the last used location therefore length is the next adjacent location.
	(index > length || index < 0) ? index = length : index;
	//If insufficient memory for additional element, invoke resize()
	if(length + 1 > capacity)
	{
		resize();
	}
	//Shift elements right ward to accomodate new element
	for(signed int i = length; i > index; --i)
	{			
		array[i] = array[i-1];
	}
	array[index] = element;
	++length;
}

template<typename type> void array_list_t<type>::remove(int index)
{
	if( index < 0 || index >= length )
	{
		std::cout << "Index out of range." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if( index == 0 && index == 1 )
	{
		delete [] array;
		array = new type[capacity];
	}
	else
	{
		for( int i = index; i < (length - 1); ++i )
		{
			array[i] = array[i+1];
		}
		--length;
		//Truncate dangling values
		set_capacity(capacity);
	}
}

template<typename type> void array_list_t<type>::clear()
{
	delete [] array;
	array = new type[capacity];
	length = 0;
}

template<typename type> type& array_list_t<type>::operator [](int index) const
{
	if(index > length-1)
	{
		std::cout << "Index is out of bounds" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return array[index];
}

template<typename type> signed int array_list_t<type>::search(const type& element) const
{
	for(int i = 0; i < length; ++i)
	{
		if( array[i] == element )
		{
			return i;
		}
	}	
	return -1;
}
