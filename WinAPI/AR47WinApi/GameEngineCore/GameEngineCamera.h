#pragma once
#include <map>
#include <list>
#include "GameEngineRenderer.h"

// ī�޶� �������� �����ϱ� ������ ȭ�鿡 �������� ���´�.
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
	// ī�޶� ���߰� �ִ� Pos (���ʿ��� 0,0)
	float4 Pos = float4::ZERO;

	// ȭ�鿡 �̹����� �׷��ִ� ������ ī�޶�� Renderer�� ���
	std::map<int, std::list<GameEngineRenderer*>> Renderers;

	// ī�޶� Renderer�� �־ ����
	void PushRenderer(GameEngineRenderer* _Renderer, int _Order);

	// �ش� ī�޶� ���� Renderer�� Render�ϴ� ������ �ۼ�
	void Render();

	void Release();
};

