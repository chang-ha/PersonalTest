#pragma once
#include "GameEngineObject.h"
#include <GameEngineBase/GameEngineMath.h>
#include <string>

// GameEngineRenderer�� �ϳ��� �̹����� ȭ�鿡 ���� ���� �����
// �׷��� ��Ȳ�� ���� On / Off�� �����ؾ� �ϱ� ������ GameEngineObject�� ��ӹ���
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

	// �ش� Renderer�� Texture�� ����(���)�ϴ� �Լ�
	void SetTexture(const std::string& _Name);

	// Render�� Pos�� ����
	void SetRenderPos(const float4& _Pos)
	{
		RenderPos = _Pos;
	}

	// Render�� Scale�� ����
	void SetRenderScale(const float4& _Scale)
	{
		RenderScale = _Scale;
		ScaleCheck = true;
	}

	// ������ �̹����� ���� ���� ��ġ�� ����
	void SetCopyPos(const float4& _CopyPos)
	{
		CopyPos = _CopyPos;
	}

	// ������ �̹����� ���� ���� ��ġ�κ��� �󸶳� ������ ����
	void SetCopyScale(const float4& _CopyScale)
	{
		CopyScale = _CopyScale;
	}

	// RenderScale�� Texture�� Scale�� �����ϴ� �Լ�
	void SetRenderScaleToTexture();

	bool IsDeath() override;
protected:

private:
	// �ش� Renderer�� � Texture���� ����ϴ� �������
	GameEngineWindowTexture* Texture;
	// �ش� Renderer�� ���� Actor�� �������� ����ϴ� �������
	GameEngineActor* Master;
	// Scale�� ������� �ִ��� üũ�ϴ� �������
	bool ScaleCheck = false;

	// �ش� Render�� Pos�� Scale
	float4 RenderPos;
	float4 RenderScale;

	// �����Ϸ��� �̹����� ���縦 ������ ��ġ�� ũ��
	float4 CopyPos;
	float4 CopyScale;

	void Render(GameEngineCamera* _Camera);
};

