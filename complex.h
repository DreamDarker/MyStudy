// complex.h --

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex {
private:
	//std::string Namepart;
	double RealPart;													// 实部
	double ImagePart;													// 虚部
public:																	// 
	Complex(/*std::string name = { 0 }, */double rp = 0, double ip = 0);
	// 构造函数，构造复数，其实部和虚部分别被赋以参数 rp 和 ip 的值
	~Complex();															// 析构函数，复数被销毁
	
	//std::string GetName() const;										// 
	// 访问函数
	double GetReal() const;												// 返回复数的实部值
	double GetImage() const;											// 返回复数的虚部值
	
	//void SetName(std::string n);										// 
	// 修改函数
	void SetReal(double e);												// 将实部赋为 e
	void SetImage(double e);											// 将虚部赋为 e

	// 辅助函数
	friend Complex operator +(const Complex &a, const Complex &b);
	// 作为？全局（友元）？函数加法运算符“+”的重载			
	Complex operator -(const Complex &a);
	// 作为成员函数减法运算符“-”的重载
};

void AddComplex(const Complex &, const Complex &, Complex &);
void ComplexOutput(const Complex &);

#endif