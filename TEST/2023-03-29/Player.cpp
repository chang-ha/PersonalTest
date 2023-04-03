#include "Player.h"

Player::Player()
{

}

void Player::Damage(int _Damage)
{
	this->Hp -= _Damage;
}