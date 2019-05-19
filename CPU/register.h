#ifndef __REGISTER_H
#define __REGISTER_H

#include <cstdint>

class Reg8 {

public:
	Reg8(int8_t val = 0) : reg(val) {}

	Reg8& operator=(const Reg8& buf) { reg = buf.reg; return *this; }

	Reg8 operator+(const Reg8& buf) { return (reg + buf.reg); }
	Reg8 operator-(const Reg8& buf) { return (reg - buf.reg); }
	Reg8 operator*(const Reg8& buf) { return (reg * buf.reg); }
	Reg8 operator/(const Reg8& buf) { return (reg / buf.reg); }
	Reg8 operator%(const Reg8& buf) { return (reg % buf.reg); }
	
	Reg8& operator+=(const Reg8& buf) { reg += buf.reg; return *this; }
	Reg8& operator-=(const Reg8& buf) { reg -= buf.reg; return *this; }
	Reg8& operator*=(const Reg8& buf) { reg *= buf.reg; return *this; }
	Reg8& operator/=(const Reg8& buf) { reg /= buf.reg; return *this; }
	Reg8& operator%=(const Reg8& buf) { reg %= buf.reg; return *this; }

	int8_t operator~() { return ~reg; }
	int8_t operator|(const Reg8& buf) { return (reg | buf.reg); }
	int8_t operator&(const Reg8& buf) { return (reg & buf.reg); }
	int8_t operator^(const Reg8& buf) { return (reg ^ buf.reg); }

	bool operator>(const Reg8& buf) { return (reg > buf.reg); }
	bool operator<(const Reg8& buf) { return (reg < buf.reg); }
	bool operator>=(const Reg8& buf) { return (reg >= buf.reg); }
	bool operator<=(const Reg8& buf) { return (reg <= buf.reg); }
	bool operator==(const Reg8& buf) { return (reg == buf.reg); }
	bool operator!=(const Reg8& buf) { return (reg != buf.reg); }

private:
	int8_t reg;

};

#endif /* __REGISTER_H */
