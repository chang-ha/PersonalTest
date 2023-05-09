#pragma once
#include "GameEngineObject.h"
#include <GameEngineBase/GameEngineMath.h>
#include <list>
#include <string>

// 설명 : 화면안에 존재하는 플레이어 몬스터 총알 등등등 존재한다고 치고
// "위치가 있다면 이 녀석으로 표현해야 합니다."
class GameEngineLevel;
class GameEngineRenderer;
class GameEngineActor : public GameEngineObject
{
	friend GameEngineLevel;
public:
	// constructer destructer
	GameEngineActor();
	// 자식 클래스의 삭제 연산자가 똑바로 이루어 지기 위해서 virtual로 선언
	virtual ~GameEngineActor();

	// delete function
	GameEngineActor(const GameEngineActor& _Ohter) = delete;
	GameEngineActor(GameEngineActor&& _Ohter) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	void SetPos(const float4& _Pos)
	{
		Pos = _Pos;
	}

	void AddPos(const float4& _Pos)
	{
		Pos += _Pos;
	}

	void SetScale(const float4& _Scale)
	{
		Scale = _Scale;
	}

	float4 GetPos()
	{
		return Pos;
	}

	float4 GetScale()
	{
		return Scale;
	}

	// Actor본인이 나를 나타내는 이미지를 담당해야함
	// Renderer 하나는 이미지 하나를 띄우는 담당을 하고 있다.
	GameEngineRenderer* CreateRenderer(const std::string& _ImageName);

	GameEngineLevel* GetLevel()
	{
		return Level;
	}
protected:

private:
	// Actor는 나를 만든 Level을 알아야함
	GameEngineLevel* Level;

	float4 Pos = float4::ZERO;
	float4 Scale = float4::ZERO; // 크기는 액터한테 필요없습니다.

	std::list<GameEngineRenderer*> AllRenderer;
};

