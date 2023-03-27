#include<iostream>

void printSingel(char* _first)
{
	for (int i = 0; i < 5; i++)
	{
		printf_s("%c\n", _first[i]);
	}
}

void printDouble(int _Arr[3][5])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf_s("%d\t", _Arr[i][j]);
		}
		printf_s("\n");
	}
}

void printPtr(int(*_Arr)[2])
{
	int(*pointer)[2] = {};
	pointer = _Arr;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf_s("%d\t", *(*(pointer + j) + i));
		}
		printf_s("\n");
	}
}

int main()
{
	{
		char first[5] = {};
		for (int i = 97; i < 102; i++)
		{
			char chr = (char)i;
			first[i - 97] = chr;
		}
		//printSingel(first);

		int Arr[3][5] = {};

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Arr[i][j] = i + j;
			}
		}
		//printDouble(Arr);

		// Pte[3][2] == {Ptr[2]의 주소값, Ptr[2]의 주소값, Ptr[2]의 주소값}
		int Ptr[3][2] =
		{
			{11, 12},
			{21, 22},
			{31, 32}
		};

		int(*pointer)[2] = {}; // ()를 안쓰면 int* pointer[2] << 포인터변수 2개가 들어가는 배열을 만드는 것
		pointer = Ptr; // pointer가 가리키는 주소를 Ptr배열 시작주소로 설정
		// (*pointer)[2] = {행렬[2]의 주소값, 행렬[2]의 주소값, 행렬[2]의 주소값}

		int(*Double0)[2] = pointer;
		int(*Double1)[2] = pointer + 1;
		int(*Double2)[2] = pointer + 2;

		__int64 DoubleAdd0 = (__int64)Double0;
		__int64 DoubleAdd1 = (__int64)Double1;
		__int64 DoubleAdd2 = (__int64)Double2;

		int* Address00 = *(pointer + 0) + 0;
		int* Address01 = *(pointer + 0) + 1;
		int* Address10 = *(pointer + 1) + 0;
		int* Address11 = *(pointer + 1) + 1;
		int* Address20 = *(pointer + 2) + 0;
		int* Address21 = *(pointer + 2) + 1;

		__int64 intAdd00 = (__int64)Address00;
		__int64 intAdd01 = (__int64)Address01;
		__int64 intAdd10 = (__int64)Address10;
		__int64 intAdd11 = (__int64)Address11;
		__int64 intAdd20 = (__int64)Address20;
		__int64 intAdd21 = (__int64)Address21;

		int Value00 = *(*(pointer + 0) + 0);
		int Value01 = *(*(pointer + 0) + 1);
		int Value10 = *(*(pointer + 1) + 0);
		int Value11 = *(*(pointer + 1) + 1);
		int Value20 = *(*(pointer + 2) + 0);
		int Value21 = *(*(pointer + 2) + 1);

		printPtr(Ptr);
	}
}