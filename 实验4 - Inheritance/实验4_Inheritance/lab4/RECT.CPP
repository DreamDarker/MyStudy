#include <assert.h>
#include "rect.h"
#include <iostream>

RectangleShape::RectangleShape(SimpleWindow &Window,
 const Position &Center, const color &c, float w,
 float h) : Shape(Window, Center, c),
 Width(w), Height(h) {
   // No code needed
	std::cout << "Constructor Rect1 called" << endl;
}

RectangleShape::RectangleShape(SimpleWindow &Window,
 float XPosition, float YPosition,
 const color &c, float w, float h) : Shape(Window,
 Position(XPosition, YPosition), c),
 Width(w), Height(h) {
   // No code needed
	std::cout << "Constructor Rect2 called" << endl;
 }

float RectangleShape::GetWidth() const {
   return Width;
}

float RectangleShape::GetHeight() const {
   return Height;
}

void RectangleShape::GetSize(float &W, float &H) const {
   W = Width;
   H = Height;
   return;
}

void RectangleShape::Draw() 
{
   const Position Center = GetPosition();
   const float Width = GetWidth();
   const float Height = GetHeight();

   const Position UpperLeft  = Center + Position(-.5f * Width, -.5f * Height);
   const Position LowerRight = Center + Position( .5f * Width,  .5f * Height);

   GetWindow().RenderRectangle(UpperLeft, LowerRight, GetColor(), HasBorder());

   return;
}

void RectangleShape::SetSize(float W, float H) 
{
   Width = W;
   Height = H;
   return;
}

void RectangleShape::Erase() 
{
   const Position Center = GetPosition();
   const float Width = GetWidth();
   const float Height = GetHeight();

   const Position UpperLeft  = Center + Position(-.5f * Width, -.5f * Height);
   const Position LowerRight = Center + Position( .5f * Width,  .5f * Height);

   GetWindow().RenderRectangle(UpperLeft, LowerRight, White, false);
   if (HasBorder()) 
   {
      GetWindow().RenderRectangle(UpperLeft, LowerRight, White, true);
   }

   return;
}




