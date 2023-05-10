#pragma once

enum class UpdateOrder
{
	Player,
	Monster
};

enum class RenderOrder
{
	BackGround,
	Play, // 플레이어뿐만아니라 움직이는 객체
	PlayUI,
};