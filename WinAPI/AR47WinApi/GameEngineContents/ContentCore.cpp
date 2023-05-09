#include "ContentCore.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include "EndingLevel.h"

ContentCore::ContentCore()
{

}

ContentCore::~ContentCore()
{

}

void ContentCore::Start()
{
	// 700, 800 or 1360x768
	GameEngineWindow::MainWindow.SetPosAndScale({ 0, 0 }, { 1360, 768 });

	// GameEngineCore의 EngineStart가 실행되는 순간
	// 윈도우창이 만들어지고 Process(ContentCore)의 Start()가 호출되면서
	// TitleLevel, PlayLevel, EndingLevel을 만듦
	// 이 방식은 ContentCore가 CoreProcess(->GameEngineObject)를 상속받으면서
	// virtual함수인 Start, Update, Render, Release함수를 재정의하여
	// 컨텐츠에 있는 함수들을 호출하는 방식으로 작동함

	// 이런 방식은 함수 포인터를 쓴것과 다를바가 없음
	// GameEnginePlatform에서는 함수포인터를 직접 인자로 받아서 사용하였음
	// void GameEngineWindow::MessageLoop(HINSTANCE _Inst, void(*_Start)(HINSTANCE), void(*_Update)(), void(*_End)())
	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::CreateLevel<EndingLevel>("EndingLevel");

	// 이 레벨이 화면에 보여라.
	GameEngineCore::ChangeLevel("PlayLevel");
}

// 행동한고.
void ContentCore::Update(float _Delta)
{
}

// 그려지고.
void ContentCore::Render()
{
}

// 정리된다.
void ContentCore::Release()
{
}