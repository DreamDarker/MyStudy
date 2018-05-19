#include "BOX.H"
#include <assert.h>

// Your implementation of BoxShape should be placed in this file
	
	BoxShape::BoxShape(SimpleWindow &window, const Position &center, 
		const color &c, float w, float h, color bc, float bs ) : Shape(window, center, c),
		Width(w), Height(h), border_color(bc), border_size(bs) {}

	BoxShape::BoxShape(SimpleWindow &window, const Position &center,
		float XPosition, float YPosition,const color &c, float w, 
		float h, color bc, float bs) : Shape(window, Position(XPosition, YPosition), c),
		Width(w), Height(h), border_color(bc), border_size(bs) {}

	float BoxShape::GetWidth()  const
	{
		return Width;
	}

	float BoxShape::GetHeight() const
	{
		return Height;
	}

	float BoxShape::GetBorderSize() const
	{
		return border_size;
	}

	color BoxShape::GetBorderColor() const
	{
		return border_color;
	}

	void BoxShape::GetSize(float &W, float &H, float &bs) const
	{
		W = Width;
   		H = Height;
   		bs = border_size;
   		return;
	}

	void BoxShape::SetSize(float W, float H, float bs)
	{
		Width = W;
   		Height = H;
   		border_size = bs;
  		return;
	}

	void BoxShape::SetBorderColor(color bc)
	{
		border_color = bc;
		return;
	}

	void BoxShape::Draw()
	{
		const Position Center = GetPosition();
   		const float Width = GetWidth();
   		const float Height = GetHeight();
		const float bs = GetBorderSize();
   		const Position extend = Position(bs, bs);

   		const Position UpperLeft  = Center + Position(-.5f * Width, -.5f * Height);
   		const Position LowerRight = Center + Position( .5f * Width,  .5f * Height);

   		GetWindow().RenderRectangle(UpperLeft, LowerRight, 
   			GetBorderColor(), 0);
   		GetWindow().RenderRectangle(UpperLeft + extend, LowerRight - extend, White, 0);
   		
   		
   		return;
	}

	void BoxShape::Erase()
	{
		const Position Center = GetPosition();
   		const float Width = GetWidth();
   		const float Height = GetHeight();
		const float bs = GetBorderSize();
   		const Position offset = Position(bs, bs);

   		const Position UpperLeft  = Center + Position(-.5f * Width, -.5f * Height);
   		const Position LowerRight = Center + Position( .5f * Width,  .5f * Height);

	   	GetWindow().RenderRectangle(UpperLeft + offset, LowerRight + offset, White, false);
	   	if (HasBorder()) 
	   	{
	      	GetWindow().RenderRectangle(UpperLeft + offset, LowerRight + offset, White, true);
	   	}

	   	return;
	}