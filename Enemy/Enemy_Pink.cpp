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
	timer++;
	if (timer > 600 && isTime == false)
	{//プレイヤーを追いかけ始める
		isTime = true;
		isPatrol = false;
	}

	if (isTime)
	{
		NextPos();
	}
	else
	{
		//自分の縄張りをぐるぐるする
		MyHouse();
	}
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
	//pPlayer->FrontPositon();
	//XMFLOAT3 playerPos = pPlayer->GetFront();

	XMFLOAT3 playerPos = pPlayer->GetPosition();

	update++;
	if (update > 30)
	{
		//探索
		pAstar->InitSearch(
			(int)transform_.position_.x, (int)transform_.position_.z,
			(int)playerPos.x + 0.5f , (int)playerPos.z  + 0.5f);

		//ルート個数の取得
		count = pAstar->GetRoute().size() - 2;


		if (count <= 0)
		{//プレイヤーに追いついたら、初期値に戻って再度探索を行う
			transform_.position_.x = 11;
			transform_.position_.z = 11;


			pAstar->InitSearch(
				(int)transform_.position_.x, (int)transform_.position_.z,
				(int)playerPos.x + 0.5f, (int)playerPos.z + 0.5f);


			count = pAstar->GetRoute().size() - 2;

		}

		update = 0;
	}

	if (move > 10)
	{
		move = 0;

		if (count >= 0)
		{
			route = pAstar->GetRoute()[count];

			//移動
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


void Enemy_Pink::MyHouse()
{
	update++;
	if (update > 20)
	{
		update = 0;

		if (isPatrol == false)
		{
			pAstar->InitSearch(
				(int)transform_.position_.x, (int)transform_.position_.z,
				HOUSE_X, HOUSE_Z);

			count = pAstar->GetRoute().size() - 2;

			if (count <= 0)
			{//左上のポイントについた
				isPatrol = true;
			}
		}
		else
		{
			pAstar->InitSearch(
				(int)transform_.position_.x, (int)transform_.position_.z,
				HOUSE_X + tourX, HOUSE_Z - tourZ);

			count = pAstar->GetRoute().size() - 2;

			if (count <= 0)
			{//巡回ポイントについた
				isPatrol = false;
			}
		}

	}

	if (move > 10)
	{
		move = 0;

		if (count >= 0)
		{
			route = pAstar->GetRoute()[count];

			//移動
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