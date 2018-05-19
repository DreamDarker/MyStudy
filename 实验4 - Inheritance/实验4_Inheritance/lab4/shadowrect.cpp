
#include "shadowrect.h"
#include <iostream>

// define ShadowedRectangleShape's constructor here
ShadowedRectangleShape::ShadowedRectangleShape(SimpleWindow &Window,
	const Position &Center, const color &c,
	float w, float h) :RectangleShape(Window, Center, c, w, h) {};

/// define ShadowedRectangleShape's draw function here
void ShadowedRectangleShape::Draw()
{
	const Position Offset = Position(0.25, 0.25);
	const Position Center = GetPosition();
	const float	Width  = GetWidth();
	const float	Height = GetHeight();

	const Position UpperLeft   = Center + Position(-.5f * Width, -.5f * Height);
	const Position LowerRight  = Center + Position( .5f * Width,  .5f * Height);

	GetWindow().RenderRectangle(UpperLeft + Offset, LowerRight + Offset, Black, HasBorder());
	GetWindow().RenderRectangle(UpperLeft, LowerRight, GetColor(), HasBorder());

	return;
}

void ShadowedRectangleShape::Erase() 
{
	const Position Offset = Position(0.25, 0.25);
	const Position Center = GetPosition();
	const float	Width = GetWidth();
	const float	Height = GetHeight();

	const Position UpperLeft = Center + Position(-.5f * Width, -.5f * Height);
	const Position LowerRight = Center + Position(.5f * Width, .5f * Height);

   // Erase main rectangle first
   GetWindow().RenderRectangle(UpperLeft, LowerRight, White, false);
   if (HasBorder()) 
   {
      GetWindow().RenderRectangle(UpperLeft, LowerRight, White, false);
   }

   GetWindow().RenderRectangle(UpperLeft + Offset, LowerRight + Offset, White, false);
   if (HasBorder()) 
   {
      GetWindow().RenderRectangle(UpperLeft + Offset, LowerRight + Offset, White, false);
   }

   return;
}
 