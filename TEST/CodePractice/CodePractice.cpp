﻿
#include <iostream>

void Varint(int _first, ...)
{
	int* Ptr = &_first;
	
	int Value0 = Ptr[0];
	int Value1 = Ptr[2];
	int Value2 = Ptr[4];
	int Value3 = Ptr[6];
	int Value4 = Ptr[8];
	int Value5 = Ptr[10];

}

int main()
{
	int Value0 = 10;
	int Value1 = 20;

	{
		int* Ptr0 = &Value0;

		const int* Ptr1 = &Value1;

		*Ptr0 = 30;
		// *Ptr1 = 30;

		Ptr0 = &Value1;
		Ptr1 = &Value0;
	}

	{
		int* Ptr0 = &Value0;
		int* const Ptr1 = &Value1;
	
		*Ptr0 = 30;
		*Ptr0 = 30;

		Ptr0 = &Value1;
		// Ptr1 = &Value0;
	}
	
	{
		int* Ptr0 = &Value0;
		const int* const Ptr1 = &Value1;

		*Ptr0 = 30;
		// *Ptr1 = 30;

		Ptr0 = &Value1;
		// Ptr1 = &Value0;


	}

	{
		__int64 Value64 = (__int64)Value0;
		__int64 Value641 = (__int64)Value1;
		int a = 0;
	}

	{
		int* Ptr = nullptr;
		int Arr[10] = {1,2,3,4,5,6,7,8,9,10};

		int* ArrPtr = Arr;
		int* ArrPtr1 = &Arr[1];
		int* ArrPtr2 = &Arr[2];
		int* ArrPtr3 = &Arr[3];
		int* ArrPtr4 = &Arr[4];
		int* ArrPtr5 = &Arr[5];
		int* ArrPtr6 = &Arr[6];
		int* ArrPtr7 = &Arr[7];
		int* ArrPtr8 = &Arr[8];
		int* ArrPtr9 = &Arr[9];
		int* ArrPtr10 = &Arr[10];
		int a = 0;
	}

	{
		const char* Ptr = "123456789";
		char ch0 = Ptr[0];
		char ch1 = Ptr[1];
		char ch2 = Ptr[2];
		char ch3 = Ptr[3];
		char ch4 = Ptr[4];
		char ch5 = Ptr[5];
		char ch6 = Ptr[6];
		char ch7 = Ptr[7];
		char ch8 = Ptr[8];
		char ch9 = Ptr[9];
		char ch10 = Ptr[10];
	}

	int Value = 5;
	printf_s("while\n");
	while (printf_s("조건부\n"), Value)
	{
		--Value;
		printf_s("코드영역\n");
	}

	Value = 5;
	printf("\ndo\n");
	do
	{
		--Value;
		printf_s("코드영역\n");
	} while (printf_s("조건부\n"), Value);

	Varint(1, 2, 3, 4, 5, 6/*, 7*/);
}