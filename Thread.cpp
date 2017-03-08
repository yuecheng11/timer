#include "Thread.h"

Thread::Thread()
:_pthid(0)
,isRunning(false)
{

}
Thread::~Thread()
{
	if(isRunning)
	{
		pthread_detach(_pthid);
	}
}
void Thread::start()
{
	pthread_create(&_pthid,NULL,&Thread::threadFunc,this);
	isRunning = true;
}
void Thread::join()
{
	if(isRunning)
	{
		pthread_join(_pthid,NULL);
	}
}

void* Thread::threadFunc(void* arg)
{
	Thread* pThread = static_cast<Thread *>(arg);
	if(pThread)
	{
		pThread->run();
	}
	
}

