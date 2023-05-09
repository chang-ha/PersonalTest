#include "PlayLevel.h"
#include "Player.h"
#include "BackGround.h"


PlayLevel::PlayLevel()
{

}

PlayLevel::~PlayLevel()
{

}
void PlayLevel::Start()
{
	// PlayLevel의 시작
	// PlayLevel이 만들어 졌으면
	// 1. 이 레벨에는 무엇이 있어야할까??
	//    1) 맵
	//	  2) 플레이어
	//    3) 몬스터 등...
	// 그런 객체(Actor)들을 만들어야함
	// 아래처럼 만들지 않음 << 이렇게 만들면 내가 Player객체를 관리할수가없음
	// 여기서만 사용가능한 NewPlayer(자기 임의대로 만들겠다는 뜻임)
	// Player* NewPlayer = new Player();
	BackGround* Back = CreateActor<BackGround>();
	Back->Init("Title.bmp");
	Player* Farmer = CreateActor<Player>();
}

void PlayLevel::Update(float _Delta)
{

}

void PlayLevel::Render()
{
	
}

void PlayLevel::Release()
{

}