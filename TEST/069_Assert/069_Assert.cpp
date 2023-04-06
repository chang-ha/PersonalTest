// 069_Assert



#include "BaseHeader.h"
#include "Player.h"

int main()
{
	// 								    	MB_OK = 확인버튼 한개 나오게
	//MessageBoxA(nullptr, "내용", "제목", MB_OK);
	//// assert가 false면 프로그램이 터지게 만듬
	//// 다시시도 누르면 어디가 터진지 알려줌
	//assert(false);
	Player NewPlayer{};
	NewPlayer.Damage(0);
}
