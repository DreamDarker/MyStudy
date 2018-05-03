// complex.h --

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex {
private:
	//std::string Namepart;
	double RealPart;													// ʵ��
	double ImagePart;													// �鲿
public:																	// 
	Complex(/*std::string name = { 0 }, */double rp = 0, double ip = 0);
	// ���캯�������츴������ʵ�����鲿�ֱ𱻸��Բ��� rp �� ip ��ֵ
	~Complex();															// ��������������������
	
	//std::string GetName() const;										// 
	// ���ʺ���
	double GetReal() const;												// ���ظ�����ʵ��ֵ
	double GetImage() const;											// ���ظ������鲿ֵ
	
	//void SetName(std::string n);										// 
	// �޸ĺ���
	void SetReal(double e);												// ��ʵ����Ϊ e
	void SetImage(double e);											// ���鲿��Ϊ e

	// ��������
	friend Complex operator +(const Complex &a, const Complex &b);
	// ��Ϊ��ȫ�֣���Ԫ���������ӷ��������+��������			
	Complex operator -(const Complex &a);
	// ��Ϊ��Ա���������������-��������
};

void AddComplex(const Complex &, const Complex &, Complex &);
void ComplexOutput(const Complex &);

#endif