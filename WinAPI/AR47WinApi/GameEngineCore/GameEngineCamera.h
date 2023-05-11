#pragma once
#include <map>
#include <list>
#include "GameEngineRenderer.h"

// 카메라가 누군가를 관측하기 떄문에 화면에 누군가가 나온다.
class GameEngineLevel;
class GameEngineActor;
class GameEngineCamera
{
	friend GameEngineLevel;
	friend GameEngineActor;
public:
	// constructer destructer
	GameEngineCamera();
	~GameEngineCamera();

	// delete function
	GameEngineCamera(const GameEngineCamera& _Ohter) = delete;
	GameEngineCamera(GameEngineCamera&& _Ohter) noexcept = delete;
	GameEngineCamera& operator=(const GameEngineCamera& _Other) = delete;
	GameEngineCamera& operator=(GameEngineCamera&& _Other) noexcept = delete;

	float4 GetPos()
	{
		return Pos;
	}

	void SetPos(const float4& _Pos)
	{
		Pos = _Pos;
	}

	void AddPos(const float4& _AddPos)
	{
		Pos += _AddPos;
	}

protected:

private:
	// 카메라가 비추고 있는 Pos (최초에는 0,0)
	float4 Pos = float4::ZERO;

	// 화면에 이미지를 그려주는 역할은 카메라와 Renderer가 담당
	std::map<int, std::list<GameEngineRenderer*>> Renderers;

	// 카메라에 Renderer를 넣어서 관리
	void PushRenderer(GameEngineRenderer* _Renderer, int _Order);

	// 해당 카메라에 들어온 Renderer만 Render하는 구조로 작성
	void Render();

	void Release();
};

