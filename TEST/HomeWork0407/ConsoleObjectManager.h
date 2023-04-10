#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleObjectManager
{
private:
	static GameEngineArray<GameEngineArray<ConsoleGameObject*>> AllObject;
public:
	template<typename ObjectType>
	// Order는 그룹의 순서
	// 몬스터 그룹이 있다.
	// 플레이어 그룹이 있다.
	// 폭탄 그룹이 있다.
	static ObjectType* CreateConsoleObject(int _Order)
	{
		//ObjectType* NewObject = new ObjectType();

		// AllObject의 자료형은 GameEngineArray<ConsoleGameObject*>

		// &안붙이면 완전히 새로운 GameEngineArray가 생성됨
		// AllObject는 처음에 비어있는 배열
		// 0번 그룹을 만들어서 넣기 위해서 AllObject배열의 크기를 늘려야함
		if (_Order >= AllObject.Count())
		{
			AllObject.ReSize(_Order + 1);
		}
		GameEngineArray<ConsoleGameObject*>& Group = AllObject[_Order];

		ObjectType* NewObject = new ObjectType();

		Group.ReSize(Group.Count() + 1);

		Group[Group.Count() - 1] = NewObject;

		return NewObject;
	}

	// 인자를 매번 (int)하기 귀찮으니 
	// 인자를 2종류 받을 수 있게 만듦
	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		return CreateConsoleObject<ObjectType>((int)_Order);
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectDelete();

	static GameEngineArray<ConsoleGameObject*>& GetGroup(int _Order)
	{
		return AllObject[_Order];
	}

private:
	// constructer destructer
	ConsoleObjectManager();
	~ConsoleObjectManager();

	// delete function
	ConsoleObjectManager(const ConsoleObjectManager& _Ohter) = delete;
	ConsoleObjectManager(ConsoleObjectManager&& _Ohter) noexcept = delete;
	ConsoleObjectManager& operator=(const ConsoleObjectManager& _Other) = delete;
	ConsoleObjectManager& operator=(ConsoleObjectManager&& _Other) noexcept = delete;

protected:

private:

};

