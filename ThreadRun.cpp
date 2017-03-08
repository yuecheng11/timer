#include "ThreadRun.h"
#include <stdlib.h>
#include <time.h>

ThreadRun::ThreadRun(Timer& time)
:_time(time)
{
	
}

void ThreadRun::run()
{
	_time.start();
}
