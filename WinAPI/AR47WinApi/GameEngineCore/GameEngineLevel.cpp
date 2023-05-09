#include "GameEngineLevel.h"
#include "GameEngineCamera.h"

GameEngineLevel::GameEngineLevel()
{
	MainCamera = new GameEngineCamera();
	UICamera = new GameEngineCamera();
}

GameEngineLevel::~GameEngineLevel()
{
	if (nullptr != MainCamera)
	{
		delete MainCamera;
		MainCamera = nullptr;
	}

	if (nullptr != UICamera)
	{
		delete UICamera;
		UICamera = nullptr;
	}
	//std::map<const int, std::list<GameEngineActor*>>::iterator Start = AllActors.begin();
	//std::map<const int, std::list<GameEngineActor*>>::iterator End = AllActors.end();
	//for (; Start != End; ++Start)
	//{
	//	std::list<GameEngineActor*>& Group = Start.operator*().second;
	//	std::list<GameEngineActor*>::iterator Start = Group.begin();
	//	std::list<GameEngineActor*>::iterator End = Group.end();
	//	for (; Start != End ;++Start)
	//	{
	//		GameEngineActor* _Actor = *Start;
	//		if (nullptr != _Actor)
	//		{
	//			delete _Actor;
	//			_Actor = nullptr;
	//		}
	//	}
	//}

	// Level이 삭제될 때
	// Level에 존재하는 모든 Actor들을 Ranged for 돌면서 삭제
	for (const std::pair<int, std::list<GameEngineActor*>>& _Pair : AllActors)
	{
		const std::list<GameEngineActor*>& Group = _Pair.second;
		for (GameEngineActor* _Actor : Group)
		{
			if (nullptr != _Actor)
			{
				delete _Actor;
				_Actor = nullptr;
			}
		}
	}
}

void GameEngineLevel::ActorInit(GameEngineActor* _Actor)
{
	// 나를 만들어준 Level을 Actor는 알아야함
	_Actor->Level = this;

	// Actor(존재)가 만들어지면 준비가 필요함
	// Start()함수를 실행하여 준비를 하는 단계임
	// 만약 업데이트에서 준비를 하게되면 계속 새로 초기화하고.... << 로딩이 오래걸림
	_Actor->Start();
}

// Level에 속하는 Actor들을 Update & Render해주는 역할은 해당 Level이 해야함
void GameEngineLevel::ActorUpdate(float _Delta)
{
	//std::map<int, std::list<GameEngineActor*>>::iterator Start = AllActors.begin();
	//std::map<int, std::list<GameEngineActor*>>::iterator End = AllActors.end();
	//for (;Start != End; ++Start)
	//{

	//}

	for (const std::pair<int, std::list<GameEngineActor*>>& _Pair : AllActors)
	{
		const std::list<GameEngineActor*>& Group = _Pair.second;
		for (GameEngineActor* _Actor : Group)
		{
			_Actor->Update(_Delta);
		}
	}
}

void GameEngineLevel::ActorRender()
{
	for (const std::pair<int, std::list<GameEngineActor*>>& _Pair : AllActors)
	{
		const std::list<GameEngineActor*>& Group = _Pair.second;
		for (GameEngineActor* _Actor : Group)
		{
			_Actor->Render();
		}
	}
}