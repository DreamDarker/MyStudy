// complex.cpp --

#include"stdafx.h"
#include"complex.h"

Complex::Complex(/*std::string name, */double rp, double ip) {			// 构造函数，用来构造复数，其实部和虚部分别被赋以参数 rp 和 ip 的值
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

double Complex::GetReal() const {					// 返回复数的实部值
	return RealPart;
}

double Complex::GetImage() const {					// 返回复数的虚部值
	return ImagePart;
}

//void Complex::SetName(std::string n) {
//	Namepart = n;
//}

void Complex::SetReal(double e) {					// 将实部赋为 e
	RealPart = e;
}

void Complex::SetImage(double e) {					// 将虚部赋为 e
	ImagePart = e;
}

void ComplexOutput(const Complex &a) {											// 输出复数
	std::cout /*<< a.GetName() <<" = " */<< a.GetReal() << "+" << a.GetImage() << "i" << std::endl;
}

Complex operator +(const Complex &a, const Complex &b) { // 全局函数
	Complex c;
	c.RealPart = a.RealPart + b.RealPart;
	c.ImagePart = a.ImagePart + b.ImagePart;
	return c;
}

Complex Complex::operator -(const Complex &a) { // 成员函数
	Complex c;
	c.RealPart = RealPart - a.RealPart;
	c.ImagePart = ImagePart - a.ImagePart;
	return c;
}