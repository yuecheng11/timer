#include "Timer.h"
#include <iostream>
using namespace std;
/*
 struct timespec {

               time_t tv_sec;                
               long   tv_nsec;               
           }; 
           struct itimerspec { 
               struct timespec it_interval;  
               struct timespec it_value;    
           };
*/
Timer::Timer()
{

}

Timer::~Timer()
{
	if(_isstart)
   	   Set_timer(0,0);
}
void Timer::Create_timer()
{
	int ret  = timerfd_create(CLOCK_REALTIME,0);  //相对时间
	if(_timerFd == -1)
	{
		perror("create timer error!!!");
		exit(EXIT_FAILURE);
	}
	_timerFd = ret;
}
void Timer::Set_timer(int init_sec,int interval_sec)
{
	struct itimerspec newvalue;
	newvalue.it_interval.tv_sec = 6;//定时器的间隔
	newvalue.it_interval.tv_nsec = 0;
	newvalue.it_value.tv_sec = 3;//定时器第一次到期间隔
	newvalue.it_value.tv_nsec = 0;

	int ret = timerfd_settime(_timerFd,0,&newvalue,NULL);
	if(ret == -1)
	{
		perror("Set_timer error!!!");
		exit(EXIT_FAILURE);
	}
	
}
void Timer::stop_timer()
{
	if(_isstart)
   	   Set_timer(0,0);
	
}
int Timer::readTimer()
{
	uint64_t howmany;	
	ssize_t ret = read(_timerFd, &howmany, sizeof(howmany));	
	if(ret != sizeof(howmany))	
	{		
		perror("read error");
		return -1;
	}	
	return howmany;
}

void Timer::start()
{
	_isstart = true;
	struct pollfd pfd;
	pfd.fd = _timerFd;
	pfd.events = POLLIN;
	uint64_t s = 0;
	while(_isstart)
	{
		int ret = poll(&pfd,1,5000);
		if(-1 == ret)
		{
			if(errno == EINTR)
			{
				continue;
			}
			else
			{
				perror("poll error!!!");
				exit(EXIT_FAILURE);
			}
		}
		else if(0 == ret)
		{
			cout<<"poll timeout"<<endl;
		}
		else
		{
			if(pfd.revents == POLLIN)
			{
				
				s=+ readTimer();

				cout<<s<<endl;
				
			}
		}
	}
}
