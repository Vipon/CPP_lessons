#ifndef ARRAY_EXEPTION
#define ARRAY_EXEPTION

#include <iostream>
#include <exception>

class ArrayException : public std::exception {
public:
    ArrayException(std::string && err) noexcept : exc(std::move(err)) {}
    ArrayException(ArrayException&& aExc) noexcept : exc(std::move(aExc.exc)) {}
    const char* what() const noexcept { return exc.c_str(); }
private:
    std::string exc;
};

#endif //ARRAY_EXEPTION