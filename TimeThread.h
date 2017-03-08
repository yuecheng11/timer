#ifndef _MT_TIMETHREAD_H_
#define _MT_TIMETHREAD_H_
#include "Timer.h"
#include "ThreadRun.h"

class ThreadTime
{
public:
	ThreadTime(Timer& time,Thread& thread);
	~ThreadTime();

	void start();
	void stop();
	
private:
	Timer& _timer;
	Thread& _thread;
};

#endif