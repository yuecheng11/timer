#ifndef _MY_NONCOPYABLE_H_
#define _MY_NONCOPYABLE_H_

class Noncopyable
{
public:
	Noncopyable(){}
private:
	Noncopyable(const Noncopyable& rhs){}
	Noncopyable& operator=(const Noncopyable& rhs){}
};

#endif