#include <assert.h>
#include "wobject.h"
#include <iostream>

WindowObject::WindowObject(SimpleWindow &w,
 const Position &p) : Window(w), Location(p) 
{
   // No body needed
	std::cout << "Constructor WinObj called" << endl;
}


Position WindowObject::GetPosition() const 
{
   return Location;
}

void WindowObject::GetPosition(float &x, float &y) const 
{
   x = Location.GetXDistance();
   y = Location.GetYDistance();
   return;
}

SimpleWindow& WindowObject::GetWindow() const 
{
   return Window;
}

void WindowObject::SetPosition(const Position &p) 
{
   Location = p;
   return;
}

void WindowObject::SetPosition(float x, float y) 
{
   Location = Position(x, y);
   return;
}


