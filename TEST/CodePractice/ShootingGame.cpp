#include <iostream>
#include "ShootingGame.h"
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Bullet.h"

void ShootingGame::Game()
{
	Player NewPlayer = Player();
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());
	NewPlayer.SetPos(ConsoleGameScreen::GetScreen().GetScreenSize().Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetScreen().ScreenClear();
		
		NewPlayer.Render();
		Bullet::AllRender();

		ConsoleGameScreen::GetScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
	}

}