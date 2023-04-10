#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <conio.h>
#include "Player.h"
#include "Bomb.h"
#include "GameEnum.h"
#include "ConsoleObjectManager.h"


int main()
{
	GameEngineDebug::LeckCheck();
	int2 ScreenSize = { 20, 10 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	// 업캐스팅
	// 이유 1. 인터페이스 통일
	//		이 프레임워크 상의 모든 존재들은 업데이트와 랜더라는 인터페이스를 따른다
	//ConsoleGameObject* NewPlayer = new Player();

	// 0번 그룹에 속한다
	// CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
	// 1번 그룹에 속한다
	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);
	// 2번 그룹에 속한다
	//CreateConsoleObject<Monster>(2);

	while (Player::IsGameUpdate)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();


		Sleep(200);
	}
	ConsoleObjectManager::ConsoleAllObjectDelete();

}