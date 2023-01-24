#include "Enemy_Red.h"
#include "../Player.h"


void Enemy_Red::Initialize()
{
	hModel = 0;
	EnemyManager::ModelLoad(hModel);
}

void Enemy_Red::Draw()
{
	EnemyManager::ModelDraw(hModel,transform_);
}

void Enemy_Red::NextPos()
{
	//ƒvƒŒƒCƒ„[‚ÌŒã‚ë‚ð’Ç‚¢‚©‚¯‚éAI
	Player* pPlayer = (Player*)FindObject("Player");
	if (pPlayer == nullptr)
	{
		KillMe();
	}
	XMFLOAT3 PlayerPos = pPlayer->GetPosition();


}