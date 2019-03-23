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
	Zp operator+(Zp lal);// оператор сложения двух чисел из поля вычетов по модулю p
	Zp operator*(Zp lal);// аналогично +
	Zp operator^(int pow);// аналогично *
	int val = 0;// дефолтное значение, его можно изменить при вводе >> или напрямую
	//void operator=(int lal);// изменяет значение элемента поля
	friend std::ostream& operator<<(std::ostream& op, Zp& output);// выводит значение элемента поля
    friend std::istream& operator>>(std::istream& in, Zp& input);// ввод значения элемента поля
private:
	size_t Char = p; // характеристика поля определена свыше 
};
#endif /*MY_CLASS_H*/