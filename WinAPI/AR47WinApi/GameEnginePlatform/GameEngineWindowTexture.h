#pragma once
#include <string>
#include <Windows.h>
#include <GameEngineBase/GameEngineMath.h>

// ���� ������ GameEngineWindowTexture �ϳ���
class GameEngineWindowTexture
{
public:
	// constructer destructer
	GameEngineWindowTexture();
	~GameEngineWindowTexture();

	// delete function
	GameEngineWindowTexture(const GameEngineWindowTexture& _Ohter) = delete;
	GameEngineWindowTexture(GameEngineWindowTexture&& _Ohter) noexcept = delete;
	GameEngineWindowTexture& operator=(const GameEngineWindowTexture& _Other) = delete;
	GameEngineWindowTexture& operator=(GameEngineWindowTexture&& _Other) noexcept = delete;

	// Resource�� Load�ϴ� �Լ�
	void ResLoad(const std::string& _Path);

	// ImageDC�� �����ϴ� �Լ�
	HDC GetImageDC()
	{
		return ImageDC;
	}

	// HDC�� �޾Ƽ� �����ϴ� �Լ� (WindowBuffer)
	void ResCreate(HDC _ImageDC)
	{
		ImageDC = _ImageDC;
		// �ش�Texture�� ũ�⸦ �����ϱ� ���� �Լ�ȣ�� (������â�� ũ�⸦ ����)
		ScaleCheck();
	}

	// �ش� ũ���� �� �̹����� ����� �Լ� (BackBuffer)
	void ResCreate(const float4& _Scale);

	float4 GetScale();

	// ���� �����ϰ��� �ϴ� Texture�� Window�� BackBuffer�� �������ִ� �Լ�
	void BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos);
	void BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos, const float4& _Scale);

	// BitCopy�� �Ѱ������� ���� ���ο� �Լ��� ��� 
	// ���� ��� �̹����� Ȯ���ϰų�, Ư�� ������ ����� �ʰ� �ϱ� ���� ���
	// void TransCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos);
	void TransCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos, const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, int _TransColor = RGB(255, 255, 255));
protected:

private:
	HBITMAP BitMap = nullptr; // ���� �ڵ�� ������ BitMap
	HBITMAP OldBitMap = nullptr; // ������ �ڵ鿡 ����Ǿ� �ִ� BitMap << ���� �ڵ鿡 ���� ������ �ڵ����� 1x1ũ���� BitMap�� ����Ǿ� �ֱ� ���� << �ƹ��͵� ����Ǿ� ���� ���� �ڵ��� �������� �ʴµ�???
	HDC ImageDC = nullptr; // ���� Load�� BitMap�� ������ ������ ������ �ڵ�
	BITMAP Info = {};
	void ScaleCheck();
};

