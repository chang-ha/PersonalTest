#pragma once
#include <string>
#include <Windows.h>
#include <GameEngineBase/GameEngineMath.h>

// 사진 한장이 GameEngineWindowTexture 하나임
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

	// Resource를 Load하는 함수
	void ResLoad(const std::string& _Path);

	// ImageDC를 리턴하는 함수
	HDC GetImageDC()
	{
		return ImageDC;
	}

	// HDC를 받아서 저장하는 함수 (WindowBuffer)
	void ResCreate(HDC _ImageDC)
	{
		ImageDC = _ImageDC;
		// 해당Texture의 크기를 저장하기 위해 함수호출 (윈도우창의 크기를 저장)
		ScaleCheck();
	}

	// 해당 크기의 빈 이미지를 만드는 함수 (BackBuffer)
	void ResCreate(const float4& _Scale);

	float4 GetScale();

	// 내가 복사하고자 하는 Texture를 Window의 BackBuffer에 복사해주는 함수
	void BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos);
	void BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos, const float4& _Scale);

	// BitCopy의 한계점으로 인해 새로운 함수를 사용 
	// 내가 띄울 이미지를 확대하거나, 특정 색상을 띄우지 않게 하기 위해 사용
	// void TransCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos);
	void TransCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos, const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, int _TransColor = RGB(255, 255, 255));
protected:

private:
	HBITMAP BitMap = nullptr; // 새로 핸들과 연결할 BitMap
	HBITMAP OldBitMap = nullptr; // 이전에 핸들에 저장되어 있던 BitMap << 최초 핸들에 권한 생성시 자동으로 1x1크기의 BitMap이 저장되어 있기 때문 << 아무것도 연결되어 있지 않은 핸들은 존재하지 않는듯???
	HDC ImageDC = nullptr; // 내가 Load한 BitMap를 수정할 권한을 저장할 핸들
	BITMAP Info = {};
	void ScaleCheck();
};

