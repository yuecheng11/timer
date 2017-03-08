#ifndef _MY_THREAD_H_
#define _MY_THREAD_H_
#include "Noncopyable.h"
#include <pthread.h>

class Thread
{
public:
	Thread();
	~Thread();
	void start();
	void join();
private:
	virtual void run() = 0;
	static void* threadFunc(void*);
private:
	pthread_t _pthid;
	bool isRunning;
};


#endif
