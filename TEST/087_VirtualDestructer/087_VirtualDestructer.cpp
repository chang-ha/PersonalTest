// 087_VirtualDestructer

#include <iostream>
class A
{
public: 
	virtual void Function()
	{

	}
	
	virtual void Test()
	{
		std::cout << "A Test" << std::endl;
	}

	A()
	{

	}

	// 소멸자의 특수성
	// 컴파일러는 소멸자 함수를 ~A로 인식하지 않고 ~로 인식하기 때문에 virtual(가상함수)를 사용하면
	// 자식 클래스에서 override가능
	virtual ~A()
	{

	}
};

class B : public A
{
	void Test() override
	{
		std::cout << "B Test" < std::endl;
	}

	B()
	{

	}

	~B() override
	{

	}
};
int main()
{
	A* NewB = new B();
	// B::Test(B* const this)
	// 사실 멤버함수의 첫번째 인자는
	// 그냥 this가 아닌 해당 클래스* 의 this를 인자로 받음
	// 그래서 아래함수는 불가능
	// NewB->B::Test();

	NewB->A::Test();
	delete NewB;
}
