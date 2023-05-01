#include "ConsoleObjectManager.h"
#include "ConsoleGameScreen.h"
std::vector<std::list<ConsoleGameObject*>> ConsoleObjectManager::AllObject;

ConsoleObjectManager::ConsoleObjectManager()
{

}

ConsoleObjectManager::~ConsoleObjectManager()
{

}

// list의 for문(순회) 방법 1.
void ConsoleObjectManager::ConsoleAllObjectUpdate()
{
	// std::vector
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		// std::list
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();
		for (; Start != End; ++Start)
		{
			ConsoleGameObject* Object = *Start;
				
			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}
			Object->Update();
		}
	}

}


// list의 for문(순회) 방법 2.
void ConsoleObjectManager::ConsoleAllObjectRender()
{
	ConsoleGameScreen::GetMainScreen().ScreenClear();

	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];
			for (ConsoleGameObject* Object : Group)
			{
				if (nullptr == Object || false == Object->IsUpdate())
				{
					continue;
				}
				Object->Render();
			}
	}
	ConsoleGameScreen::GetMainScreen().ScreenPrint();
}

void ConsoleObjectManager::ConsoleAllObjectRelease()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		// iterator로 for문을 돌렸을 때 내부에서 삭제가 용이하기 때문에
		// 보통 삭제 체크를 할 때 iterator로 순회를 합니다.
		for ( ; Start != End; /*++Start*/)
		{
			ConsoleGameObject* Object = *Start;
			// 일반적으로 for문을 돌리면 여기서 오류 발생
			if (nullptr == Object || false == Object->IsDeath())
			{
				// 램에서 어떻게 동작하는지 그려보기
				// 오류 해결을 위해 ++Start는 if문 안에서 실행해야합니다.
				// for문에서 ++Start를 하면 erase를 하고 난 뒤
				// Start와 End가 (두 iterator가) 같은 End노드를 가리켜야 하는데
				// for문에서 ++Start가 되어버리면 Start(iterator)가 End(iterator)를 한 칸 넘어서 허공을 가리키기 때문에
				// 잘못된 접근으로 오류 발생
				++Start;
				continue;
			}
			// 삭제가 되면
			// iterator가 허공을 가리키고 있음
			// 그래서 iterator가 가리키는 대상을 현재 Node의 Next로 바꿔줘야함
			// 그 기능의 구현은 erase함수 안에 구현되어 있음
			Start = Group.erase(Start);
			delete Object;
			Object = nullptr;
		}
	}
}

void ConsoleObjectManager::ConsoleAllObjectDelete()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for ( ; Start != End; ++Start)
		{
			ConsoleGameObject* Object = *Start;
			if (nullptr == Object)
			{
				continue;
			}
			delete Object;
			Object = nullptr;
		}
	}
}