#include "EnemyManager.h"
#include "../Wall.h"
#include "../Engine/Model.h"

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

	// ‰E•ûŒü
	{
		checkX = (int)trans->position_.x + 0.3f;
		checkZ = (int)trans->position_.z;
		if (pWall->IsWall(checkX, checkZ))
		{
			return true;
		}
	}
	// ¶•ûŒü
	{
		checkX = (int)trans->position_.x - 0.3f;
		checkZ = (int)trans->position_.z;
		if (pWall->IsWall(checkX, checkZ))
		{
			return true;
		}
	}
	// ã•ûŒü
	{
		checkX = (int)trans->position_.x;
		checkZ = (int)trans->position_.z + 0.3f;
		if (pWall->IsWall(checkX, checkZ))
		{
			return true;
		}
	}
	// ‰º•ûŒü
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

void EnemyManager::ModelLoad(int TypeNum)
{
	EnemyHandle = (EnemyType)TypeNum;
	int hModel = -1;

	switch (EnemyHandle)
	{
	default:
		break;
	case Red:
		hModel = Model::Load("Enemy_Red.fbx");
		assert(hModel >= 0);
		break;
	case Green:
		hModel = Model::Load("Enemy_Green.fbx");
		assert(hModel >= 0);
		break;
	case Pink:
		hModel = Model::Load("Enemy_Pink.fbx");
		assert(hModel >= 0);
		break;
	case Orange:
		hModel = Model::Load("Enemy_Orange.fbx");
		assert(hModel >= 0);
		break;
	}
}

void EnemyManager::ModelDraw(int TypeNum, Transform& trans)
{
	EnemyHandle = (EnemyType)TypeNum;
	Transform MyPosition = trans;
	Model::SetTransform(EnemyHandle, MyPosition);
	Model::Draw(EnemyHandle);
}