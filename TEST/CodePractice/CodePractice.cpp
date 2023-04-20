class A
{
	static const int Value = 0;
};

#include <iostream>
int main()
{
	A newA;
	printf_s("%d", sizeof(newA));
}