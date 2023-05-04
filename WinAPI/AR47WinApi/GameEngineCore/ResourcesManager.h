#pragma once
#include <string>

// �̱������� ����
// �̱����̶�? �� ���α׷����� �� ��ü�� 1���� �־����� ���ڴ�
// 1. ������ �� �Ҹ��ڸ� private�� �����
// 2. ���ο� static ��������� 1�� �д�
// 3. �ش� ������ �������ִ� �Լ��� �����.

// �̱����� ������������ �ϳ��� �����ε�
// ���� UML�� ���� �����ϸ� ����
class GameEngineTexture;
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
	void TextureLoad(const std::string& _Path)
	{

	}

	// TextureLoad�Լ��� �����ε�, �ҷ��� Texture�� �̸��� ���� �ο��ϰ� ������ ���
	void TextureLoad(const std::string& _Name, const std::string& _Path)
	{

	}

	GameEngineTexture* FintTexture(const std::string& _Image);

	// �̹� �ε�� Texture���� Ȯ���ϴ� �Լ�
	bool IsLoadTexture(const std::string& _Image);
protected:

private:
	static ResourcesManager Inst;
	// constructer destructer
	ResourcesManager();
	~ResourcesManager();
};

