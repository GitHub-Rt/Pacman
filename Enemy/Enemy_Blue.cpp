#include "Enemy_Blue.h"
#include "../Engine/Model.h"
#include "../Engine/Global.h"

#include "../Player.h"
#include "Enemy_Red.h"

#include "../Wall.h"


Enemy_Blue::Enemy_Blue(GameObject* parent)
	: GameObject(parent, "Enemy_Blue"), hModel(-1), count(0), update(60), move(0)
{

}

Enemy_Blue::~Enemy_Blue()
{

}


void Enemy_Blue::Initialize()
{
	hModel = Model::Load("Enemy_Blue.fbx");
	assert(hModel >= 0);


	transform_.position_.x = 10;
	transform_.position_.z = 10;

	pWall = (Wall*)FindObject("Wall");
	pAstar = new Astar(pWall);
}

void Enemy_Blue::Update()
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

void Enemy_Blue::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy_Blue::Release()
{
	SAFE_DELETE(pAstar);
}

void Enemy_Blue::NextPos()
{
	//パックマンを中心にして、オイカケ（赤）の点対称の位置を最短距離で目指して行動する

	Player* pPlayer = (Player*)FindObject("Player");
	XMFLOAT3 playerPos;
	if (pPlayer != nullptr)
	{
		playerPos = pPlayer->GetPosition();
	}

	Enemy_Red* pRed = (Enemy_Red*)FindObject("Enemy_Red");
	XMFLOAT3 redPos;
	if (pRed != nullptr)
	{
		redPos = pRed->GetPosition();
	}


	//点対称の位置を調べる

	XMVECTOR vRed = XMLoadFloat3(&redPos);
	XMVECTOR vPlayer = XMLoadFloat3(&playerPos);

	XMVECTOR vBlue = vRed - vPlayer;
	vBlue = XMVector3Normalize(vBlue);
	vBlue *= -1;		//向きを反対にする


	XMStoreFloat3(&bluePos, vBlue);
	ceil(bluePos.x);
	ceil(bluePos.z);

	bool isWall = pWall->IsWall((int)bluePos.x, (int)bluePos.z);

	if (isWall)
	{// 壁だった
		while (isWall)
		{
			bluePos.x--;
			bluePos.z--;
			isWall = pWall->IsWall((int)bluePos.x, (int)bluePos.z);
		}
	}


	update++;
	if (update > 30)
	{
		update = 0;

		//探索
		pAstar->InitSearch(
			(int)transform_.position_.x, (int)transform_.position_.z,
			(int)bluePos.x, (int)bluePos.z);

		//ルート個数の取得
		count = pAstar->GetRoute().size() - 2;

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

void Enemy_Blue::MyHouse()
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
			{//右上のポイントについた
				isPatrol = true;
			}
		}
		else
		{
			pAstar->InitSearch(
				(int)transform_.position_.x, (int)transform_.position_.z,
				HOUSE_X - tourX, HOUSE_Z + tourZ);

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

