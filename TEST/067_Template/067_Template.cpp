// 067_Template



#pragma once


typedef int Datatype;

class GameEngineArray
{
public:
	// constructer destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new Datatype[_Value])
		, ArrCount(_Value)
	{
		// ArrPtr = new int[_Value];
	}

	~GameEngineArray()
	{
		// 생성자에서 만들어준 배열은 소멸자에서 삭제한다
		// 안전한 삭제 방법으로
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	// delete function
	GameEngineArray(const GameEngineArray& _Ohter) = delete;
	GameEngineArray(GameEngineArray&& _Ohter) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		ArrCount = _Other.ArrCount;
		ArrPtr = _Other.ArrPtr;


		return *this;
	}

	size_t Count()
	{
		return ArrCount;
	}

	Datatype& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void ReSize(int _Value)
	{
		// 기존의 할당된 배열을 섣불리 지우면 안됨
		// 기존의 있던 값에서 현재의 배열이 복사한 다음 삭제해야 한다.
		// 이전 배열을 지워버림 (Leak방지)
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = new Datatype[_Value];
		ArrCount = _Value;
	}
protected:

private:
	size_t ArrCount;
	Datatype* ArrPtr = nullptr;
};


// Function은 완전히 동일한 함수(오버로딩 개념과 유사)
//void Function(int _Value)
//{
//	printf_s("%d\n", _Value);
//}
//
//void Function(short _Value)
//{
//	printf_s("%d\n", _Value);
//}

template<typename DataType>
void Function(DataType _Value)
{
	printf_s("%d\n", _Value);
}

// 컴파일러가 함수를 새로 만들어주는 형식으로 작동함
// 컴파일러가 오버로딩을 해주는 문법임 (함수를 계속 만들어주는 문법임)
//void Function<int>(int _Value)
//{
//	printf_s("%d\n", _Value);
//}

//void Function<char>(char _Value)
//{
//	printf_s("%d\n", _Value);
//}



// 인자가 char일때 글자가 출력되게 하고 싶음 (딱 char일때만 특수하게 동작하게 하고싶음)
// 이를 "템플릿 특수화"라는 문법입니다.
// template<>를 안붙여도 되지만 명시적인게 좋음
// 오버로딩이랑 똑같은 개념임
template<>
void Function(char _Value)
{
	printf_s("%c\n", _Value);
}

// class Bullet;
template<typename DataType>
class Test
{
public:
	DataType Value;
};
#include <iostream>
int main()
{
	// 아래는 int배열임
	GameEngineArray NewArr(20);

	// 그치만 bool배열을 만들고 싶으면??? 현재 상태면 boolArray 클래스를 다시 만들어야함
	// typedef 의 int가 bool로 바뀌면 bool배열이 되는것임

	// 모든 코드는 그대로인데 자료형만 변수처럼 바꾸고 싶은것임
	// 이때 사용하는 문법이 "Template"
	// 이 템플릿이란 문법은
	// 특정 함수나 특정 클래스에서 자료형만 바뀐 완전히 동일한 함수나 완전히 동일한 클래스를
	// 만들고 싶을때 사용하는 문법입니다.

	// 템플릿 함수의 경우 사용법
	{
		Function<int>(100);
		Function<char>('a');
		// 함수의 경우 "인자추론" 이라는 것을 할 수 있다.
		// 그 상황에 맞춰서 알아서 자료형을 맞춰버림 (암시적 형변환과 유사)
		Function(100);
		Function('a'); 

		// 템플릿 특수화
		Function<char>('a');
		Function<int>('a');
	}

	{
		Test<int> NewIntArr;
		NewIntArr.Value = 10;

		Test<Bullet> NewBulletArr;
		// 이제는 Test가 Bullet이니까 안됨
		// NewBulletArr.Value = 10;
		
		// 클래스는 인자추론이 안됨
		// 지역변수들의 크기를 다 알아야하기 때문에
		// 명시안해주면 크기를 알 수가 없음

		// Test int형
		Test<int> NewInt;
		// Test Bullet형
		Test<Bullet> NewBullet;

		// 둘의 자료형이 다른데
		// 아래가 될 것이라고 착각하지 말자
		// NewInt = NewBullet;
	}
}

