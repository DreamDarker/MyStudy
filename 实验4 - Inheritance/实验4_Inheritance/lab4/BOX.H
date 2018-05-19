#ifndef BOX_H
#define BOX_H
// Your declaration of BoxShape should be placed in this file
#include "shape.h"

class BoxShape : public Shape
{
public:
	BoxShape(SimpleWindow &Window,
		const Position &Center, const color &c = White,
		float Length = 1.0f, float Width = 2.0f, 
		color border_color = Red, float border_size = 0.1f);

	BoxShape(SimpleWindow &window, 
		const Position &center,float XPosition, 
		float YPosition, const color &c, 
		float Length = 1.0f,float Width = 2.0f, 
		color border_color = Red, float border_size = 0.1f);

	float BoxShape::GetWidth()  const;
	float BoxShape::GetHeight() const;
	float BoxShape::GetBorderSize() const;
	color BoxShape::GetBorderColor() const;

	void GetSize(float &Width, float &Height, float &bs) const; 
	void SetSize(float Width, float Height, float bs);
	void SetBorderColor(color bc);

	void Draw();
	void Erase();
private:
	float Width;
	float Height;
	float border_size;
	color border_color;
};

#endif