#ifndef RECTSHAPE_H
#define RECTSHAPE_H

#include "shape.h"

class RectangleShape : public Shape 
{
public:
   RectangleShape(SimpleWindow &Window,
       const Position &Center, const color &c = Red,
       float Length = 1.0f, float Width = 2.0f);

   RectangleShape(SimpleWindow &w,
       float XCoord, float YCoord,
       const color &c = Red, float Length = 1.0f,
       float Width = 2.0f);

   float GetWidth() const;
   float GetHeight() const;

   void GetSize(float &Width, float &Height) const; 
   void SetSize(float Width, float Height);

   void Draw();
   void Erase();
   
private:
   float Width;
   float Height;
};

#endif
