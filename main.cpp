// main.cpp -- 复数的实部与虚部

#include "stdafx.h"
#include "complex.h"

int main()
{
	using namespace std;
	Complex z1(2, 3);						// 通过构造函数自动生成复数 z=2 + 3i
	ComplexOutput(z1);
	Complex z2;									// 通过构造函数自动生成复数 z=0 + 0i=0
	ComplexOutput(z2);
	z2.SetReal(6);								// 将 z2 实部赋为 6
	z2.SetImage(8);								// 将 z2 虚部赋为 8
	/*z2.PutName("z2");*/
	ComplexOutput(z2);
	Complex z3;
	z3 = z1 - z2;
	ComplexOutput(z3);
	Complex z4;
	z4 = z1 + 3;
	ComplexOutput(z4);
	z4 = z1 + z2;
	ComplexOutput(z4);
	return 0;
}

