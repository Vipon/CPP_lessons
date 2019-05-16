#ifndef MY_CLASS_H
#define MY_CLASS_H
#include <iostream>
#include <cstdio>
using namespace std;
/*этот класс описывает элементы поля вычетов по модулю p с естественными операциями сложения, умножения (и возведение в степень,
присваивание, ввод с клавиатуры и вывод). У данного класса определен дефолтный конструктор для более простого
использования.*/
class Zp {
public:
	Zp(size_t Char);
	~Zp() = default;
	Zp operator+(const Zp& lal) ; // сложение по модулю p
	Zp operator*(const Zp& lal) ; // умножение элементов, взятое по модулю p
	Zp operator^(const int pow) ; // возведение в степень (положительную или отрицательную) по модулю p
	Zp& operator=(const int lal); // присваивание элементу целое значение, которое преобразовывается в элемент поля
	friend std::ostream& operator<<(std::ostream& op, const Zp& output); // вывод значение элемента 
	friend std::istream& operator>>(std::istream& in, Zp& input); // аналогично оператору "=", только ввод с клавиатуры 
	Zp& operator=(const Zp lal) 
	{
		Char = lal.Char;
		val = lal.val;
		return *this;
	}
private:
	size_t Char; // характеристика поля
		int val = 0; // значение элемента поля по умолчанию (для дефолтного конструктора, который упрощает работу с элементами
		// поля как с числами)
};
#endif /*MY_CLASS_H*/
