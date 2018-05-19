//
// Laboratory 4 - Inheritance (exp2.cpp)
//
#include <assert.h>
#include "shadowrect.h"
#include "BOX.H"

SimpleWindow DemoWindow("Lab 4 - Experiment 2", 15.0, 9.0, Position(3.0, 3.0));

int ApiMain() 
{
   DemoWindow.Open();
   assert(DemoWindow.GetStatus() == WindowOpen);

   // Instantiate a red shadowed rectangle
   BoxShape B(DemoWindow, Position(6, 5), White, 10.0, 6.0, Blue, 1.0);
   BoxShape R(DemoWindow, Position(6, 5), White, 4.0, 3.0, Red, 0.5);

   B.Draw();
   R.Draw();

   return 0;
}
