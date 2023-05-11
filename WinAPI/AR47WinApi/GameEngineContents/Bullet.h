#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRenderer;
class Bullet : public GameEngineActor
{
public:
	// constructer destructer
	Bullet();
	~Bullet();

	// delete function
	Bullet(const Bullet& _Ohter) = delete;
	Bullet(Bullet&& _Ohter) noexcept = delete;
	Bullet& operator=(const Bullet& _Other) = delete;
	Bullet& operator=(Bullet&& _Other) noexcept = delete;

	GameEngineRenderer* Renderer;

	void SetDir(const float4& _Dir)
	{
		Dir = _Dir;
	}

	void SetSpeed(const float _Speed)
	{
		Speed = _Speed;
	}
protected:

private:
	float4 Dir;
	float Speed = 500.0f;

	void Start() override;
	void Update(float _Delta) override;
	void Render() override;
	void Release() override;
};

