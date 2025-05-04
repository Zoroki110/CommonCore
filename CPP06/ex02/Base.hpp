#ifndef BASE_HPP
#define BASE_HPP

class Base {
	public:
		Base();
		Base(const Base& copy);
		Base& operator=(const Base& copy);
		virtual ~Base();
};

#endif