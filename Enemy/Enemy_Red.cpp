#include "Enemy_Red.h"
#include "../Engine/Model.h"
#include "../Engine/Global.h"

#include "../Player.h"

#include "../Wall.h"


Enemy_Red::Enemy_Red(GameObject* parent)
	: GameObject(parent,"Enemy_Red"),hModel(-1),count(0),update(60),move(0)
{

}

Enemy_Red::~Enemy_Red()
{

}


void Enemy_Red::Initialize()
{
	hModel = Model::Load("Enemy_Red.fbx");
	assert(hModel >= 0);


	transform_.position_.x = 12;
	transform_.position_.z = 12;

	pWall = (Wall*)FindObject("Wall");
	pAstar = new Astar(pWall);
}

void Enemy_Red::Update()
{
	NextPos();
}

void Enemy_Red::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy_Red::Release()
{
	SAFE_DELETE(pAstar);
}

void Enemy_Red::NextPos()
{
	Player* pPlayer = (Player*)FindObject("Player");
	if (pPlayer == nullptr)
	{
		return;
	}
	XMFLOAT3 playerPos = pPlayer->GetPosition();
	

	update++;
	if (update > 60)
	{
		//’Tõ
		pAstar->InitSearch(
			(int)transform_.position_.x, (int)transform_.position_.z,
			(int)playerPos.x, (int)playerPos.z);

		//ƒ‹[ƒgŒÂ”‚ÌŽæ“¾
		count = pAstar->GetRoute().size() - 2;

		update = 0;
	}

	if (move > 10)
	{
		move = 0;

		if (count >= 0)
		{
			route = pAstar->GetRoute()[count];

			//ˆÚ“®
			transform_.position_.x = route.x + 0.5f;
			transform_.position_.z = route.y + 0.5f;

			count--;
		}
	}
	else
	{
		move++;
	}
	

}