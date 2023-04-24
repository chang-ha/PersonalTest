// 080_TypeDefEx


#include <iostream>
typedef int MYINT, * MYTEST;
int main()
{
	int* Ptr0 = nullptr;
	// typedef에 *붙이면 포인터를 typedef하는 것
	MYTEST Ptr1 = nullptr;
}