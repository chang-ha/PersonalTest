#pragma once
#include <map>
#include <list>
#include "GameEngineRenderer.h"
// ī�޶� �������� �����ϱ� ������ ȭ�鿡 �������� ���´�.
class GameEngineCamera
{
public:
	// constructer destructer
	GameEngineCamera();
	~GameEngineCamera();

	// delete function
	GameEngineCamera(const GameEngineCamera& _Ohter) = delete;
	GameEngineCamera(GameEngineCamera&& _Ohter) noexcept = delete;
	GameEngineCamera& operator=(const GameEngineCamera& _Other) = delete;
	GameEngineCamera& operator=(GameEngineCamera&& _Other) noexcept = delete;

protected:

private:
	// ȭ�鿡 �̹����� �׷��ִ� ������ ī�޶�� Renderer�� ���
	std::map<int, std::list<GameEngineRenderer*>> Renderers;
};

