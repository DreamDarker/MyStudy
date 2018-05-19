#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include "ezwin.h"

//
// WindowObject - base class for objects that can be
//                displayed in a window
//
class WindowObject 
{
public:
   WindowObject(SimpleWindow &w, const Position &p);

   Position      GetPosition() const;
   void          GetPosition(float &x, float &y) const ;
   SimpleWindow &GetWindow() const;

   void SetPosition(const Position &p);
   void SetPosition(float x, float y);

private:
   SimpleWindow& Window;
   Position      Location;
};

#endif

