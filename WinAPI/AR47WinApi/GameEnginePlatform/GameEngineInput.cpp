#include "GameEngineInput.h"


GameEngineInput::GameEngineInput()
{

}

GameEngineInput::~GameEngineInput()
{

}

void GameEngineInput::GameEngineKey::Update(float _DeltaTime)
{
	// 키가 눌렸다면
	if (true == KeyCheck())
	{
		PressTime += _DeltaTime;

		// 여태까지 키가 눌렸던 적이 없음
		if (true == Free)
		{
			Down = true;
			Press = true;
			Up = false;
			Free = false;
		}
		else if (true == Down)
		{
			Down = false;
			Press = true;
			Up = false;
			Free = false;
		}
	}
	else // 키가 눌리지 않았다.
	{
		PressTime = 0.0f;
		// 방금전까지 키를 누르고 있었다가 이제 땟다
		if (true == Press)
		{
			Down = false;
			Press = false;
			Up = true;
			Free = true;
		}
		else if (true == Up)
		{
			Down = false;
			Press = false;
			Up = false;
			Free = true;
		}
	}
}