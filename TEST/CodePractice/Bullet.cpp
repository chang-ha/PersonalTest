#include "Bullet.h"
#include "ConsoleGameMath.h"
#include "ConsoleGameScreen.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

Bullet::Bullet()
{

}

void Bullet::Render()
{
	if (true == Fire)
	{
		ConsoleGameScreen::GetScreen().SetScreenCharacter(Pos, '^');
	}
}

void Bullet::Update()
{
	if (true == Fire)
	{
		Pos.SetYPos(Pos.GetYPos() - 1);
	}
}

void Bullet::AllRender()
{
	for (size_t i = 0; i < ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}
		ArrBullet[i].Render();
	}
}

void Bullet::AllUpdate()
{
	for (size_t i = 0; i < ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}
		ArrBullet[i].Update();
	}
}