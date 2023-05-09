#pragma once
#include <map>
#include <list>
#include "GameEngineRenderer.h"
// 카메라가 누군가를 관측하기 떄문에 화면에 누군가가 나온다.
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
	// 화면에 이미지를 그려주는 역할은 카메라와 Renderer가 담당
	std::map<int, std::list<GameEngineRenderer*>> Renderers;
};

