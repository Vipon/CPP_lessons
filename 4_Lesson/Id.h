#ifndef __ID_H
#define __ID_H

#include <cstdint>
#include <string>
#include <iostream>

class Id {

public:
    Id(const std::string& name, uint8_t age)
        : name(name), age(age)
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
    }

    // copy constructor
    Id(const Id& id)
        : name(id.name), age(id.age)
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
    }

    // move constructor
    Id(Id&& id)
        : name(std::move(id.name)), age(id.age)
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
    }

    ~Id()
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
        info();
        std::cout << '\n';
    }

    virtual void info() const
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
        std::cout << "\tname: " << name << '\n';
        std::cout << "\tage: " << (int)age << '\n';
    }

private:
    std::string name;
    uint8_t age;

};

#endif /* __ID_H */
