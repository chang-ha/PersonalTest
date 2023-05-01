#pragma once
#include <GameEngineCore/GameEngineCore.h>

class ContentCore : public CoreProcess
{
public:
	// constructer destructer
	ContentCore();
	~ContentCore();

	// delete function
	ContentCore(const ContentCore& _Ohter) = delete;
	ContentCore(ContentCore&& _Ohter) noexcept = delete;
	ContentCore& operator=(const ContentCore& _Other) = delete;
	ContentCore& operator=(ContentCore&& _Other) noexcept = delete;

protected:

private:
	// GameEngineObject에서 상속받은 함수들
	void Start() override;

	void Update() override;

	void Render() override;

	void Release() override;
};

