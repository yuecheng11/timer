#include <iostream>
#include "Timer.h"
using namespace std;

int main()
{
	cout<<"first create timer"<<endl;
	Timer timeObj;
	timeObj.Create_timer();
	timeObj.Set_timer(3,6);//��һ�ε����뿪ʼ��ӡ���Ժ�������5���ӡһ��
	timeObj.start();

	timeObj.stop_timer();
	return 0;
}
