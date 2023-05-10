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

	// �ڽ� Ŭ������ ���� �����ڰ� �ȹٷ� �̷�� ���� ���ؼ� virtual�� ���� << �ڽ��� ������� �� std::string�� �Ҹ��ڰ� ȣ����� �ʾ� LEAK�� �߻��Ͽ��� ����
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

	float4 GetPos()
	{
		return Pos;
	}

	// Actor������ ���� ��Ÿ���� �̹����� ����ؾ���
	// Renderer �ϳ��� �̹��� �ϳ��� ���� ����� �ϰ� �ִ�.
	GameEngineRenderer* CreateRenderer(const std::string& _ImageName, int _Order);

	template <typename EnumType>
	GameEngineRenderer* CreateRenderer(const std::string& _ImageName, EnumType _Order)
	{
		return CreateRenderer(_ImageName, static_cast<int>(_Order));
	}

	GameEngineLevel* GetLevel()
	{
		return Level;
	}

protected:

private:
	// Actor�� ���� ���� Level�� �˾ƾ���
	GameEngineLevel* Level;

	float4 Pos = float4::ZERO;

	// ĳ���Ͷ� ���� �̹����� ���ļ� ĳ���� ��ü�� �����ִ� �� << ex) ����, ��, ����Ʈ ���
	// ������ ����ϴ� Renderer�� list�� ����
	std::list<GameEngineRenderer*> AllRenderer;
};

