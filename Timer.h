#ifndef _MY_TIMER_H_
#define _MY_TIMER_H_
#include "Noncopyable.h"
#include <sys/timerfd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/poll.h>
#include <time.h>
class Timer:Noncopyable
{
public:
	Timer();
	~Timer();
	void Create_timer();
	void Set_timer(int init_sec,int interval_sec);
	void stop_timer();

	void start();

	int  readTimer();
private:
	int _timerFd;
	bool _isstart;
};

//timerfd_create


#endif