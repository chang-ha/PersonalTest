#pragma once
#include "GameEngineObject.h"

// ���� : ȭ��Ȥ�� ����� ǥ���մϴ�.
// Ÿ��Ʋ ���
// �÷��� ���
// ���� ���
class GameEngineLevel : public GameEngineObject
{
public:
	// constructer destructer
	GameEngineLevel();
	~GameEngineLevel();

	// delete function
	GameEngineLevel(const GameEngineLevel& _Ohter) = delete;
	GameEngineLevel(GameEngineLevel&& _Ohter) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:

private:

};

