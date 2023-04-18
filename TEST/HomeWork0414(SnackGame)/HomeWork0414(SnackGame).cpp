// HomeWork0414(SnackGame)


#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <conio.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include <GameEngineBase/GameEngineRandom.h>

#include "Head.h"
#include "GameEnum.h"
#include "Body.h"
int main()
{
	GameEngineDebug::LeckCheck();
	int2 ScreenSize = { 5, 5 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);
	ConsoleObjectManager::CreateConsoleObject<Head>(ObjectOrder::Head);

	ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);

	while (true == Head::IsPlay)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();

		Sleep(200);
	}
	ConsoleObjectManager::ConsoleAllObjectDelete();
}