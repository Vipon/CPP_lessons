#ifndef __Exceptions_H
#define __Exceptions_H

#include <iostream>
#include <exception>

class ArrException : public std::exception {
public:
    ArrException(std::string&& err) noexcept : exc(std::move(err)) {}
    ArrException(ArrException&& gExc) noexcept : exc(std::move(gExc.exc)) {}
    const char* what() const noexcept { return exc.c_str(); }
private:
    std::string exc;
};

#endif//__Exceptions_H