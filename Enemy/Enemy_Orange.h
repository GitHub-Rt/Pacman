#pragma once
#include "../Engine/GameObject.h"

#include "Astar.h"
#include "../Wall.h"

class Enemy_Orage : public GameObject
{
	const int HOUSE_X = 1;
	const int HOUSE_Z = 1;


private:
	int hModel;
	Astar* pAstar;
	Wall* pWall;
	Coordinate route;
	int count;
	int update;
	int move;

	int timer;
	int tourX = 4;
	int tourZ = 3;

	bool isTime;
	bool isPatrol;

public:
	Enemy_Orage(GameObject* parent);
	~Enemy_Orage();
	void Initialize() override;
	void Update()override;
	void Draw() override;
	void Release()override;


	/// <summary>
	/// パックマンより遠いところにいるときは追いかけ、近いところにいるときは逃げる
	/// </summary>
	void NextPos();



	/// <summary>
	/// 縄張りをぐるぐるする関数
	/// </summary>
	void MyHouse();

};

