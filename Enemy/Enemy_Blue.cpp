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
	{//�v���C���[��ǂ������n�߂�
		isTime = true;
		isPatrol = false;
	}
	else if (timer > 1200)
	{//�꒣��ɖ߂��Ă���
		isTime = false;
		update = 0;
	}

	if (isTime)
	{
		//NextPos();
	}
	else
	{
		//�����̓꒣������邮�邷��
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
	//�p�b�N�}���𒆐S�ɂ��āA�I�C�J�P�i�ԁj�̓_�Ώ̂̈ʒu���ŒZ�����Ŗڎw���čs������

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

	update++;
	if (update > 30)
	{
		update = 0;

		//�T��
		pAstar->InitSearch(
			(int)transform_.position_.x, (int)transform_.position_.z,
			(int)playerPos.x, (int)playerPos.z);

		//���[�g���̎擾
		count = pAstar->GetRoute().size() - 2;

		if (count <= 20)
		{
			//������

		}
	}
	if (move > 10)
	{
		move = 0;

		if (count >= 0)
		{
			route = pAstar->GetRoute()[count];

			//�ړ�
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
			{//�E��̃|�C���g�ɂ���
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
			{//����|�C���g�ɂ���
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

			//�ړ�
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

