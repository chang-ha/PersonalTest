// 077_Cast



#include <iostream>
class A
{
	virtual void Test()
	{

	}

};

class B : public A
{

};

class C : public A
{

};

int main()
{
	// 1. static_cast
	// 메모리 크기만 다른 값형태 형변환에서 사용한다
	{
		// 암시적 형변환 << 사실 별로 좋진 않음 << C++에서 권장하지 않음
		short Test = 0;
		int Value = Test;
		Value = (int)Test; // << C스타일 컴파일했네??? 하면서 static_cast<int>로 바꾸면서 컴파일이 느려짐

		// 서로간의 메모리 크기만 다를 뿐
		// 서로 값형태일때
		Value = static_cast<int>(Test);
	}

	// 2. reinterpret_cast
	// 정수를 포인터로, 포인터를 정수로 변경할 떄 사용한다
	{
		int Value = 3;
		__int64 Address = reinterpret_cast<__int64>(&Value);
		int* Ptr = reinterpret_cast<int*>(Address);
	}

	// 3. dynamic_cast
	// 부모자식구조에서 사용됩니다. (다운캐스팅에 이용됩니다)
	{
		A NewA;
		B NewB;
		A* PtrA = &NewA;
		B* PtrB = &NewB;

		// 다형성 형식의 클래스만 사용가능이라고 뜸
		// 부모자식 관계가 아니면 Null로 리턴해줌
		B* Test = dynamic_cast<B*>(PtrA);
	}

	{
		// 다운캐스팅을 안전하게 할 수 있게 도와준다.
		// 다른 클래스가 들어와도 Null로 바꿔줌
		A* PtrC = new C();
		B* Test = dynamic_cast<B*>(PtrC);
	}

	// 4. const_cast << 존재만 한다. 안알려준다
	// 콘스트를 풀어주는??? 것인듯
	{
		const int a = 0;
		int* b = const_cast<int*>(&a);
		*b = 10;
		int c = 0;
	}
}
