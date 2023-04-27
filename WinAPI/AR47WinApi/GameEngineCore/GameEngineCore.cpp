#include "GameEngineCore.h"

// WindowTitle의 실체를 만듦
std::string GameEngineCore::WindowTitle = "";
// AllLevel의 실체를 만듦
std::map<std::string, GameEngineLevel*> GameEngineCore::AllLevel;

GameEngineCore::GameEngineCore()
{

}

GameEngineCore::~GameEngineCore()
{

}

void GameEngineCore::EngineStart(const std::string& _Title, HINSTANCE _Inst)
{
	// 메모리누수 체크
	GameEngineDebug::LeckCheck();
	// 인자로 받은 _Title명을 WindowTitle에 저장
	WindowTitle = _Title;
	// 윈도우창이 꺼지지 않도록 무한루프
	GameEngineWindow::MessageLoop(_Inst, CoreStart, CoreUpdate, CoreEnd);
}

void GameEngineCore::CoreStart(HINSTANCE _Inst)
{
	// 시작하면 윈도우창을 띄움
	GameEngineWindow::MainWindow.Open(WindowTitle, _Inst);
}

void GameEngineCore::CoreUpdate()
{

}

void GameEngineCore::CoreEnd()
{

}