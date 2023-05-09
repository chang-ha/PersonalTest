#pragma once
#include <map>
#include <list>
#include "GameEngineObject.h"
#include "GameEngineActor.h"
#include <string>

// 설명 : 화면 혹은 장면을 표현합니다.
// 타이틀 장면, 플레이 장면, 엔딩 장면
class GameEngineCamera;
class GameEngineCore;
class GameEngineLevel : public GameEngineObject
{
	friend GameEngineCore;
	friend GameEngineActor;
public:
	// constructer destructer
	GameEngineLevel();
	~GameEngineLevel();

	// delete function
	GameEngineLevel(const GameEngineLevel& _Ohter) = delete;
	GameEngineLevel(GameEngineLevel&& _Ohter) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

	template<typename ActorType>
	ActorType* CreateActor(int _Order = 0)
	{
		// 자료구조를 하다보면 아래와 같은 상황이 있을때가 있음 
		// 내가 어떤 자료를 찾아봤는데 없다 -> 그럼 그걸 만들어서 자료구조에 넣어야함
		// _Order인 그룹을 만들고 그 그룹에 Actor를 넣어줘야하는 상황임
		// 그렇지만 아래처럼은 정말 옛날 사용법임 
		
		//std::map<int, std::list<GameEngineActor*>>::iterator FindIter = AllActors.find(_Order);
		//if (AllActors.end() == AllActors.find(_Order))
		//{
		//	// _Order인 그룹이 없다면( == AllActors.end())
		//	// _Order인 그룹을 만들어라
		//	AllActors.insert(std::make_pair(_Order, std::list<GameEngineActor*>));
		//	FindIter = AllActors.find(_Order);
		//}
		// std::list<GameEngineActor*>& GroupList = FindIter.second;
		
		// map은 list처럼 자료형에 접근하게 operator[] 되어있음
		// 아래처럼 사용하면
		// 만약 맵 안에 해당 Key를 가진 자료가 있으면 해당 값을 return해주고
		// 해당 Key값을 가진 자료가 없으면 만들어서 해당 값을 return해줌
		std::list<GameEngineActor*>& GroupList = AllActors[_Order];

		// GameEngineActor로 ActorType을 upcasting해서 힙 메모리에 동적할당
		GameEngineActor* NewActor = new ActorType();

		ActorInit(NewActor);
		GroupList.push_back(NewActor);
		return dynamic_cast<ActorType*>(NewActor);
	}
protected:

private:
	GameEngineCamera* MainCamera;
	GameEngineCamera* UICamera;

	// 맵, 플레이어, 몬스터 엑터가 필요하다고(만들어야한다고) 가정
	
	// list로 데이터를 만들 시 만드는 순서가 중요함!!
	// 맵이 먼저 로딩되어야하면 맵을 가장 먼저 list에 push_back해야하고 ... 등
	// list로 만들면 너무 일이 비효율적이고 힘들고 실수의 가능성이 높음(모든 사람이 0번으로 맵을 만들어야함을 알아야함...)
	
	// 그래서 map 자료구조를 이용하기로 함
	// map은 for문(ranged for)를 돌리면 오림차순으로 정렬되는 것처럼 느껴지기 때문 << 연관컨테이너 & iterator가 중위순회로 돌아감
	// 넣는 순서가 중요하지 않음

	// Key값은 int, Value값은 std::list<GameEngineActor*>가 들어가는 map을 만듦
	std::map <int, std::list<GameEngineActor*>> AllActors;

	void ActorInit(GameEngineActor* _Actor);

	// 해당 Level에 존재하는 모든 Actor들을 Update & Render 해줘야함
	void ActorUpdate(float _Delta);
	void ActorRender();
};

