#pragma once
#include "../Engine/GameObject.h"

#include "Astar.h"
#include "../Wall.h"

class Enemy_Red : public GameObject
{
private :
	int hModel;
	Astar* pAstar;
	Wall* pWall;
	Coordinate route;
	int count;
	int update;
	int move;

public :
	Enemy_Red(GameObject* parent);
	~Enemy_Red();
	void Initialize() override;
	void Update()override;
	void Draw() override;
	void Release()override;
	

	/// <summary>
	/// プレイヤーの後ろを追いかける探索関数(移動も込み)
	/// </summary>
	void NextPos();
};

