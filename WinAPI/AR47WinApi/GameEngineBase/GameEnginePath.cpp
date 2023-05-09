#include "GameEnginePath.h"
#include "GameEngineDebug.h"

GameEnginePath::GameEnginePath()
{

}

GameEnginePath::GameEnginePath(const std::string& _Path)
	:Path(_Path) // filesystem내부에 이미 구현되어 있음 << string으로 값이 들어올 때 path내부의 경로값에 해당 string값을 복사
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

void GameEnginePath::MoveParent()
{
	// 현재 경로에서 부모 경로로 이동하는 함수
	Path = Path.parent_path();
}

// _ChildPath 폴더 또는 파일을 찾을 때 까지 계속 부모경로로 이동하는 함수
void GameEnginePath::MoveParentToExistsChild(const std::string& _ChildPath)
{
	while (true)
	{
		std::filesystem::path CheckPath = Path;
		CheckPath.append(_ChildPath);

		if (false == std::filesystem::exists(CheckPath))
		{
			MoveParent();
		}
		else
		{
			break;
		}

		// 만약 Root경로(C or D드라이브) 까지 찾아봤는데 없으면 해당 폴더가 없는것임
		if (Path == Path.root_path())
		{
			MsgBoxAssert("Root경로까지 찾았지만 해당 폴더 또는 파일을 찾을 수 없습니다." + _ChildPath);
			return;
		}
	}
}

void GameEnginePath::MoveChild(const std::string& _ChildPath)
{
	// 경로를 이동하기 전에 해당 경로가 있는지 Check용으로 path변수 선언
	std::filesystem::path CheckPath = Path;
	// Check용 변수에 미리 경로를 이동해서
	CheckPath.append(_ChildPath);
	// 해당 경로가 있는지 체크
	if (false == std::filesystem::exists(CheckPath))
	{
		MsgBoxAssert(_ChildPath + "경로를 가진 폴더 또는 파일은 존재하지 않습니다.");
		return;
	}
	// 해당 경로가 실존하면 Path를 해당 경로로
	Path = CheckPath;
}


std::string GameEnginePath::GetFileName()
{
	return Path.filename().string();
}
