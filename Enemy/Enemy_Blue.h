#pragma once
#include "../Engine/GameObject.h"

#include "Astar.h"
#include "../Wall.h"

class Enemy_Blue : public GameObject
{
	const int HOUSE_X = 21;
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

	XMFLOAT3 bluePos;

public:
	Enemy_Blue(GameObject* parent);
	~Enemy_Blue();
	void Initialize() override;
	void Update()override;
	void Draw() override;
	void Release()override;


	/// <summary>
	/// パックマンを中心にして、オイカケ（赤）の点対称の位置を最短距離で目指して行動する
	/// </summary>
	void NextPos();



	/// <summary>
	/// 縄張りをぐるぐるする関数
	/// </summary>
	void MyHouse();

};

