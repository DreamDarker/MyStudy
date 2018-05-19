//
// Laboratory 4 - Inheritance (exp3.cpp)
//
#include <assert.h>
#include "ezwin.h"
#include "box.h"

SimpleWindow DemoWindow("Lab 4 - Experiment 3", 15.0, 9.0, Position(3.0, 3.0));

int ApiMain() 
{
	// Insert your code here
	DemoWindow.Open();
	assert(DemoWindow.GetStatus() == WindowOpen);

	// Instantiate a red shadowed rectangle
	BoxShape R(DemoWindow, Position(7, 5), White, 5.0, 2.5, Red, 0.1);
	BoxShape B(DemoWindow, Position(7, 5), White, 10.0, 5.0, Blue, 0.1);

	B.Draw();
	R.Draw();

	// R.Erase();

	return 0;

}

