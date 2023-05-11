#pragma once
#include <Windows.h>
#include <map>
#include <string>
// 윈도우에 들어오는 Input값을 해당 클래스를 통해 움직임 등을 처리할 것임
class GameEngineInput
{
private:
	// 키 하나를 체크하게 됨( A키, B키 등등...)
	class GameEngineKey
	{
		// 상태를 체크하기 위한 멤버변수들

		// Down은 누르는 순간 한번만 체크함
		bool Down = false;
		// 키를 계속 누르고 있는지 체크함
		bool Press = false;
		// 키를 떼는 순간 한번만 체크함
		bool Up = false;
		// 안누르고 있다.
		bool Free = true;
		// 해당 키를 몇 초간 눌렀는지?
		float PressTime = 0.0f;

		int Key = -1;
		bool KeyCheck()
		{
			return 0 != GetAsyncKeyState(Key);
		}

		void Update(float _DeltaTime);
	};
public:
	// constructer destructer
	GameEngineInput();
	~GameEngineInput();

	// delete function
	GameEngineInput(const GameEngineInput& _Ohter) = delete;
	GameEngineInput(GameEngineInput&& _Ohter) noexcept = delete;
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput&& _Other) noexcept = delete;

protected:

private:
	static std::map <std::string, GameEngineKey> AllKeys;
};

