#pragma once
#include <string>
#include <filesystem> // C++ 17버전 이상에서만 사용가능

// 절대경로는 절대 쓰지 않음
// 설치하는 환경이 사람마다 다르기 때문에 
class GameEnginePath
{
public:
	// constructer destructer
	GameEnginePath();
	~GameEnginePath();

	// delete function
	GameEnginePath(const GameEnginePath& _Ohter) = delete;
	GameEnginePath(GameEnginePath&& _Ohter) noexcept = delete;
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

	// 현재 실행중인 파일의 경로를 return해주는 함수
	void GetCurrentPath();
protected:

private:
	std::filesystem::path Path;
};

