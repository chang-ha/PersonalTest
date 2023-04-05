// etc.GameEngineArray


#include <iostream>
#include "GameEngineArray.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		int Arr0[10];
		int Arr1[10];

		// 당연히 되어야 할 것 같은 대입이 안됨
		// Arr0 = Arr1;

		// 컴파일러에서 지원하는 Arr형에는
		// operator = 함수를 구현하지 않았다.
	}

	{
		// GameEngineArray Array0;
		// GameEngineArray Array1;

		// 내가 막아놔서 안되는 것
		// operator = 는 delete해놔서
		// 그래서 구현할 것임
		// Array0 = Array1;

		GameEngineArray Array0(10); // == GameEngineArray Array0 = GameEngineArray(20);
		GameEngineArray Array1();

		// 이전의 20개 배열은 잃어버림 == Leak 발생 << 그래서 함수안에서 delete를 만들어 줘야함
		// ArrPtr = new int[10];

		// 숙제 1. 기존의 데이터를 보존해야함
		// 숙제 2. 줄어들든 커지든 데이터는 보존되어야 한다.
		Array0.ReSize(5);
		for (size_t i = 0; i < Array0.Count(); i++)
		{
			Array0[i] = i;
		}

		for (size_t i = 0; i < Array0.Count(); i++)
		{
			printf_s("%d\n", Array0[i]);
		}
	}

	{
		GameEngineArray Array0(10);
		GameEngineArray Array1(5);

		// 숙제 3.
		// 왜 터지는가?????? 이걸 이해하고 고쳐라
		Array1 = Array0;
	}

	{
		GameEngineArray Array0(10);
		GameEngineArray Array1(5);

		for (size_t i = 0; i < Array0.Count(); i++)
		{
			Array0[i] = i;
		}

		// 완전히 동일한 배열이 되게 만들어주세요
		// Array1이 10개짜리 배열이 되고 안에 값도 0~9가 들어가 있어야함
		Array1 = Array0;

		// 0~9가 출력되게 만들어야함
		for (size_t i = 0; i < Array1.Count(); i++)
		{
			printf_s("%d\n", Array1[i]);
		}
	}
}