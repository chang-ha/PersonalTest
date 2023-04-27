#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class EndingLevel : public GameEngineLevel

{
public:
	// constructer destructer
	EndingLevel();
	~EndingLevel();

	// delete function
	EndingLevel(const EndingLevel& _Ohter) = delete;
	EndingLevel(EndingLevel&& _Ohter) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

protected:

private:

};

