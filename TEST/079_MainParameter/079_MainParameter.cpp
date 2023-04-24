// 079_MainParameter


#include <iostream>
// 예전의 main함수는 아래처럼 되어 있었음
int main(int _Count, const char** _InitText)
{
	// 내 프로세스가 다른 프로세스를 실행할수도 있습니다.
	// 내가 실행하는 곳에 따라서 위치가 달라진다

	for (size_t i = 0; i < _Count; i++)
	{
		// char*자료형임
		// 이 프로그램이 실행되는 경로를 우리에게 줌
		std::cout << _InitText[i] << std::endl;
	}
}
