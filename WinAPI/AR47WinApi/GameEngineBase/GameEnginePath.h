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
	GameEnginePath(const std::string& _Path);
	~GameEnginePath();	

	// delete function
	GameEnginePath(const GameEnginePath& _Ohter) = delete;
	GameEnginePath(GameEnginePath&& _Ohter) noexcept = delete;
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

	// 현재 실행중인 파일의 경로를 return해주는 멤버함수
	void GetCurrentPath();

	// 현재 경로에서 상위 폴더로 이동하는 멤버함수
	void MoveParent();

	// 원하는 폴더가 하위 폴더에 있을 떄 까지 상위 폴더로 이동하는 멤버함수
	void MoveParentToExistsChild(const std::string& _ChildPath);

	// 하위 경로에 있는 원하는 폴더 또는 파일로 경로를 변경해주는 멤버함수
	void MoveChild(const std::string& _ChildPath);

	std::string PlusFilePath(const std::string& _ChildPath);

	// path 클래스 내부에 있는 경로값을 string으로 return해주는 멤버함수
	std::string GetStringPath()
	{
		return Path.string();
	}

	// 경로를 제외한 파일 이름을 받는 멤버함수
	std::string GetFileName();
protected:

private:
	// 경로를 저장하는 멤버변수
	std::filesystem::path Path;
};

