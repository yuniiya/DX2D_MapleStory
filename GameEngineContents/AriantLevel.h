#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// ���� :
class AriantLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	AriantLevel();
	~AriantLevel();

	// delete Function
	AriantLevel(const AriantLevel& _Other) = delete;
	AriantLevel(AriantLevel&& _Other) noexcept = delete;
	AriantLevel& operator=(const AriantLevel& _Other) = delete;
	AriantLevel& operator=(AriantLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:

};

