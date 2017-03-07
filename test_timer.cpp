#include <iostream>
#include "Timer.h"
using namespace std;

int main()
{
	cout<<"first create timer"<<endl;
	Timer timeObj;
	timeObj.Create_timer();
	timeObj.Set_timer(3,6);//第一次等三秒开始打印，以后周期性5秒打印一次
	timeObj.start();

	timeObj.stop_timer();
	return 0;
}
