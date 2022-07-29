#include "PreCompile.h"
#include "EntranceLevel.h"
#include <GameEngineCore/GEngine.h>
#include "Player.h"

EntranceLevel::EntranceLevel() 
{
}

EntranceLevel::~EntranceLevel() 
{
}

void EntranceLevel::Start()
{
	SetCollisionMap("ColMap_Entrance.png");
	SetBackGround("Back_Entrance.png");
	SetStage("Stage_Entrance.png");

	// UI
	ContentsUI* MainUI = CreateActor<ContentsUI>(GAMEOBJGROUP::UI);

	Player_ = CreateActor<Player>((int)GAMEOBJGROUP::PLAYER);
	Player_->GetTransform().SetLocalPosition({ 2100.0f, -1000.0f, 0.0f });
}

void EntranceLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
	{
		GEngine::ChangeLevel("Castle");
	}
	if (GameEngineInput::GetInst()->IsDown("FreeCameraOnOff"))
	{
		GetMainCameraActor()->FreeCameraModeOnOff();
	}

	float4 PlayerPos_ = Player_->GetTransform().GetLocalPosition();

	if (false == GetMainCameraActor()->IsFreeCameraMode())
	{
		GetMainCameraActor()->GetTransform().SetLocalPosition({ PlayerPos_.x, PlayerPos_.y + 120.f });
	}

	CameraFix({ 2340.f, 1355.f });

}

void EntranceLevel::End()
{
}
