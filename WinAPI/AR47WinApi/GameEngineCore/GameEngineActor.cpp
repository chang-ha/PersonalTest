#include <GameEngineBase/GameEngineDebug.h>
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
	if ("" != _ImageName)
	{
		NewRenderer->SetTexture(_ImageName);
	}
	AllRenderer.push_back(NewRenderer);
	return NewRenderer;
}

void GameEngineActor::Release()
{
	std::list<GameEngineRenderer*>::iterator ObjectStartIter = AllRenderer.begin();
	std::list<GameEngineRenderer*>::iterator ObjectEndIter = AllRenderer.end();
	for (; ObjectStartIter != ObjectEndIter; )
	{
		GameEngineRenderer* Renderer = *ObjectStartIter;
		if (false == Renderer->IsDeath())
		{
			++ObjectStartIter;
			continue;
		}

		if (nullptr == Renderer)
		{
			MsgBoxAssert("nullptr인 액터가 레벨의 리스트에 들어가 있었습니다.");
			continue;
		}

		delete Renderer;
		Renderer = nullptr;
		ObjectStartIter = AllRenderer.erase(ObjectStartIter);
	}
}
