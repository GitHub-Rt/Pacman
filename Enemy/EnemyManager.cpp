#include "EnemyManager.h"
#include "../Wall.h"

EnemyManager::EnemyManager(GameObject* parent)
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::Initialize()
{
}

void EnemyManager::Update()
{
}

void EnemyManager::Draw()
{
}

void EnemyManager::Release()
{
}

bool EnemyManager::HaveWall(Transform* trans)
{
	Wall* pWall = (Wall*)FindObject("Wall");

	int checkX, checkZ;

	// 右方向
	{
		checkX = (int)trans->position_.x + 0.3f;
		checkZ = (int)trans->position_.z;
		if (pWall->IsWall(checkX, checkZ))
		{
			return true;
		}
	}
	// 左方向
	{
		checkX = (int)trans->position_.x - 0.3f;
		checkZ = (int)trans->position_.z;
		if (pWall->IsWall(checkX, checkZ))
		{
			return true;
		}
	}
	// 上方向
	{
		checkX = (int)trans->position_.x;
		checkZ = (int)trans->position_.z + 0.3f;
		if (pWall->IsWall(checkX, checkZ))
		{
			return true;
		}
	}
	// 下方向
	{
		checkX = (int)trans->position_.x;
		checkZ = (int)trans->position_.z - 0.3f;
		if (pWall->IsWall(checkX, checkZ))
		{
			return true;
		}
	}



	return false;
}
