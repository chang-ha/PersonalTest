#pragma once
#include <Windows.h>

class GameEngineTime
{
public:
	static GameEngineTime MainTimer;

	// constructer destructer
	GameEngineTime();
	~GameEngineTime();

	// delete function
	GameEngineTime(const GameEngineTime& _Ohter) = delete;
	GameEngineTime(GameEngineTime&& _Ohter) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime&& _Other) noexcept = delete;

	// 흐른 시간(float)를 return해주는 멤버함수
	float GetDeltaTime()
	{
		return FloatDelta;
	}

	// 지금까지 세었던 시간을 초기화하는 멤버함수 
	void Reset();

	// 한 프레임이 지나는 동안 흐른 시간을 DoubleDelta, FloatDelta에 저장하는 함수
	void Update();
protected:

private:
	LARGE_INTEGER Count = { 0 }; // 1초에 몇 번 셀수있는지 저장하는 멤버변수
	LARGE_INTEGER Cur = { 0 }; // 지금까지 몇 번 세었는지 저장하는 멤버변수
	LARGE_INTEGER Prev = { 0 }; // 이전에는 몇 번 세었는지 저장하는 멤버변수
	__int64 Tick; // Tick(몇 번 세었는지) 차이값을 저장하기 위한 멤버변수
	double DoubleDelta; // 흐른 시간을 double로 저장하는 멤버변수
	float FloatDelta; // 흐른 시간을 float로 저장하는 멤버변수
};

