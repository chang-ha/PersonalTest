#pragma once
#include <Windows.h>

// �����쿡 ������ Input���� �ش� Ŭ������ ���� ������ ���� ó���� ����
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

