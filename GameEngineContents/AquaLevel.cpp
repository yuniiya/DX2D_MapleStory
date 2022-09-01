#include "PreCompile.h"
#include "AquaLevel.h"
#include <GameEngineCore/GEngine.h>
#include "Player.h"
#include "Mouse.h"
#include "Fade.h"
#include "Freezer.h"
#include "Sparker.h"
#include "Inventory.h"

AquaLevel::AquaLevel() 
	: Player_(nullptr)
{
}

AquaLevel::~AquaLevel() 
{
}

void AquaLevel::Start()
{
	GlobalLevel::Start();

	SetCollisionMap("ColMap_Aqua2.png");
	SetBackGround("Back_Aqua2.png");
	SetStage("Stage_Aqua.png");

	SetPortal({ 97.f, -1123.f, (int)ZOrder::PORTAL});
	SetPortal({ 1494.f, -1064.f, (int)ZOrder::PORTAL });

	// UI
	//ContentsUI* MainUI = CreateActor<ContentsUI>(GAMEOBJGROUP::UI);
	//CreateActor<Mouse>((int)GAMEOBJGROUP::MOUSE);
}

void AquaLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
	{
		GEngine::ChangeLevel("Boss");
	}
	if (GameEngineInput::GetInst()->IsDown("FreeCameraOnOff"))
	{
		GetMainCameraActor()->FreeCameraModeOnOff();
	}

	//float4 PlayerPos_ = Player_->GetTransform().GetLocalPosition();
	float4 PlayerPos_ = Player::MainPlayer_->GetTransform().GetLocalPosition();

	if (false == GetMainCameraActor()->IsFreeCameraMode())
	{
		GetMainCameraActor()->GetTransform().SetLocalPosition({ PlayerPos_.x, PlayerPos_.y + 120.f });
	}

	CameraFix({ 1614.f, 1380.f });
}

void AquaLevel::End()
{
}

void AquaLevel::LevelStartEvent()
{
	Fade* FadeActor = CreateActor<Fade>(GAMEOBJGROUP::FADE);
	Player::MainPlayer_->GetTransform().SetLocalPosition({ 1200.0f, -1000.0f, (int)ZOrder::PLAYER });


	// Monster
	{
		Sparker* Spark1 = CreateActor<Sparker>(GAMEOBJGROUP::MONSTER);
		Spark1->GetTransform().SetLocalPosition({ 1050.f, -1000.f, (int)ZOrder::MONSTER });
		Spark1->SetMonsterDir(ACTORDIR::LEFT);
	}

	{
		Freezer* Freez1 = CreateActor<Freezer>(GAMEOBJGROUP::MONSTER);
		Freez1->GetTransform().SetLocalPosition({ 800.f, -1000.f, (int)ZOrder::MONSTER });
		Freez1->SetMonsterDir(ACTORDIR::LEFT);
	}
}

void AquaLevel::LevelEndEvent()
{
	Player::MainPlayer_->SetLevelOverOn();
	Inventory::MainInventory_->SetLevelOverOn();
}
