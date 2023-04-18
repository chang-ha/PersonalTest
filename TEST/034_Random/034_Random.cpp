// 034_Random


#include <iostream>
#include <conio.h>
// int Seed;
int Seed = 0;

int SeedChange(int _Seed)
{
	Seed = _Seed;
}

int RandomInt() // == rand()
{
	// 수학공식을 통해서 뭔가 랜덤해보이는 수를 뽑아내주는 것.
	// Seed값이 동일하면 Random은 같은 숫자들이 나옴
	// 그래서 다른 값들을 뽑아주려면 Seed값을 바꿔줘야함
	return ++Seed;
}

int main()
{
	{
		// 금일 질문 답변
		// 배열은 하나의 자료형밖에 안됨
		// int Arr[10] != int Arr[9]
		// int Arr[9] = int Arr[10]은 들어갈 수 없음 (자료형이 전혀 다르기 때문에)
		// int Arr[10] = int Arr[10]도 들어갈 수 없음
		// 배열은 하나하나 직접 다 입력해줘야함
	}
	{
		while (true)
		{
			printf_s("%d\n", RandomInt());
			// 아무키가 눌릴때까지 프로그램을 정지시킨다.
			_getch();
		}
	}

	// Random()은 시드값이 동일하면 동일한 랜덤변수가 나옴
	// 그래서 나온게 srand();
	srand(1);
	// 시드값을 바꿔주는 방법 2가지
	// 1. 현재 시간
	// time()
	// time_t Test = time(0);
	// 2. 프로그램이 켜질 떄 주소값이 바뀌는 것을 이용
	// int Value; , srand((int)&Value)

	// 현재 시간을 리턴해줍니다.
	// 컴퓨터는 시간을 8바이트 정수로 준다.
	// 특정기준시간부터 지금시간까지 몇 초 지났는지 세주는 것
	// ex) 특정기준(1000년)부터 지금시간까지(2023년)까지 몇 초 지났는지 값을 출력해줌
	// 1초 지날때 마다 int값이 1증가함
	// 특정기준시는 UTC시간 (1972년 1월 1일)
	unsigned int Test = time(0);
	srand(Test);
	_getch();
}
