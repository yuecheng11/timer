#include <iostream>
#include <time.h>
#include "TimeThread.h"
//#include "Thread.h"
using namespace std;

int main()
{
	cout<<"first create timer"<<endl;
	Timer timeObj;
	timeObj.Create_timer();
	timeObj.Set_timer(3,6);//第一次等三秒开始打印，以后周期性5秒打印一次

	Thread* pthread = new ThreadRun(timeObj);
	
	ThreadTime pthTime(timeObj,*pthread);
	
	//timeObj.start();
	pthTime.start();

	sleep(20);
	
	pthTime.stop();
	return 0;
}
