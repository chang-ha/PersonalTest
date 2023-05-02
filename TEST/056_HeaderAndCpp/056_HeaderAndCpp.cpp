// 056_HeaderAndCpp


#include <iostream>
// c++정식 해더 확장자는 hpp
// 아무도 쓰지를 않는다.
// c하던 사람들이 다 c++로 넘어왔고
// 초반에 c++위원회는 c와의 호환성을 강조했다.

//#include "Player.hpp"

#include "Player.h"
#include "Player.h"
#include "Player.h"
#include "Monster.h"
// int Value = 10;

// #pragma once
// 한 cpp파일내의 헤더 중복 제거.
//#include "Player.h"
//#include "Player.h"
//#include "Player.h"
//#include "Player.h"
//#include "Player.h"
//#include "Player.h"
//#include "Player.h"
//#include "Player.h"
//#include "Player.h"

// 위 영역은 선언 (header파일 불러옴)
// 컴파일러는 2가지 처리를 합니다.
// "먼저 Cpp들을 다 검사한다."
// 헤더들을 모아서 main위에 올려놓습니다. (하나의 파일에 모아둔다)
// 내가 친 모든 코드는 하나의 프로젝트(1개의 파일로) 응축되게 됩니다.

int main()
{
    Player NewPlayer = Player();

    NewPlayer.Damage(10);

    Monster NewMonster = Monster();

    // 내가 사용하지 않는건 컴파일러가 맘대로 지워버릴때가 있기 때문에
    // 사용을해야 오류가 발생 (사용하지 않으면 최적화 때문에 컴파일러가 목록에서 빼버림)
    // Monster::MonsterCount = 10;

}
// 아래 영역은 구현 (cpp파일을 불러움)