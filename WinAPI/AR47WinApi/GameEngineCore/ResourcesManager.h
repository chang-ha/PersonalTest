#pragma once
#include <string>
#include <map>
#include <GameEngineBase/GameEnginePath.h>

// �̱������� ����
// �̱����̶�? �� ���α׷����� �� ��ü�� 1���� �־����� ���ڴ�
// 1. ������ �� �Ҹ��ڸ� private�� �����
// 2. ���ο� static ��������� 1�� �д�
// 3. �ش� ������ �������ִ� �Լ��� �����.

// �̱����� ������������ �ϳ��� �����ε�
// ���� UML�� ���� �����ϸ� ����
class GameEngineWindowTexture;
class ResourcesManager
{
public:
	// delete function
	ResourcesManager(const ResourcesManager& _Ohter) = delete;
	ResourcesManager(ResourcesManager&& _Ohter) noexcept = delete;
	ResourcesManager& operator=(const ResourcesManager& _Other) = delete;
	ResourcesManager& operator=(ResourcesManager&& _Other) noexcept = delete;

	// �̱��� ������� ���� Inst�� return���ִ� �Լ� 
	static ResourcesManager& GetInst()
	{
		return Inst;
	}

	// �ش� ��ο��ִ� Texture�� �ҷ��������� �Լ�
	GameEngineWindowTexture* TextureLoad(const std::string& _Path)
	{
		GameEnginePath LoadPath = _Path;
		return TextureLoad(LoadPath.GetFileName(), _Path); 
	}

	// TextureLoad�Լ��� �����ε�, �ҷ��� Texture�� �̸��� ���� �ο��ϰ� ������ ���
	GameEngineWindowTexture* TextureLoad(const std::string& _Name, const std::string& _Path);

	GameEngineWindowTexture* FindTexture(const std::string& _Name);

	// �̹� �ε�� Texture���� Ȯ���ϴ� �Լ�
	bool IsLoadTexture(const std::string& _Name);
protected:

private:
	static ResourcesManager Inst;
	// constructer destructer
	ResourcesManager();
	~ResourcesManager();

	// �ε��� �ؽ��ĸ� ������ map ����
	std::map<std::string, GameEngineWindowTexture*> AllTexture;
};

