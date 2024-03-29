#include "PreCompile.h"
#include "CastleLevel.h"
#include <GameEngineCore/GEngine.h>
#include "MapBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "Player.h"
#include "Mouse.h"
#include "Fade.h"
#include "Inventory.h"
#include "NPC_Castle.h"
#include "GameBgmPlayer.h"

CastleLevel::CastleLevel() 
	: Player_(nullptr)
{
}

CastleLevel::~CastleLevel() 
{
}

void CastleLevel::Start()
{
	SetCollisionMap("ColMap_Castle.png");
	SetBackGround("Back_Castle2.png");
	SetStage("Stage_Castle3.png");

	//Player_ = CreateActor<Player>((int)GAMEOBJGROUP::PLAYER);
	//Player_->GetTransform().SetLocalPosition({ 300.0f, -400.0f});

	SetPortal({ 273.f, -495.f, (int)ZOrder::PORTAL });

	NPC_Castle* NPC_ = CreateActor<NPC_Castle>((int)GAMEOBJGROUP::OBJ);
	NPC_->SetNPCType(NPCType::NPC_Castle);
	NPC_->GetTransform().SetLocalPosition({ 1550.f, -520.f, (int)ZOrder::NPC });
	NPC_->SetQuestRendererPosition();

	// UI
	/*if (nullptr == GetContentsUI())
	{
		CreateActor<ContentsUI>(GAMEOBJGROUP::UI);
	}*/
	//ContentsUI* MainUI = CreateActor<ContentsUI>(GAMEOBJGROUP::UI);
	//CreateActor<Mouse>((int)GAMEOBJGROUP::MOUSE);
}

void CastleLevel::Update(float _DeltaTime)
{ 
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
	{
		GEngine::ChangeLevel("Aqua");
	}
	if (GameEngineInput::GetInst()->IsDown("FreeCameraOnOff"))
	{
		GetMainCameraActor()->FreeCameraModeOnOff();
	}

	float4 PlayerPos = Player::MainPlayer_ ->GetTransform().GetLocalPosition();
	float4 CameraPos = GetMainCameraActor()->GetTransform().GetLocalPosition();

	if (false == GetMainCameraActor()->IsFreeCameraMode())
	{
		GetMainCameraActor()->GetTransform().SetLocalPosition({ PlayerPos.x, CameraPos.y + 100.f});
	}

	CameraFix(GetCollisionMap()->GetTransform().GetLocalScale());
}

void CastleLevel::End()
{
}

void CastleLevel::LevelStartEvent()
{
	Fade* FadeActor = CreateActor<Fade>(GAMEOBJGROUP::FADE);
	if (nullptr != Player::MainPlayer_)
	{
		Player::MainPlayer_->On();
		Player::MainPlayer_->GetTransform().SetLocalPosition({ 300.0f, -400.0f, (int)ZOrder::PLAYER });
	}
	if (nullptr != ContentsUI::MainUI_)
	{
		ContentsUI::MainUI_->On();
	}
}

void CastleLevel::LevelEndEvent()
{
	Player::MainPlayer_->SetLevelOverOn();
	Inventory::MainInventory_->SetLevelOverOn();


	Mouse::MainMouse_->SetLevelOverOn();
}
