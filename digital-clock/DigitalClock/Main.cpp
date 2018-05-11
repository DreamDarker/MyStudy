#include "circle.h"  //ezWinLibrary中的圆形类
#include "label.h"   //ezWinLibrary中的标签类
#include "Time.h"    //自定义的时间类
#include "Date.h"

const float WIN_SIZE = 16.0f;
SimpleWindow W("Clock", WIN_SIZE, WIN_SIZE);

int Clock(){
	static Time tm;
	extern Date Dt;
	--tm;

	CircleShape clock(W, Position(WIN_SIZE / 2, WIN_SIZE / 2),
		Yellow, WIN_SIZE - 0.3f);
	Label time(W, Position(WIN_SIZE / 2, WIN_SIZE * 3/ 5),
		tm.GetTime(), Black, Green);
	Label Date(W, Position(WIN_SIZE / 2, WIN_SIZE * 2/ 5), 
		Dt.GetDate(), Black, Green);

	time.SetFont("Arial", 120);
	Date.SetFont("Arial", 120);
	clock.Draw();
	time.Draw();
	Date.Draw();

	return 0;
}

int ApiMain()
{
	W.Open();
	W.SetTimerCallback(Clock);
	W.StartTimer(1000);
	return 0;
}
