#include "ResourcesManager.h"
#include <GameEngineBase/GameEngineString.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>

ResourcesManager ResourcesManager::Inst;

ResourcesManager::ResourcesManager()
{

}

ResourcesManager::~ResourcesManager()
{
	for (const std::pair<std::string, GameEngineWindowTexture*>& _Pair : AllTexture)
	{
		GameEngineWindowTexture* _Texture = _Pair.second;
		if (nullptr != _Texture)
		{
			delete _Texture;
			_Texture = nullptr;
		}
	}
}

bool ResourcesManager::IsLoadTexture(const std::string& _Name)
{
	// "_Name"이름의 Texture가 로드되어 있으면 true를 리턴해주는 함수
	return FindTexture(_Name) != nullptr;
}

GameEngineWindowTexture* ResourcesManager::TextureLoad(const std::string& _Name, const std::string& _Path)
{
	// 이름을 대문자로 변경
	std::string UpperName = GameEngineString::ToUpperReturn(_Name);

	// GameEngineTextrue Heap메모리에 동적할당
	GameEngineWindowTexture* LoadTexture = new GameEngineWindowTexture();

	LoadTexture->ResLoad(_Path);

	AllTexture.insert(std::make_pair(UpperName, LoadTexture));

	return LoadTexture;
 }

GameEngineWindowTexture* ResourcesManager::FindTexture(const std::string& _Name)
{
	std::string UpperName = GameEngineString::ToUpperReturn(_Name);

	std::map<std::string, GameEngineWindowTexture*>::iterator FindIter = AllTexture.find(UpperName);
	if (AllTexture.end() == FindIter)
	{
		return nullptr;
	}

	return FindIter->second;
}
