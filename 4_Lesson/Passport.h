#ifndef __PASSPORT_H
#define __PASSPORT_H

#include "Id.h"
#include <string>


class Passport : public Id {

public:
    Passport(const std::string& name, uint8_t age, const std::string& addr)
        : Id(name, age), addr(addr)
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
    }

    Passport(const Id& id, const std::string& addr)
        : Id(id), addr(addr)
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
    }

    Passport(const Passport& pass)
        : Id(pass), addr(pass.addr)
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
    }

    Passport(Passport&& pass)
        : Id(std::move(pass)), addr(std::move(pass.addr))
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
    }

    ~Passport()
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
        info();
    }

    virtual void info() const
    {
        std::cout << "call " << __PRETTY_FUNCTION__ << "\n";
        Id::info();
        std::cout << "\taddr: " << addr << '\n';
    }

private:
    std::string addr;

};

#endif /* __PASSPORT_H */
