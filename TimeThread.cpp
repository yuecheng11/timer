#include "TimeThread.h"

ThreadTime::ThreadTime(Timer& time,Thread& thread)
:_timer(time)
,_thread(thread)
{


}

ThreadTime::~ThreadTime()
{
	_timer.stop_timer();
}

void ThreadTime::start()
{
	_thread.start();
}

void ThreadTime::stop()
{
	_timer.stop_timer();
}