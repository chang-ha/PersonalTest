#include "GameEngineLevel.h"
#include "GameEngineCamera.h"
#include <GameEngineBase/GameEngineDebug.h>

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

void GameEngineLevel::ActorInit(GameEngineActor* _Actor, int _Order)
{
	// 나를 만들어준 Level을 Actor는 알아야함
	_Actor->Level = this;

	// 해당 Actor의 Order를 설정해줌
	_Actor->SetOrder(_Order);

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
			if (false == _Actor->IsUpdate())
			{
				continue;
			}

			_Actor->AddLiveTime(_Delta);
			_Actor->Update(_Delta);
		}
	}
}

void GameEngineLevel::ActorRender()
{
	MainCamera->Render();

	for (const std::pair<int, std::list<GameEngineActor*>>& _Pair : AllActors)
	{
		const std::list<GameEngineActor*>& Group = _Pair.second;
		for (GameEngineActor* _Actor : Group)
		{
			if (false == _Actor->IsUpdate())
			{
				continue;
			}
			_Actor->Render();
		}
	}
}

void GameEngineLevel::ActorRelease()
{
	MainCamera->Release();

	std::map <int, std::list<GameEngineActor*>>::iterator GroupStartIter = AllActors.begin();
	std::map <int, std::list<GameEngineActor*>>::iterator GroupEndIter = AllActors.end();

	// 조금이라도 연산을 줄이고 싶으면 위에서 미리 선언하고 아래에서는 대입만 받음 
	// std::list<GameEngineActor*>::iterator ActorStartIter;
	// std::list<GameEngineActor*>::iterator ActorEndIter;
	for (;GroupStartIter != GroupEndIter ; ++GroupStartIter)
	{
		std::list<GameEngineActor*>& Group = GroupStartIter->second;
		std::list<GameEngineActor*>::iterator ObjectStartIter = Group.begin();
		std::list<GameEngineActor*>::iterator ObjectEndIter = Group.end();
		// ActorStartIter = Group.begin();
		// ActorEndIter = Group.end();

		for ( ; ObjectStartIter != ObjectEndIter; )
		{
			GameEngineActor* Object = *ObjectStartIter;
			Object->Release();
			// 해당 오브젝트가 죽지않은 상태라면 Release를 하지 않음
			if (false == Object->IsDeath())
			{
				++ObjectStartIter;
				continue;
			}

			if (nullptr == Object)
			{
				MsgBoxAssert("null인 Object는 Release할 수 없습니다.");
			}
			delete Object;
			Object = nullptr;
			ObjectStartIter = Group.erase(ObjectStartIter);
		}
	}
}
