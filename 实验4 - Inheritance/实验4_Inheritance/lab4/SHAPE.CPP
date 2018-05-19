#include <assert.h>
#include "shape.h"
#include <iostream>

Shape::Shape(SimpleWindow &Window, const Position &p,
 const color &c) : WindowObject(Window, p), Color(c),
 Border(true) 
{
   // No body needed
	std::cout << "Constructor Shape called" << endl;
}

color Shape::GetColor() const 
{
   return Color;
}

void Shape::SetColor(const color &c) 
{
   assert(c >= 0 && c < MaxColors);
   Color = c;
   return;
}

void Shape::SetBorder() 
{
   Border = true;
   return;
}

void Shape::ClearBorder() 
{
   Border = false;
   return;
}

bool Shape::HasBorder() const 
{
   return Border;
}


