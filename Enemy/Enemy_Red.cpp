#include "Enemy_Red.h"
#include "../Player.h"


void Enemy_Red::Initialize()
{
	hModel = 0;
	EnemyManager::ModelLoad(hModel);
}

void Enemy_Red::Update()
{
	NextPos();
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

	XMVECTOR vMyPos = XMLoadFloat3(&transform_.position_);
	XMVECTOR vPlayer = XMLoadFloat3(&PlayerPos);


	XMVECTOR vMove = vPlayer - vMyPos;
	XMVector3Normalize(vMove);


	XMFLOAT3 move;
	XMStoreFloat3(&move, vMove);

	Transform nextPos;
	nextPos.position_.x = transform_.position_.x + move.x;
	nextPos.position_.z = transform_.position_.z + move.z;

	bool isMove = EnemyManager::HaveWall(&nextPos);

	if (isMove)
	{
		transform_.position_.x += move.x;
		transform_.position_.z += move.z;
	}
}