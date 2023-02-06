#include "Enemy_Pink.h"
#include "../Engine/Model.h"
#include "../Engine/Global.h"

#include "../Player.h"

#include "../Wall.h"


Enemy_Pink::Enemy_Pink(GameObject* parent)
	: GameObject(parent, "Enemy_Pink"), hModel(-1), count(0), update(60), move(0)
{

}

Enemy_Pink::~Enemy_Pink()
{

}


void Enemy_Pink::Initialize()
{
	hModel = Model::Load("Enemy_Pink.fbx");
	assert(hModel >= 0);


	transform_.position_.x = 11;
	transform_.position_.z = 11;

	pWall = (Wall*)FindObject("Wall");
	pAstar = new Astar(pWall);
}

void Enemy_Pink::Update()
{
	NextPos();
}

void Enemy_Pink::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy_Pink::Release()
{
	SAFE_DELETE(pAstar);
}

void Enemy_Pink::NextPos()
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
			(int)playerPos.x + 0.5f, (int)playerPos.z + 0.5f);

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