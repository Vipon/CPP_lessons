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
	Zp operator+(Zp lal);// �������� �������� ���� ����� �� ���� ������� �� ������ p
	Zp operator*(Zp lal);// ���������� +
	Zp operator^(int pow);// ���������� *
	int val = 0;// ��������� ��������, ��� ����� �������� ��� ����� >> ��� ��������
	//void operator=(int lal);// �������� �������� �������� ����
	friend std::ostream& operator<<(std::ostream& op, Zp& output);// ������� �������� �������� ����
    friend std::istream& operator>>(std::istream& in, Zp& input);// ���� �������� �������� ����
private:
	size_t Char = p; // �������������� ���� ���������� ����� 
};
#endif /*MY_CLASS_H*/