#include "GameEngineTime.h"
#include <Windows.h>

GameEngineTime GameEngineTime::MainTimer;

GameEngineTime::GameEngineTime()
{
	QueryPerformanceFrequency(&Count); // 1초에 몇 번 셀수있는지 알려주는 함수
	QueryPerformanceCounter(&Cur); // 지금까지(컴퓨터가 켜지고) 몇 번 세었는지 알려주는 함수
}

GameEngineTime::~GameEngineTime()
{

}