// 033_MyPrintf


#include <iostream>

inline int MyPrintf(const char* const _Value, ...)
{
	__int64 Address = (__int64)&_Value;
	char* Ptr = (char*)Address;
	Ptr += 8; // char의 sizeof가 1byte이기 때문에 +8하면 8바이트 이동
	int* IntPtr = (int*)Ptr;
	int Value0 = *IntPtr;

	return 0;
	int Count = 0;

	while (0 != _Value[Count])
	{
		char Value = _Value[Count];
		if ('%' == Value)
		{
			++Count;
			char Format = _Value[Count];
			switch (Format)
			{
			case 'd':
			{

				break;
			}
			case 's':
			{

				break;
			}
			default:
			{

				break;
			}
			}
		}
		else
		{
			putchar(Value);
		}
		Count++;
	}
	return 0;
}

int main()
{
	MyPrintf("abcdefg %d asdasdka");
}
