#include "GameEngineCore.h"
#include "GameEngineLevel.h"
// WindowTitle의 실체를 만듦
std::string GameEngineCore::WindowTitle = "";
// AllLevel의 실체를 만듦
std::map<std::string, GameEngineLevel*> GameEngineCore::AllLevel;
// Process의 실체를 만듦
CoreProcess* GameEngineCore::Process = nullptr;
// CurLevel의 실체를 만듦
GameEngineLevel* GameEngineCore::CurLevel = nullptr;
// NextLevel의 실체를 만듦
GameEngineLevel* GameEngineCore::NextLevel = nullptr;

GameEngineCore::GameEngineCore()
{

}

GameEngineCore::~GameEngineCore()
{

}

void GameEngineCore::EngineStart(const std::string& _Title, HINSTANCE _Inst, CoreProcess* _Ptr)
{
	// 메모리누수 체크
	GameEngineDebug::LeckCheck();

	Process = _Ptr;
	// 인자로 받은 _Title명을 WindowTitle에 저장
	WindowTitle = _Title;
	// 윈도우창이 꺼지지 않도록 무한루프
	GameEngineWindow::MessageLoop(_Inst, CoreStart, CoreUpdate, CoreEnd);
}

void GameEngineCore::CoreStart(HINSTANCE _Inst)
{
	// 엔진쪽에서 준비할 부분을 다 준비
	// 시작하면 윈도우창을 띄움
	GameEngineWindow::MainWindow.Open(WindowTitle, _Inst);

	// 엔진부분은 준비 완료상태, 이제 컨텐츠 부분을 준비해준다.
	Process->Start();
}

void GameEngineCore::CoreUpdate()
{
	// MessageLoop함수에서 호출됨
	// 윈도우창에 메세지가 들어오면 호출되는 부분임
	if (nullptr != NextLevel)
	{
		// NextLevel이 존재하면
		// CurLevel을 NextLevel로 바꿔줌
		CurLevel = NextLevel;
		NextLevel = nullptr;
	}

	// CurLevel부분을 Update 및 Render
	CurLevel->Update();
	CurLevel->ActorUpdate();
	CurLevel->Render();
	CurLevel->ActorRender();
}

void GameEngineCore::CoreEnd()
{
	// MessageLoop에서 while문(프로그램)이 끝난 뒤 End가 호출될 때
	// End에 CoreEnd 함수 포인터를 넘겨서 해당 함수를 호출
	// Process(CoreProcess <- ContentCore)를 Release()
	// Level을 삭제함
	Process->Release();

	if (nullptr != Process)
	{
		delete Process;
		Process = nullptr;
	}

	// Ranged for 돌면서 Level을 모두 삭제
	for (std::pair<std::string, GameEngineLevel*> _Pair : AllLevel)
	{
		if (nullptr != _Pair.second)
		{
			delete _Pair.second;
			_Pair.second = nullptr;
		}
	}
}

// Level의 Start()를 호출하기 위한 함수
// 포인터를 넘기는 함수일 뿐임
void GameEngineCore::LevelInit(GameEngineLevel* _Level)
{
	_Level->Start();
}