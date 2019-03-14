#ifndef __GRAPH_EXCEPTION_H
#define __GRAPH_EXCEPTION_H

#include <string>
#include <exception>


class graphException : public std::exception {

public:

    graphException(std::string&& err) noexcept : exc(std::move(err)) {}
    graphException(graphException&& gExc) noexcept : exc(std::move(gExc.exc)) {}
    const char* what() const noexcept { return exc.c_str(); }

private:

    std::string exc;
};


#endif /* __GRAPH_EXCEPTION_H */
