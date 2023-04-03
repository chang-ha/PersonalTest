#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "ConsoleGameMath.h"
#include "ConsoleGameScreen.h"
#include "Bullet.h"

Player::Player()
{

}


void Player::Input()
{
	if (0 == _kbhit())
	{
		Sleep(InterFream);
		return;
	}

	char Ch = _getch();

	ConsoleGameMath NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.SetYPos(NextPos.GetYPos() - 1);
		if (false == ConsoleGameScreen::GetScreen().IsScreenOver(NextPos))
		{
			Pos.SetYPos(Pos.GetYPos() - 1);
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.SetYPos(NextPos.GetYPos() + 1);
		if (false == ConsoleGameScreen::GetScreen().IsScreenOver(NextPos))
		{
			Pos.SetYPos(Pos.GetYPos() + 1);
		}
		break;
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.SetXPos(NextPos.GetXPos() - 1);
		if (false == ConsoleGameScreen::GetScreen().IsScreenOver(NextPos))
		{
			Pos.SetXPos(Pos.GetXPos() - 1);
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.SetXPos(NextPos.GetXPos() + 1);
		if (false == ConsoleGameScreen::GetScreen().IsScreenOver(NextPos))
		{
			Pos.SetXPos(Pos.GetXPos() + 1);
		}
		break;
	case 'x':
	case 'X':
			BulletPtr[NowBullet].SetPos(Pos);
			BulletPtr[NowBullet].FireOn();
			++NowBullet;
			if (NowBullet == Bullet::ArrBulletCount)
			{
				NowBullet = 0;
			}
		break;
	default:
		break;
	}
	Sleep(InterFream);
}

void Player::Render()
{
	ConsoleGameScreen::GetScreen().SetScreenCharacter(Pos, '*');
}
