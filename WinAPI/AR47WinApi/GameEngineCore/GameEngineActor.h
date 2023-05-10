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

	// 자식 클래스의 삭제 연산자가 똑바로 이루어 지기 위해서 virtual로 선언 << 자식의 멤버변수 중 std::string이 소멸자가 호출되지 않아 LEAK이 발생하였기 때문
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

	// Actor본인이 나를 나타내는 이미지를 담당해야함
	// Renderer 하나는 이미지 하나를 띄우는 담당을 하고 있다.
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
	// Actor는 나를 만든 Level을 알아야함
	GameEngineLevel* Level;

	float4 Pos = float4::ZERO;

	// 캐릭터란 여러 이미지가 뭉쳐서 캐릭터 전체를 보여주는 것 << ex) 몸통, 옷, 이펙트 등등
	// 각각을 담당하는 Renderer를 list로 관리
	std::list<GameEngineRenderer*> AllRenderer;
};

