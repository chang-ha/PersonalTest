// 금일 강의 내용 : Header & Cpp

// c++에서 정식 헤더 확장자는 hpp
// 아무도 쓰지를 않는다 << C하던 사람들이 다 C++로 넘어와서 
#include "Player.h"
#include "Monster.h"

// 위 영역은 선언 (header파일 불러옴)
int main()
{
	// 컴파일러는 2가지 처리를 합니다.
	// 먼저 Cpp들을 다 검사한다.
	// 헤더들을 모아서 main위에 올려놓습니다. (하나의 파일에 모아둔다)
	// 내가 친 모든 코드는 하나의 프로젝트(1개의 파일로) 응축되게 됩니다.

	Player NewPlayer = Player();

	// 사용을해야 오류가 발생 (사용하지 않으면 최적화 때문에 컴파일러가 목록에서 빼버림)
	Monster::MonsterCount = 20;
	NewPlayer.Damage(10);
}

// 아래 영역은 구현 (cpp파일을 불러움)