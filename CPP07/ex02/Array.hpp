#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template <typename T>
class Array {
	private : 
		T* _data;
		unsigned int _size;
	public :
		Array() : _data(NULL), _size(0) {}

		Array(unsigned int n) : _data(new T[n]), _size(n) {}

		Array(const Array &copy) : _data(NULL), _size(0) {
				*this = copy;
		}

		~Array() {
			delete[] _data;
		}
    // Opérateur d’affectation
		Array &operator=(const Array& copy) {
			if (this != &copy) {
				delete[] _data;
				_size = copy._size;
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_data[i] = copy._data[i];
			}
			return *this;
		}
    // Opérateur d’indexation
		T &operator[](unsigned int index) {
			if (index >= _size)
				throw std::out_of_range("Index out of range");
			return _data[index];
		}
    // version const de l’opérateur []
		const T &operator[](unsigned int index) const {
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}
    // Méthode size()
		unsigned int size() const {
			return _size;
		}
};

#endif