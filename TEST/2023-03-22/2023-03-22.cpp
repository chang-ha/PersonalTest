﻿// 금일 강의 내용 : 이차원배열

#include <iostream>

int main()
{
	{
		// 코드영역에 있는 char[7]
		// 스택영역에 있는 const char*
		// 자료형이 다르지만 형변환이 일어남
		// 자연스럽게 형변환이 되어버린 것 == 암시적 형변환
		const char* Ptr = "우창하";

		// char 배열형
		// 배열은 중첩이 가능하다

		char Arr[20] = "우창하";

		// 글자 20개 넣을수 있는 배열이 30개 필요함
		// 이차원 배열 == char[][]
		// 차원에 한계는 없음
		// 배열은 뒤에서 앞으로 읽음 == 20개 짜리 배열을 30개 만들어라
		// 궁극적으로 보면 2차원 배열은 실존하지 않음
		// 배열도 포인터와 같이 nd(차원이 정해져있지 않음)임
		char Arr[30][20] = {};

		// 자료형이 다르면 주의하자
		// 자료형이 다르면 무조건 안될 가능성이 있다.
		// bool TTT;
		// Arr = TTT; << 자료형이 다르므로 안됨
	}

	{
		// 램 16기가 == 1바이트가 16기가 만큼 존재하는 1차원 배열
		// 그래서 궁극적으로 모든 배열은 1차원 배열입니다.
		// 메모리는 램안에 있을 수 밖에 없음
		// 2차원 배열이란 인간이 인식하기 쉽게 만든 것
		int Arr[2][2] = { {1, 2}, {3, 4} };
		// [1][2]
		// [3][4]

		int Value00 = Arr[0][0];
		int Value01 = Arr[0][1];
		int Value11 = Arr[1][0];
		int Value10 = Arr[1][1];
		
		// 실제 주소값을 보면 일렬로 붙어있음
		// [1][2][3][4]
		__int64 Address00 = (__int64)&Arr[0][0];
		__int64 Address01 = (__int64)&Arr[0][1];
		__int64 Address10 = (__int64)&Arr[1][0];
		__int64 Address11 = (__int64)&Arr[1][1];
		int a = 0;
	}
}