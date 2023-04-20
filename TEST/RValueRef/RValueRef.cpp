// RValueRef (&& == 이동생성자)
// RValue == 이름없는 녀석 == 함수의 리턴값이 존재하면 "보이진 않지만 할당된 공간"이 있음

#include <iostream>
#include <string>
#include <vector>

class A
{
public:
	std::string Name;
	std::vector<int> Values;
};

void Test(const A& _Other)
{
	if ("Fighter" == _Other.Name)
	{
		int a = 0;
	}
	int a = 0;
}

class NewTest 
{
public:
	int Value;
	int* Ptr = nullptr;

	void CreateBuffer()
	{
		Ptr = new int[500];
	}
	NewTest()
	{

	}

	~NewTest()
	{
		if (nullptr != Ptr)
		{
			delete[] Ptr;
			Ptr = nullptr;
		}
	}
	NewTest(const NewTest& _Other)
	{
		int a = 0;
	}

	// 이동생성자라고 합니다
	NewTest(NewTest&& _Other)
	{
		int a = 0;
	}
	NewTest& operator=(const NewTest& _Other)
	{
		int a = 0;
		return *this;
	}

	// 함수안의 지역변수에서 곧 사라질 변수를 인자로 받았다는것을 구분할 수 있게 해주는
	// 함수 == RValue Reference (&&)
	NewTest& operator=(NewTest&& _Other)
	{
		// 이때 할일은 얕은 복사
		// 함수에서 할당한 곧 사라질 힙 메모리를 그냥 없애지말고 (그냥 없애면 비효율적임 == 낭비)
		// 해당 힙 메모리 영역의 주소값을 return값으로 받을 수 있게 해줌
		Ptr = _Other.Ptr; // 이동 대입 (상대의 권한을 이동받는다고 표현해서)
		_Other.Ptr = nullptr; // const NewTest&& 로 받으면 안되는 이유임(Ptr을 끊어줘야함)
		return *this;
	}
};

NewTest TestNew()
{
	NewTest NewValue;
	NewValue.CreateBuffer();
	return NewValue;
}

int Function()
{
	return 10;
}

std::vector<int> TestInt()
{
	return std::vector<int> { 1, 2, 3 };
}
int main()
{
	A NewA;
	NewA.Name = "Fighter";
	NewA.Values = { 1,2,3 };
	Test(NewA);

	A NewA0;
	NewA0 = NewA;

	{
		NewTest Test;
		Test = TestNew();
		int a = 0;

	}

	{
		// 대입할 수 있고 메모리 영역을 특정할 수 있느 메모리들을 LValue라고 함
		int Test = 20;
		Test = 30;

		// LValue는 쉽게 RValue가 될 수 있음
		int Test2 = 10;
		Test2 = Test;

		if (Function())
		{

		}
		// RValue
		// 메모리를 사용할 순 없음
		// 참조만 할 수 있음 
		// RValue는 LValue가 될 수 없음
		// Function() = 30;

		// &(하나)를 LValue Reference
		// 명확하게 위치가 있고 메모리를 특정할 수 있어야함
		// int& Test = Function(); << 불가능

		// &&(두개)를 RValue Reference
		// 메모리를 특정할 수 없음
		// 이것을 받아서 쓸 수 있게 만들어주는 &&
		int&& Test3 = Function();
		int Test4 = Function();
	}

	{
		// 이떄 RValue가 동작한다는 겁니다.
		std::vector<int> Test = TestInt();
	}
}