#pragma once

enum class GAMEOBJGROUP
{
	BACKGROUND,
	STAGE,
	PLAYER,
	MONSTER,
	OBJ,
	EFFECT,
	UI,

	MAX,
};

enum class PLAYERSTATE
{
	IDLE,
	MOVE,
	JUMP,
	PRONE,
	PRONESTAB,
	LADDER,
	ROPE,
	ATTACK,
	DAMAGED,
	DIE,

	MAX,
};
