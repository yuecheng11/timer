#ifndef _MY_THREADTIME_H_
#define _MY_THREADTIME_H_
#include "Thread.h"
#include "Timer.h"

class ThreadRun:public Thread
{
public:
	ThreadRun(Timer& time);
	void run();
private:
	Timer& _time;
};

#endif