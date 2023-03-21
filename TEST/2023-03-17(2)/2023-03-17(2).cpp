// 금일 강의 내용 : if문, else if문, else문 


// if문 꿀팁 if + Tab은 자동완성
//if (true)
//{
//
//}
#include <iostream>

int ReturnValue()
{
	return 30;
}
int main()
{
	// if (메모리영역)
	// {
	//		실행코드
	// }
	// 참이면 실행코드가 실행되고
	// 거짓이면 실행코드가 실행되지 않습니다.
	// 참 = 숫자, 거짓 = 0

	int Value = 10;

	// Value는 특정 메모리영역값이 들어가서 거기가 비트가 0이 아니면 if문을 실행하는 것
	if (Value)
	{
		printf_s("실행됩니다\n");
	}

	// 아래도 가능
	if (ReturnValue())
	{
		printf_s("실행됩니다1\n");
	}

	// 아래도 가능하지만 if문 인자에만 int 2개 사용 (선언한 int, 보이지는 않지만 ReturnValue의 값)
	if (int Value0 = ReturnValue())
	{
		printf_s("실행됩니다2\n");
	}
	
	// 아래처럼 사용하는걸 권장
	// 아래처럼 해야 값을 확인하고 왜 작동안하는지 알 수 있음
	int Value0 = ReturnValue();

	if (0 != ReturnValue)
	{
		printf_s("실행됩니다3\n");
	}

	// if문의 함정 (한줄치기)
	
	// 1. 선생님이 극혐함, 내 의견 : 가독성 떨어질거같다
	if (ReturnValue)
		printf_s("실행됩니다4\n");

	// 2. 에러가 발생하기 쉬운 문제 ";" !!!!!!! if옆에 쓰지말자
	if (ReturnValue);
	{
		printf_s("실행됩니다5\n");
	}

	// else if
	// else if는 하나만 실행됨 (가장 먼저 if문 안에 들어가는 녀석)
	if (0)
	{
		printf_s("실행됩니다6\n");
	}
	else if (1)
	{
		printf_s("실행됩니다7\n");
	}
	else if (2)
	{
		printf_s("실행됩니다8\n");
	}

	// else
	if (0)
	{
		printf_s("실행됩니다9\n");
	}
	else if (0)
	{
		printf_s("실행됩니다10\n");
	}
	else
	{
		// 모든 if문이 실패하면 무조건 else내부의 코드 실행
		printf_s("모두실패해서 실행됩니다.\n");
	}

	// 인자는 항상 가장 오른쪽 값을 기준으로 한다.
	// 별로 좋은 코드는 아니지만 가능은 함
	// 가장 오른쪽 인자를 제외하면 모두 실행됨
	if (printf_s("10\n"), 1)
	{
		printf_s("출력되었다.\n");
	}
}
