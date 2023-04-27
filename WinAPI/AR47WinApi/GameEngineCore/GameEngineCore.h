#pragma once
#include <string>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <map>

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
	static void EngineStart(const std::string& _Title, HINSTANCE _Inst);

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

		GameEngineLevel* NewLevel = new LevelType();
		AllLevel.insert(std::make_pair(Upper, NewLevel));
	}
protected:

private:
	// 메인에서 Title명을 정해줄 떄, 해당 Title명을 저장할 WindowTitle(static 변수) 선언
	static std::string WindowTitle;

	// 프로그램이 실행되면 처음 해야할 일들을 실행
	static void CoreStart(HINSTANCE _Inst);
	// 프로그램중 실시간 업데이트가 일어나야할 일들을 실행
	static void CoreUpdate();
	// 프로그램이 끝나면 마무리해야할 일들을 실행(메모리 정리 등)
	static void CoreEnd();
	// 모든 컨텐츠 Level을 저장할 map형식 자료구조 선언
	static std::map<std::string, GameEngineLevel*> AllLevel;
};

