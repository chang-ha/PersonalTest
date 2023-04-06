#include "Player.h"
#include "BaseHeader.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Damage(int _Value)
{
	if (0 == _Value)
	{
		MessageBoxAssert("데미지는 0이 될 수 없습니다.");
	}
}