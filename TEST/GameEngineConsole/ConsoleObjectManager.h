#pragma once
#include "GameEngineArray.h"
#include "ConsoleGameObject.h"
#include <vector>
#include <list>

class ConsoleObjectManager
{
private:
	static std::vector<std::list<ConsoleGameObject*>> AllObject;
public:
	template<typename ObjectType>
	// Order�� �׷��� ����
	// ���� �׷��� �ִ�.
	// �÷��̾� �׷��� �ִ�.
	// ��ź �׷��� �ִ�.
	static ObjectType* CreateConsoleObject(int _Order)
	{
		// ObjectType* NewObject = new ObjectType();

		// AllObject�� �ڷ����� GameEngineArray<ConsoleGameObject*>

		// &�Ⱥ��̸� ������ ���ο� GameEngineArray�� ������
		// AllObject�� ó���� ����ִ� �迭
		// 0�� �׷��� ���� �ֱ� ���ؼ� AllObject�迭�� ũ�⸦ �÷�����
		if (_Order >= AllObject.size())
		{
			AllObject.resize(_Order + 1);
		}
		std::list<ConsoleGameObject*>& Group = AllObject[_Order];

		ObjectType* NewObject = new ObjectType();

		Group.push_back(NewObject);

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
	// object�� delete�� ���� ������� ����� �� ���� ����
	static void ConsoleAllObjectRelease();
	static void ConsoleAllObjectDelete();
	template<typename EnumType>
	static std::list<ConsoleGameObject*>& GetGroup(EnumType _Order)
	{
		return AllObject[(int)_Order];
	}

	static std::list<ConsoleGameObject*>& GetGroup(int _Order)
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

};

