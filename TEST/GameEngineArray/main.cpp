// GameEngineArray


#include <iostream>
#include "GameEngineArray.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int Array0Size = 10;
	GameEngineArray<int> Array0(Array0Size);
	GameEngineArray<int> Array1(5);

	for (size_t i = 0; i < Array0.Count(); i++)
	{
		Array0[i] = i;
	}

	printf_s("----------Array0(%d)----------\n", Array0Size);
	for (size_t i = 0; i < Array0.Count(); i++)
	{
		printf_s("%d\n", Array0[i]);
	}

	Array0Size = 15;
	printf_s("-------Array0 Resize(%d)-------\n", Array0Size);
	Array0.ReSize(Array0Size);
	for (size_t i = 0; i < Array0.Count(); i++)
	{
		printf_s("%d\n", Array0[i]);
	}

	Array0Size = 7;
	printf_s("-------Array0 Resize(%d)-------\n", Array0Size);
	Array0.ReSize(Array0Size);
	for (size_t i = 0; i < Array0.Count(); i++)
	{
		printf_s("%d\n", Array0[i]);
	}

	printf_s("--------Array1 = Array0--------\n");
	Array1 = Array0;
	for (size_t i = 0; i < Array1.Count(); i++)
	{
		printf_s("%d\n", Array1[i]);
	}

	GameEngineArray<int> ArrayTest(0);
}

