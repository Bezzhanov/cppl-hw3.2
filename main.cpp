#include <iostream>
#include <algorithm>

class smart_array
{
public:
	smart_array(size_t size) : arr_(new int[size]), size_(size)
	{
		std::cout << "\nconstructor called\n";
	};
	~smart_array()
	{
		delete[] arr_;
		std::cout << "\ndestructor called\n";
	};
	smart_array(smart_array& array)
	{
		delete[] this->arr_;
		this->counter = 0;
		this->size_ = array.size_;
		this->arr_ = new int[array.size_];
		for (int i = 0; i < array.counter; i++)
		{
			this->add_element(array.get_element(i));
		}
		//delete[] & array;
		std::cout << "\ncalled copy constructor\n";
	};

	void add_element(int element)
	{
		if (this->counter < this->size_)
		{
			arr_[counter] = element;
			std::cout << arr_[counter] << "\t";
			counter++;
		}
		else
		{
			std::cout << "\nArray index out of bounds!\n" << std::endl;
		}
	};
	int get_element(int index)
	{

		if (this->counter > index)
		{

			return this->arr_[index];
		}
		else
		{
			throw "\nThere is no such index in the array\n";
		}

	}

	void operator=(smart_array& array)
	{
		delete[] this->arr_;
		this->counter = 0;
		this->size_ = array.size_;
		this->arr_ = new int[array.size_];
		for (int i = 0; i < array.counter; i++)
		{
			this->add_element(array.get_element(i));
		}
		//delete[] & array;
		std::cout << "\ncalled overload operator=\n";
	}

private:
	int* arr_;
	size_t size_;
	size_t counter = 0;
};

int main()
{

	try
	{
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);

		std::cout << arr.get_element(1) << std::endl;
		//4
		smart_array new_array(2);
		new_array.add_element(155);
		new_array.add_element(14);

		arr = new_array;
		std::cout << arr.get_element(1) << std::endl;
		//14
		smart_array new_array_2(arr);
		std::cout << new_array_2.get_element(1) << std::endl;
		//14
	}
	catch (const std::exception& ex)

	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}