#pragma once

class GameEngineTime
{
public:
	// 싱글톤 패턴
	static GameEngineTime MainTimer;

	// constructer destructer
	GameEngineTime();
	~GameEngineTime();

	// delete function
	GameEngineTime(const GameEngineTime& _Ohter) = delete;
	GameEngineTime(GameEngineTime&& _Ohter) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime&& _Other) noexcept = delete;

protected:

private:
	LARGE_INTEGER Count; // 1초에 몇 번 셀수있어?
	LARGE_INTEGER Cur; // 지금까지 몇 번 세었어?
	LARGE_INTEGER Prev; // 이전에는 몇 번 세었어??
};

