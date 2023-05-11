#pragma once
#include "GameEngineObject.h"
#include <GameEngineBase/GameEngineMath.h>
#include <string>

// GameEngineRenderer가 하나의 이미지를 화면에 띄우는 것을 담당함
// 그래서 상황에 따라 On / Off가 가능해야 하기 때문에 GameEngineObject를 상속받음
class GameEngineActor;
class GameEngineWindowTexture;
class GameEngineCamera;
class GameEngineRenderer : public GameEngineObject
{
	friend GameEngineActor;
	friend GameEngineCamera;
public:
	// constructer destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete function
	GameEngineRenderer(const GameEngineRenderer& _Ohter) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Ohter) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	// 해당 Renderer에 Texture를 세팅(기억)하는 함수
	void SetTexture(const std::string& _Name);

	// Render할 Pos를 세팅
	void SetRenderPos(const float4& _Pos)
	{
		RenderPos = _Pos;
	}

	// Render할 Scale을 세팅
	void SetRenderScale(const float4& _Scale)
	{
		RenderScale = _Scale;
		ScaleCheck = true;
	}

	// 복사할 이미지의 복사 시작 위치를 세팅
	void SetCopyPos(const float4& _CopyPos)
	{
		CopyPos = _CopyPos;
	}

	// 복사할 이미지의 복사 시작 위치로부터 얼마나 할지를 세팅
	void SetCopyScale(const float4& _CopyScale)
	{
		CopyScale = _CopyScale;
	}

	// RenderScale을 Texture의 Scale로 설정하는 함수
	void SetRenderScaleToTexture();

	bool IsDeath() override;
protected:

private:
	// 해당 Renderer가 어떤 Texture인지 기억하는 멤버변수
	GameEngineWindowTexture* Texture;
	// 해당 Renderer의 주인 Actor가 누구인지 기억하는 멤버변수
	GameEngineActor* Master;
	// Scale이 변경된적 있는지 체크하는 멤버변수
	bool ScaleCheck = false;

	// 해당 Render의 Pos와 Scale
	float4 RenderPos;
	float4 RenderScale;

	// 복사하려는 이미지의 복사를 시작할 위치와 크기
	float4 CopyPos;
	float4 CopyScale;

	void Render(GameEngineCamera* _Camera);
};

