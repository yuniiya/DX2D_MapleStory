#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "GlobalActor.h"

class GameEngineTextureRenderer;
class Player : public GlobalActor
{
public:
	static Player* MainPlayer_;

	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

private:
	float Speed_;

	PLAYERSTATE CurState_;

private:
	GameEngineCollision* PlayerCollision_;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End()  {}

protected:
	GameEngineTextureRenderer* PlayerRenderer_;
	std::string AnimationName_;

protected:
	void PixelColiisionCheck();
	void ColiisionCheck();

protected:
	void ChangeState(PLAYERSTATE _State);
	void PlayerStateUpdate();

protected:
	void IdleStart();
	void MoveStart();
	void JumpStart();
	void ProneStart();
	void ProneStabStart();
	void LadderStart();
	void RopeStart();
	void AttackStart();
	void DamagedStart();
	void DieStart();

	void IdleUpdate();
	void MoveUpdate();
	void JumpUpdate();
	void ProneUpdate();
	void ProneStabUpdate();
	void LadderUpdate();
	void RopeUpdate();
	void AttackUpdate();
	void DamagedUpdate();
	void DieUpdate();
};

