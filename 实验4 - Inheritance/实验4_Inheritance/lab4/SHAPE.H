#ifndef SHAPE_H
#define SHAPE_H

#include "wobject.h"

//
// Shape - base class for shapes that can be displayed
//         in a window. Shape is derived from
//         WindowObject
//
class Shape : public WindowObject 
{
public:
  Shape(SimpleWindow &Window, const Position &p, const color &c = Red);

  color GetColor() const;
  bool  HasBorder() const;
  
  void SetColor(const color &c);
  void SetBorder();
  void ClearBorder();

  virtual void Shape::Draw() = 0;

private:
  color Color;
  bool  Border;
};

#endif
