#ifndef MY_CLASS_H
#define MY_CLASS_H
#include <iostream>
#include <cstdio>
using namespace std;
/*���� ����� ��������� �������� ���� ������� �� ������ p � ������������� ���������� ��������, ��������� (� ���������� � �������,
������������, ���� � ���������� � �����). � ������� ������ ��������� ��������� ����������� ��� ����� ��������
�������������.*/
class Zp {
public:
	Zp(size_t p);
	~Zp() = default;
	Zp operator+(const Zp lal) const; // �������� �� ������ p
	Zp operator*(const Zp lal) const; // ��������� ���������, ������ �� ������ p
	Zp operator^(const int pow) const; // ���������� � ������� (������������� ��� �������������) �� ������ p
	Zp& operator=(const int lal); // ������������ �������� ����� ��������, ������� ����������������� � ������� ����
	friend std::ostream& operator<<(std::ostream& op, const Zp& output); // ����� �������� �������� 
	friend std::istream& operator>>(std::istream& in, Zp& input); // ���������� ��������� "=", ������ ���� � ���������� 
	Zp& operator=(const Zp lal) 
	{
		Char = lal.Char;
		val = lal.val;
		return *this;
	}
private:
	size_t Char; // �������������� ����
		int val = 0; // �������� �������� ���� �� ��������� (��� ���������� ������������, ������� �������� ������ � ����������
		// ���� ��� � �������)
};
#endif /*MY_CLASS_H*/