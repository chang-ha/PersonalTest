#pragma once
#include <string>
#include <map>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "GameEngineObject.h"
// 윈도우를 직접 조종하는 라이브러리
// 사용자가 직접 hInstance를 받아서 어쩌구... 할 필요가 없음
// 엔진을 쓸 떄 윈도우를 사용자가 직접 조작해야 하는 경우는 없음

// 엔진 입장에서는 유저가 무슨 게임을 만들지를 알 수가 없음(그렇다고 컨텐츠부분을 알면 안됨)
// 함수포인터(Virtual함수)로 해결이 가능
// Content 부분을 만들 떄 CoreProcess를 상속받아서 만들어
// Content부분에서 만든 함수를 엔진부분(Core)에서 대신 호출해줄게
class CoreProcess : public GameEngineObject
{
	// GameEngineObject는
	// 1. Start, 2. Update, 3.Render, 4.Release 가상함수들을 들고있으므로
	// 자식클래스들은 위 함수들을 재정의 가능
};

// 전방선언
class GameEngineLevel;
class GameEngineCore
{
public:
	// constructer destructer
	GameEngineCore();
	~GameEngineCore();

	// delete function
	GameEngineCore(const GameEngineCore& _Ohter) = delete;
	GameEngineCore(GameEngineCore&& _Ohter) noexcept = delete;
	GameEngineCore& operator=(const GameEngineCore& _Other) = delete;
	GameEngineCore& operator=(GameEngineCore&& _Other) noexcept = delete;

	// 프로그램을 시작하는 함수
	template <typename CoreProcessType>
	static void EngineStart(const std::string& _Title, HINSTANCE _Inst)
	{
		//
		EngineStart(_Title, _Inst, new CoreProcessType());
	}

	// 컨텐츠에서 Level을 만들기위한 함수
	template<typename LevelType>
	static void CreateLevel(const std::string& _Name)
	{
		// 모든 문자열은 대문자로 하여 관리할 것임 (소문자, 대문자 표기 오류를 방지)
		std::string Upper = GameEngineString::ToUpperReturn(_Name);

		// 이미 해당 Level이 존재하므로 새로 Create불가능
		if (AllLevel.end() != AllLevel.find(Upper))
		{
			MsgBoxAssert(Upper + "의 이름을 가진 GameEngineLevel은 이미 존재합니다.");
			return;
		}
		
		// 새로운 Level(장면)을 만들고, 초기화한후 map에 insert
		GameEngineLevel* NewLevel = new LevelType();
		// NewLevel->Start()를 하고싶지만, Level의 헤더를 모르게하기 위해
		// LevelInit함수를 만들어서 Start()를 호출
		LevelInit(NewLevel);
		AllLevel.insert(std::make_pair(Upper, NewLevel));
	}

	// Level(장면)을 전환하기 위한 함수
	static void ChangeLevel(const std::string& _Name)
	{
		std::string Upper = GameEngineString::ToUpperReturn(_Name);
		std::map<std::string, GameEngineLevel*>::iterator Finditer = AllLevel.find(Upper);

		if (AllLevel.end() == Finditer)
		{
			MsgBoxAssert(Upper + "의 이름을 가진 GameEngineLevel은 존재하지 않습니다.");
			return;
		}

		NextLevel = Finditer->second;
	}
protected:

private:
	// 메인에서 Title명을 정해줄 떄, 해당 Title명을 저장할 WindowTitle(static 변수) 선언
	static std::string WindowTitle;
	static CoreProcess* Process;

	// Level의 Start()를 호출하기 위한 함수
	static void LevelInit(GameEngineLevel* _Level);
	// CoreProcess클래스의 포인터값을 넣어줘야함
	static void EngineStart(const std::string& _Title, HINSTANCE _Inst, CoreProcess* _Ptr);
	// 프로그램이 실행되면 처음 해야할 일들을 실행
	static void CoreStart(HINSTANCE _Inst);
	// 프로그램중 실시간 업데이트가 일어나야할 일들을 실행
	static void CoreUpdate();
	// 프로그램이 끝나면 마무리해야할 일들을 실행(메모리 정리 등)
	static void CoreEnd();
	// 모든 컨텐츠 Level을 저장할 map형식 자료구조 선언
	static std::map<std::string, GameEngineLevel*> AllLevel;
	static GameEngineLevel* CurLevel;
	static GameEngineLevel* NextLevel;
};

