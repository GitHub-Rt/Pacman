#include "Enemy_Orange.h"
#include "../Engine/Model.h"
#include "../Engine/Global.h"

#include "../Player.h"

#include "../Wall.h"


Enemy_Orage::Enemy_Orage(GameObject* parent)
	: GameObject(parent, "Enemy_Orage"), hModel(-1), count(0), update(60), move(0)
{

}

Enemy_Orage::~Enemy_Orage()
{

}


void Enemy_Orage::Initialize()
{
	hModel = Model::Load("Enemy_Orange.fbx");
	assert(hModel >= 0);


	transform_.position_.x = 11;
	transform_.position_.z = 12;

	pWall = (Wall*)FindObject("Wall");
	pAstar = new Astar(pWall);
}

void Enemy_Orage::Update()
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
		NextPos();
	}
	else
	{
		//�����̓꒣������邮�邷��
		MyHouse();
	}
}

void Enemy_Orage::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy_Orage::Release()
{
	SAFE_DELETE(pAstar);
}

void Enemy_Orage::NextPos()
{
	//�p�b�N�}����艓���Ƃ���ɂ���Ƃ��͒ǂ������A�߂��Ƃ���ɂ���Ƃ��͓�����
}

void Enemy_Orage::MyHouse()
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
				HOUSE_X + tourX, HOUSE_Z + tourZ);

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

