#include "GameEnginePath.h"


GameEnginePath::GameEnginePath()
{

}

GameEnginePath::~GameEnginePath()
{

}

void GameEnginePath::GetCurrentPath()
{
	// 현재 경로로 설정 << 이 파일이 있는 경로 (main파일이 있는 경로)
	Path = std::filesystem::current_path();
}
