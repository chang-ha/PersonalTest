#include "GameEngineTime.h"

GameEngineTime GameEngineTime::MainTimer;

GameEngineTime::GameEngineTime()
{
	QueryPerformanceFrequency(&Count); // 1초에 몇 번 셀수있는지 알려주는 함수
	// QueryPerformanceCounter(&Cur); // 지금까지(컴퓨터가 켜지고) 몇 번 세었는지 알려주는 함수
	Reset(); // MainTimer가 만들어질때 현재까지 몇 번 세었는지 저장해서 Prev에 저장
}

GameEngineTime::~GameEngineTime()
{

}

void GameEngineTime::Reset()
{
	// 현재 시간까지의 Tick값을 저장
	QueryPerformanceCounter(&Cur);
	// 이전 Tick값을 현재 Tick값으로 세팅
	Prev = Cur;
}

// 프레임 사이에서 실행되어야할 함수들은 다 업데이트라고 이름을 지을 것이다.
void GameEngineTime::Update()
{
	// 현재 시간까지의 Tick값을 저장
	QueryPerformanceCounter(&Cur);

	// 현재 시간과 이전 시간의 Tick차이값을 저장함
	Tick = Cur.QuadPart - Prev.QuadPart;

	// double은 8바이트 실수형 << 더 작은 소수점까지 표현가능
	// 계산할때는 double로 casting해서 계산해야함 << 안하면 소수점은 전부 버려짐
	// 현재 시간과 이전 시간에서의 Tick차이값 /  초당 몇 번 셀수있는지의 값
	DoubleDelta = static_cast<double>(Tick) / static_cast<double>(Count.QuadPart);

	// 이전 Tick값을 현재 Tick값으로 세팅
	// (현재 시간은 계속 흘러가는 중)
	Prev.QuadPart = Cur.QuadPart;
	FloatDelta = static_cast<float>(DoubleDelta);
}

