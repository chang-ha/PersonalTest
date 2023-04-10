#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleObjectManager
{
private:
	static GameEngineArray<GameEngineArray<ConsoleGameObject*>> AllObject;
public:
	template<typename ObjectType>
	// Order�� �׷��� ����
	// ���� �׷��� �ִ�.
	// �÷��̾� �׷��� �ִ�.
	// ��ź �׷��� �ִ�.
	static ObjectType* CreateConsoleObject(int _Order)
	{
		//ObjectType* NewObject = new ObjectType();

		// AllObject�� �ڷ����� GameEngineArray<ConsoleGameObject*>

		// &�Ⱥ��̸� ������ ���ο� GameEngineArray�� ������
		// AllObject�� ó���� ����ִ� �迭
		// 0�� �׷��� ���� �ֱ� ���ؼ� AllObject�迭�� ũ�⸦ �÷�����
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

	// ���ڸ� �Ź� (int)�ϱ� �������� 
	// ���ڸ� 2���� ���� �� �ְ� ����
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

