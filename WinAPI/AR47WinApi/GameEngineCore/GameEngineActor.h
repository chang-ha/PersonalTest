#pragma once
#include "GameEngineObject.h"
#include <GameEngineBase/GameEngineMath.h>
#include <list>
#include <string>

// ���� : ȭ��ȿ� �����ϴ� �÷��̾� ���� �Ѿ� ���� �����Ѵٰ� ġ��
// "��ġ�� �ִٸ� �� �༮���� ǥ���ؾ� �մϴ�."
class GameEngineLevel;
class GameEngineRenderer;
class GameEngineActor : public GameEngineObject
{
	friend GameEngineLevel;
public:
	// constructer destructer
	GameEngineActor();
	// �ڽ� Ŭ������ ���� �����ڰ� �ȹٷ� �̷�� ���� ���ؼ� virtual�� ����
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

	// Actor������ ���� ��Ÿ���� �̹����� ����ؾ���
	// Renderer �ϳ��� �̹��� �ϳ��� ���� ����� �ϰ� �ִ�.
	GameEngineRenderer* CreateRenderer(const std::string& _ImageName);

	GameEngineLevel* GetLevel()
	{
		return Level;
	}
protected:

private:
	// Actor�� ���� ���� Level�� �˾ƾ���
	GameEngineLevel* Level;

	float4 Pos = float4::ZERO;
	float4 Scale = float4::ZERO; // ũ��� �������� �ʿ�����ϴ�.

	std::list<GameEngineRenderer*> AllRenderer;
};

