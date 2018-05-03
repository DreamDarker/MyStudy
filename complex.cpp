// complex.cpp --

#include"stdafx.h"
#include"complex.h"

Complex::Complex(/*std::string name, */double rp, double ip) {			// ���캯�����������츴������ʵ�����鲿�ֱ𱻸��Բ��� rp �� ip ��ֵ
	/*Namepart = name;*/
	RealPart = rp;
	ImagePart = ip;
}

Complex::~Complex() {
//	delete Complex::NamePart;
	std::cout << "obj has deleted." << std::endl;
}

//std::string Complex::GetName() const {
//	return Namepart;
//}

double Complex::GetReal() const {					// ���ظ�����ʵ��ֵ
	return RealPart;
}

double Complex::GetImage() const {					// ���ظ������鲿ֵ
	return ImagePart;
}

//void Complex::SetName(std::string n) {
//	Namepart = n;
//}

void Complex::SetReal(double e) {					// ��ʵ����Ϊ e
	RealPart = e;
}

void Complex::SetImage(double e) {					// ���鲿��Ϊ e
	ImagePart = e;
}

void ComplexOutput(const Complex &a) {											// �������
	std::cout /*<< a.GetName() <<" = " */<< a.GetReal() << "+" << a.GetImage() << "i" << std::endl;
}

Complex operator +(const Complex &a, const Complex &b) { // ȫ�ֺ���
	Complex c;
	c.RealPart = a.RealPart + b.RealPart;
	c.ImagePart = a.ImagePart + b.ImagePart;
	return c;
}

Complex Complex::operator -(const Complex &a) { // ��Ա����
	Complex c;
	c.RealPart = RealPart - a.RealPart;
	c.ImagePart = ImagePart - a.ImagePart;
	return c;
}