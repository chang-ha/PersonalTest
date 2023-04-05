// 065_DeleteHeap


void TestReference(int& _Value);
// 중요한 습관들
#include <iostream> // iosteam안에 crtdbg.h가 들어있음
void main()
{
	// 힙을 사용한다면 맨 처음에 걸어놓는 습관을 들이자
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// 중복할당 예시
	{
		int* Newint = new int();
		Newint = new int();
	}

	{
		int* Newint = new int();
		delete Newint; // 꼭 해당 포인터를 사용해야 한다면 지우고 다시 할당받기
		Newint = new int();
		delete Newint;
	}

	{
		// new는 운영체제에 부탁하는것이다.
		// 어떤 일이 있었건 운영체제가 못하면 null을 리턴함
		int* Newint = new int();

		// 습관을 들여놔야함
		if (nullptr == Newint)
		{
			// 한계에 도달하면 null이 나올때가 있음
			// 중단점도 꼭 걸어두기
			return;
		}
		// 힙을 쓰기 전에도 nullptr인지 체크하는 습관!!!!!!!!
		*Newint = 20;

		delete Newint;
	}

	// 지운거 또 지우면 위험함
	// 댕글링 포인터라고 합니다.
	{
		int* Newint = new int();
		delete Newint;
		// delete Newint; // 터지게 된다. == "메모리 크러쉬"가 발생한다고 한다.
	}

	{
		int* Newint = new int(10);
		
		// 안전한 삭제
		if (nullptr != Newint)
		{
			delete Newint;
			Newint = nullptr;
			// 지우면 null로 바꿔주는게 좋음  
		}
	}

	// null Reference Exception
	// Reference가 null인데 참조하면 터짐
	// 게임이 튕긴다고한다.
	{
		int* Test = nullptr;
		Reference(*Test);
	}
}

void Reference(int& _Value)
{
	_Value = 0;
}