#include "GameEngineActor.h"
#include "GameEngineRenderer.h"
#include "GameEngineLevel.h"
#include "GameEngineCamera.h"

GameEngineActor::GameEngineActor()
{

}

GameEngineActor::~GameEngineActor()
{
	//std::list<GameEngineRenderer*>::iterator Start = AllRenderer.begin();
	//std::list<GameEngineRenderer*>::iterator End = AllRenderer.end();
	//for (; Start != End; ++Start)
	//{
	//	GameEngineRenderer* _Renderer = *Start;
	//	if (nullptr != _Renderer)
	//	{
	//		delete _Renderer;
	//		_Renderer = nullptr;
	//	}
	//}

	for (GameEngineRenderer* _Renderer :AllRenderer)
	{
		if (nullptr != _Renderer)
		{
			delete _Renderer;
			_Renderer = nullptr;
		}
	}
}

// 이미지를 담당하는 Renderer를 생성
GameEngineRenderer* GameEngineActor::CreateRenderer(const std::string& _ImageName, int _Order)
{
	GameEngineRenderer* NewRenderer = new GameEngineRenderer();
	GetLevel()->MainCamera->PushRenderer(NewRenderer, _Order);
	NewRenderer->Master = this;
	NewRenderer->SetTexture(_ImageName);
	AllRenderer.push_back(NewRenderer);
	return NewRenderer;
}