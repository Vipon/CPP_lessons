#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <exception>
#include <iostream>
class ArrayException : public std::exception
{
public:
	ArrayException(std::string&& err) noexcept : exc(std::move(err)) {}
	ArrayException(ArrayException&& aExc) noexcept : exc(std::move(aExc.exc)) {}
	const char* what() const noexcept { return exc.c_str(); }
private:
	std::string exc;
};
#endif /*MYEXCEPTION_H*/