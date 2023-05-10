#include "GameEngineWindowTexture.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "GameEngineWindow.h"

// TransCopy 내부의 " " 함수를 사용하기 위해 lib를 불러와야함
#pragma comment(lib, "msimg32.lib")

GameEngineWindowTexture::GameEngineWindowTexture()
{

}

GameEngineWindowTexture::~GameEngineWindowTexture()
{

}

void GameEngineWindowTexture::ResLoad(const std::string& _Path)
{
	// LoadImageA << 단순히 이미지를 로드하는 기능이 아니라, 우리에게 핸들을 return해줌 << 우리는 멀티바이트를 사용하므로 함수명 맨 뒤에 W가 아닌 A
	// LoadImage는 2차원 행렬에 RGB값이 막 들어있는 것
	// 윈도우는 이 값을 우리가 수정할 수 없게 핸들이라는 형태로 줌 (해당 이미지를 수정하거나 사용할 떄 핸들을 달라고 함)
	// LoadImageA로 Bitmap, 커서, 아이콘도 다 로드가능 (BitMap만 로드하고 싶으면 LoadBitMapA)

	// LPCSTR == const char*값을 넣어달라는 것
	// 여기의 hInstance는 nullptr넣어도 됨
	// _Path값은 string으로 들어왔으니, c_str()으로 const char*값으로 바꿔줌
	// IMAGE_BITMAP << 로드할 이미지가 BITMAP형식임 << 커서나 아이콘은 다른 값을 넣어줘야함
	// 0 << 로드할 이미지의 X축값 (해당 X값부터 이미지를 로드함) << 그래서 모든 이미지를 로드하려면 0
	// 0 << 로드할 이미지의 Y축값
	// LR_LOADFROMFILE << 로드할 이미지가 파일형식임
	HANDLE ImageHandle = LoadImageA(nullptr, _Path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); // << 핸들을 만드는데 성공하면 특정값, 실패하면 0을 return

	if (nullptr == ImageHandle)
	{
		MsgBoxAssert(_Path + "이미지 로드에 실패했습니다.");
		return;
	}

	// LoadImage는 사용자가 어떤 이미지를 로드할 지 모르기 때문에 그냥 핸들을 return해줌 (Bitmap, Cursor, Icon등... 무엇을 로드할 지 모름)
	// 그래서 ImageHandle을 HBITMAP을 수정할 수 있는 핸들로 casting해줘야함
	// 이미지를 로드했다는 핸들 << 윈도우창에 이미지를 띄우려면 이 이미지를 수정할 수 있는 권한이 또 필요함(HDC)
	BitMap = static_cast<HBITMAP>(ImageHandle);

	// 내가 어떠한 이미지를 로드했으니
	// 윈도우창에 이미지를 수정할 권한을 만들어 줘야함 (띄우는 것도 수정하는 것임)
	// 아래는 그냥 권한을 만들었지 아직 어떠한 이미지를 수정할 권한이 있는것은 아님 << 사실 만들어지자마자 1x1짜리 비트맵을 수정할 수 있는 권한임
	// 그래서 우리가 로드한 이미지를 수정할 권한으로 교체해 줄것임
	// 인자를 넣고싶으면 Window에서 얻어온 HDC를 넣어주면 됨
	ImageDC = CreateCompatibleDC(nullptr);

	// SelectObject를 하면 내가 만든 권한을 불러온 이미지와 연결할 수 있는데 << 내가 로드한 이미지의 수정 권한을 ImageDC로 만들어준 것임
	// 이 함수의 리턴값은 이전에 연결되어 있던 핸들을 return해줌
	// 그래서 OldBitMap이란 핸들을 만들어서 return해주는 값을 받아줘야함
	// SelectObject(ImageDC, BitMap);
	OldBitMap = static_cast<HBITMAP>(SelectObject(ImageDC, BitMap));
	// 요약
	// HBITMAP(BitMap)은 내가 로드한 이미지(BitMap형식)에대한 권한
	// HDC(ImageDC)는 윈도우창에 채워져있는 2차원 행렬의 비트값을 수정할 수 있는 권한

	// 해당 Texture의 크기를 저장하기 위해 호출
	ScaleCheck();
}

void GameEngineWindowTexture::ResCreate(const float4& _Scale)
{
	// 윈도우 크기(_Scale인자)와 똑같은 아무것도 없는 빈 이미지를 만듦
	HANDLE ImageHandle = CreateCompatibleBitmap(GameEngineWindow::MainWindow.GetHDC(), _Scale.iX(), _Scale.iY());

	if (nullptr == ImageHandle)
	{
		MsgBoxAssert("BackBuffer 생성에 실패했습니다.");
		return;
	}
	BitMap = static_cast<HBITMAP>(ImageHandle);
	ImageDC = CreateCompatibleDC(nullptr);
	OldBitMap = static_cast<HBITMAP>(SelectObject(ImageDC, BitMap));
	ScaleCheck();
}


void GameEngineWindowTexture::ScaleCheck()
{
	GetObject(BitMap, sizeof(BITMAP), &Info);
	//BITMAP OldInfo;
	//GetObject(OldBitMap, sizeof(BITMAP), &OldInfo);
}

float4 GameEngineWindowTexture::GetScale()
{
	return {static_cast<float>(Info.bmWidth), static_cast<float>(Info.bmHeight)};
}

void GameEngineWindowTexture::BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos)
{
	// Scale을 지정해주지 않으면 불러온 Texture의 크기를 자동으로 넣어줌
	BitCopy(_CopyTexture, _Pos, _CopyTexture->GetScale());
}

void GameEngineWindowTexture::BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos, const float4& _Scale)
{
	// 복사할 이미지의 DC
	HDC CopyImageDC = _CopyTexture->GetImageDC();
	// 내 이미지 DC에 복사할 이미지의 DC를 복사함
	BitBlt(ImageDC, 
		_Pos.iX() - _Scale.ihX(),
		_Pos.iY() - _Scale.ihY(), 
		_Scale.iX(), 
		_Scale.iY(), 
		CopyImageDC, 0, 0, SRCCOPY);
}

// BackBuffer->TransCopy(FindTexture, GetPos(), Scale, { 0,0 }, FindTexture->GetScale());

void GameEngineWindowTexture::TransCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos, const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, int _TransColor)
{
	// 내 이미지 DC에 복사할 이미지의 DC를 복사함
	HDC CopyImageDC = _CopyTexture->GetImageDC();

	// ImageDC == BackBuffer
	// CopyImageDC == 내가 그릴 이미지
	TransparentBlt(ImageDC,
		_Pos.iX() - _Scale.ihX(),
		_Pos.iY() - _Scale.ihY(),
		_Scale.iX(),
		_Scale.iY(),
		CopyImageDC,
		_OtherPos.iX(), // 카피하려는 이미지의 카피하기를 원하는 위치의 좌상단 X << 해당 이미지의 어느 위치부터 복사할것임?? 의 X값
		_OtherPos.iY(), // 카피하려는 이미지의 카피하기를 원하는 위치의 좌상단 Y << 해당 이미지의 어느 위치부터 복사할것임?? 의 Y값
		_OtherScale.iX(), // 해당 부분부터 X의 사이즈 << 위의 Pos값에서 X축으로 어느만큼의 크기를 복사할 것인가?
		_OtherScale.iY(), // 해당 부분부터 Y의 사이즈 << 위의 Pos값에서 Y축으로 어느만큼의 크기를 복사할 것인가?
		_TransColor);
}
