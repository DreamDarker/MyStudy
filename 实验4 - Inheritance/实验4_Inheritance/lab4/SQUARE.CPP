#include "square.h"

SquareShape::SquareShape(SimpleWindow &Window,
 const Position &center, const color &c, float s) :
 Shape(Window, center, c), SideLength(s) {
   // No code needed!
}

float SquareShape::GetSideLength() const {
   return SideLength;
}

void SquareShape::Draw() {
   const Position Center = GetPosition();
   const float SideLength = GetSideLength();

   const Position UpperLeft = Center
    + Position(-.5f * SideLength, -.5f * SideLength);
   const Position LowerRight = Center
    + Position(.5f * SideLength, .5f * SideLength);
   GetWindow().RenderRectangle(UpperLeft, LowerRight,
    GetColor(), HasBorder());
   return;
}


void SquareShape::SetSize(float s) {
   SideLength = s;
   return;
}

void SquareShape::Erase() {
   const Position Center = GetPosition();
   const float SideLength = GetSideLength();

   const Position UpperLeft = Center
    + Position(-.5f * SideLength, -.5f * SideLength);
   const Position LowerRight = Center
    + Position(.5f * SideLength, .5f * SideLength);
   GetWindow().RenderRectangle(UpperLeft, LowerRight,
    White, false);
   if (HasBorder()) {
      GetWindow().RenderRectangle(UpperLeft, LowerRight,
       White, true);
   }
   return;
}


