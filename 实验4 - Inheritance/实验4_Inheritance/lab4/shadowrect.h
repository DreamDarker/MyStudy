#include "rect.h"

class ShadowedRectangleShape : public RectangleShape 
{
public:
	// prototype constructor         
	ShadowedRectangleShape(SimpleWindow &Window, 
		const Position &Center, const color &c = Black, 
		float Length = 1.0f, float Width = 2.0f);
	// prototype Draw()
	void Draw();
	// prototype Erase()
	void Erase();

private:
	Position Offset;
};
