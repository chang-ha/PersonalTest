// 금일 강의 내용 : typedef

#include<iostream>

// 이제부터 자료형 unsigned __int64를 size_t라고 부르겠다
// typedef		 unsigned __int64 size_t
// unsigned __int64 == size_t

// 이런걸 유저가 정의한 자료형이라고 부른다.
// 사용자 정의 자료형의 일종입니다.
// 모든 문법은 인간이 편해지려고 만든 것

// typedef 한것도 다시 typedef할 수 있다.
// time_t == __time64_t
// __time64_t == __int64

// 최신문법으로 typedef와 동일한 문법
using MMInt = int;
using MyMyInt = MMInt;

int main()
{

	time_t Dtime = time(0);
	int length = 0;
	for (size_t i = 0; i < length; i++)
	{

	}
}

// 컴파일러가 하는 일이 늘어남
// 선생님은 생략문법을 안좋아하심