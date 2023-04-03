// 059_ClassDefault


#include <iostream>
class A
{
	// 눈에 보이지 않지만 존재하는 것들
	// private : << 디폴트 접근제한 지정자


	// public:
	// A& operator=(const A& _Other) {}
	// 디폴트 대입연산자가 존재합니다.

	// public:
	// A(); << 디폴트 생성자
	// A(const A& _Other); << 디폴트 복사생성자


	// ~A(); << 디폴트 소멸자

	// 아래는 나중에 설명할 내용
	// A& operator=(const A&& _Other) {} // RValue 대입연산자가 존재.
	// A(const A&& _Other) {} // RValue 복사 생성자
	// = delete; (해당 함수를 안쓰겠다)

	// 앞으로 아래 함수들은 전부 디폴트값으로 만들것임
	// 모르고 사용하는것을( == 당연히 된다는 것을) 막기위해

public:

	// constructer destructer
	A() {}
	~A() {}

	// delete function
	A(const A& _Ohter) = delete;
	A(A&& _Ohter) noexcept = delete;
	A& operator=(const A& _Other) = delete;
	A& operator=(A&& _Other) noexcept = delete;
};

int main()
{
	A NewA0;
	A NewA1;

	// A(A && _Ohter) noexcept = delete;
	// A NewA2 = A();

	// A& operator=(const A & _Other) = delete; 
	// NewA1 = NewA0;
}
