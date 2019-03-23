#ifndef MY_CLASS_H
#define MY_CLASS_H
#define p 7
#include <iostream>
#include <cstdio>
using namespace std;

class Zp{
public:
	Zp() = default;
	~Zp() = default;
	Zp operator+(Zp lal);// оператор сложени€ двух чисел из пол€ вычетов по модулю p
	Zp operator*(Zp lal);// аналогично +
	Zp operator^(int pow);// аналогично *
	int val = 0;// дефолтное значение, его можно изменить при вводе >> или использу€ оператор =
	void operator=(int lal);// измен€ет значение элемента пол€
	friend std::ostream& operator<<(std::ostream& op, Zp& output);// выводит значение элемента пол€
    friend std::istream& operator>>(std::istream& in, Zp& input);// ввод значени€ элемента пол€
private:
	size_t Char = p; // характеристика пол€ определена свыше 
};
#endif /*MY_CLASS_H*/