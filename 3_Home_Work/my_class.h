#ifndef MY_CLASS_H
#define MY_CLASS_H
#define p 7
#include <iostream>
#include <cstdio>
using namespace std;
/*этот класс описывает элементы поля вычетов по модулю p с естественными операциями сложения, умножения (и возведение в степень, 
присваивание, ввод с клавиатуры и вывод). У данного класса определен дефолтный конструктор для более простого 
использования.*/
class Zp{
public:
	Zp() = default;
	~Zp() = default;
	Zp operator+(Zp lal);
	Zp operator*(Zp lal);
	Zp operator^(int pow);
	int val = 0;
	Zp& operator=(const int lal);
	friend std::ostream& operator<<(std::ostream& op, const Zp& output);
    	friend std::istream& operator>>(std::istream& in, Zp& input);
private:
	size_t Char = p; 
};
#endif /*MY_CLASS_H*/
