// 082_LocalStaticValue



#include <iostream>
// static int Value = 0;

void TestFunction()
{
	// 지역 static은 이 함수 내부에서만 쓸 수 있는 전역변수임
	// 컴파일 되면 외부에서 선언되는것과 같음
	static int Value = 0;
	std::cout << Value << std::endl;
	++Value;
}
int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		TestFunction();
	}
}