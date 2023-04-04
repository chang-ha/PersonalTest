// 064_Heap

#include <crtdbg.h>

class Monster
{

};
int main()
{
	// 동적메모리 (힙영역에 들어감)
	// 연산자   자료형   생성자
	//  new    자료형     ();

	// 힙은 가장 자유롭게 메모리를 할당할 수 있는 영역입니다.
	new int(); // << 힙 영역에 int 하나가 생김

	// 보통 이름이 주소값
	int Value = 20;

	// int를 계속 만들어서 메모리가 계속 늘어남
	//while (true)
	//{
	//	new int();
	//}

	// new int();
	// new int()는 가만히 내버려두면 잃어버림 << 절대로 못씀
	// 받지 않으면 잃어버렸다고 표현함
	// new int는 한번 무조건 받아야함 (주소값으로 받아야함)
	// 그래서 힙영역은 포인터로받게 받을수 없음
	int* Ptr = new int(); // == operator new() int();
	*Ptr = 20;

	// 외워야한다
	// 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시.
	// 힙은 자동으로 지워지지 않기 때문에 알아서 지워야하는데
	// 안지운 힙 메모리를 알려줌
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 잃어버린 힙은 절대 지울수가 없음
	// 지우지 않으면 Leak or 메모리 누수가 났다고 표현함
	// 그것때문에 프로그램을 종료해도 윈도우가 느려지는 경우는 없다.
	// 그치만 프로그램이 느려질 순 없다.
	delete Ptr;

	// 참고로 강제로 종료하면 삭제되지 않음 == Leak이 날수밖에 없음 << 어쩔수 없음
	// 크게 신경쓸 필요는 없음
	Monster* PtrMonster = new Monster();
	//while (true)
	//{

	//}
	delete PtrMonster;

	// Monster& PtrMonster = new Monster();

}