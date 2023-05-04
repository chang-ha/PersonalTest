#pragma once
#include <string>

// 싱글톤으로 구성
// 싱글톤이란? 이 프로그램에서 이 객체가 1개만 있었으면 좋겠다
// 1. 생성자 및 소멸자를 private로 숨긴다
// 2. 내부에 static 멤버변수를 1개 둔다
// 3. 해당 변수를 리턴해주는 함수를 만든다.

// 싱글톤은 디자인패턴중 하나의 유형인데
// 보통 UML과 같이 공부하면 좋음
class GameEngineTexture;
class ResourcesManager
{
public:
	// delete function
	ResourcesManager(const ResourcesManager& _Ohter) = delete;
	ResourcesManager(ResourcesManager&& _Ohter) noexcept = delete;
	ResourcesManager& operator=(const ResourcesManager& _Other) = delete;
	ResourcesManager& operator=(ResourcesManager&& _Other) noexcept = delete;

	// 싱글톤 방법으로 만든 Inst를 return해주는 함수 
	static ResourcesManager& GetInst()
	{
		return Inst;
	}

	// 해당 경로에있는 Texture를 불러오기위한 함수
	void TextureLoad(const std::string& _Path)
	{

	}

	// TextureLoad함수의 오버로딩, 불러온 Texture에 이름을 따로 부여하고 싶을때 사용
	void TextureLoad(const std::string& _Name, const std::string& _Path)
	{

	}

	GameEngineTexture* FintTexture(const std::string& _Image);

	// 이미 로드된 Texture인지 확인하는 함수
	bool IsLoadTexture(const std::string& _Image);
protected:

private:
	static ResourcesManager Inst;
	// constructer destructer
	ResourcesManager();
	~ResourcesManager();
};

