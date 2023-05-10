#pragma once
#include <Windows.h>

// 윈도우에 들어오는 Input값을 해당 클래스를 통해 움직임 등을 처리할 것임
class GameEngineInput
{
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

};

