// 068_DeepCopyAndShallowCopy


#include <iostream>
#include "GameEngineArray.h"

int main()
{
	// 얕은 복사 (단순하게 같은 주소값을 복사하는 것)
	// Newint0 이 100번지 라면
	int* Newint0 = new int();

	// Newint1도 100번지
	int* Newint1 = Newint0;

	if (nullptr != Newint0)
	{
		delete Newint0;
		Newint0 = nullptr;
	}
	
	if (nullptr != Newint1)
	{
		delete Newint1;
		Newint1 = nullptr;
	}


	// 딥 카피
	// 나만의 메모리를 새로 만들고
	// 상대방것을 기반으로 새로 만드는것
}



