#pragma once
#include <map>
#include <list>
#include "GameEngineObject.h"
#include "GameEngineActor.h"
#include <string>

// ���� : ȭ�� Ȥ�� ����� ǥ���մϴ�.
// Ÿ��Ʋ ���, �÷��� ���, ���� ���
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
		// �ڷᱸ���� �ϴٺ��� �Ʒ��� ���� ��Ȳ�� �������� ���� 
		// ���� � �ڷḦ ã�ƺôµ� ���� -> �׷� �װ� ���� �ڷᱸ���� �־����
		// _Order�� �׷��� ����� �� �׷쿡 Actor�� �־�����ϴ� ��Ȳ��
		// �׷����� �Ʒ�ó���� ���� ���� ������ 
		
		//std::map<int, std::list<GameEngineActor*>>::iterator FindIter = AllActors.find(_Order);
		//if (AllActors.end() == AllActors.find(_Order))
		//{
		//	// _Order�� �׷��� ���ٸ�( == AllActors.end())
		//	// _Order�� �׷��� ������
		//	AllActors.insert(std::make_pair(_Order, std::list<GameEngineActor*>));
		//	FindIter = AllActors.find(_Order);
		//}
		// std::list<GameEngineActor*>& GroupList = FindIter.second;
		
		// map�� listó�� �ڷ����� �����ϰ� operator[] �Ǿ�����
		// �Ʒ�ó�� ����ϸ�
		// ���� �� �ȿ� �ش� Key�� ���� �ڷᰡ ������ �ش� ���� return���ְ�
		// �ش� Key���� ���� �ڷᰡ ������ ���� �ش� ���� return����
		std::list<GameEngineActor*>& GroupList = AllActors[_Order];

		// GameEngineActor�� ActorType�� upcasting�ؼ� �� �޸𸮿� �����Ҵ�
		GameEngineActor* NewActor = new ActorType();

		ActorInit(NewActor);
		GroupList.push_back(NewActor);
		return dynamic_cast<ActorType*>(NewActor);
	}
protected:

private:
	GameEngineCamera* MainCamera;
	GameEngineCamera* UICamera;

	// ��, �÷��̾�, ���� ���Ͱ� �ʿ��ϴٰ�(�������Ѵٰ�) ����
	
	// list�� �����͸� ���� �� ����� ������ �߿���!!
	// ���� ���� �ε��Ǿ���ϸ� ���� ���� ���� list�� push_back�ؾ��ϰ� ... ��
	// list�� ����� �ʹ� ���� ��ȿ�����̰� ����� �Ǽ��� ���ɼ��� ����(��� ����� 0������ ���� ���������� �˾ƾ���...)
	
	// �׷��� map �ڷᱸ���� �̿��ϱ�� ��
	// map�� for��(ranged for)�� ������ ������������ ���ĵǴ� ��ó�� �������� ���� << ���������̳� & iterator�� ������ȸ�� ���ư�
	// �ִ� ������ �߿����� ����

	// Key���� int, Value���� std::list<GameEngineActor*>�� ���� map�� ����
	std::map <int, std::list<GameEngineActor*>> AllActors;

	void ActorInit(GameEngineActor* _Actor);

	// �ش� Level�� �����ϴ� ��� Actor���� Update & Render �������
	void ActorUpdate(float _Delta);
	void ActorRender();
};

