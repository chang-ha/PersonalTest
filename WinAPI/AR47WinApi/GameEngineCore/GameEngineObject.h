#pragma once

// 설명 : 모든 기본적인 행동을 제안하는 클래스
// 제안하는 클래스 (제안 : virtual을 만들건데, 자식이 따로 구현을 할 것인지는 선택임)
class GameEngineObject
{
public:
	// constructer destructer
	GameEngineObject();
	~GameEngineObject();

	// delete function
	GameEngineObject(const GameEngineObject& _Ohter) = delete;
	GameEngineObject(GameEngineObject&& _Ohter) noexcept = delete;
	GameEngineObject& operator=(const GameEngineObject& _Other) = delete;
	GameEngineObject& operator=(GameEngineObject&& _Other) noexcept = delete;

	// 시작하고
	virtual void Start() {}

	// 행동하고
	virtual void Update(float _Delta) {}

	// 그려지고
	virtual void Render() {}

	// 정리된다
	virtual void Release() {}

	// UpdateValue를 true로 만듦(업데이트가 되는 객체로 변경)
	void On()
	{
		IsUpdateValue = true;
	}

	// UpdateValue를 false로 만듦(객체가 더이상 업데이트 되지 않도록)
	void Off()
	{
		IsUpdateValue = false;
	}

	// 객체의 UpdateValue가 true이고, DeathValue가 false면 업데이트를 해라
	bool IsUpdate()
	{
		return true == IsUpdateValue && false == IsDeathValue;
	}

	bool IsDeath()
	{
		return IsDeathValue;
	}
protected:

private:
	// 객체가 업데이트가 되어야 하는지 판별하는 값
	bool IsUpdateValue = true;	// 기능을 끄고 싶으면 false
	// 객체를 삭제해야 하는지 판별하는 값
	bool IsDeathValue = false;	// 메모리에서 날려버리고 싶으면 true
};

