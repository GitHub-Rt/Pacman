#pragma once
#include "../Engine/GameObject.h"

#include "Astar.h"
#include "../Wall.h"

class Enemy_Pink : public GameObject
{
private:
	int hModel;
	Astar* pAstar;
	Wall* pWall;
	Coordinate route;
	int count;
	int update;
	int move;

public:
	Enemy_Pink(GameObject* parent);
	~Enemy_Pink();
	void Initialize() override;
	void Update()override;
	void Draw() override;
	void Release()override;


	/// <summary>
	/// �v���C���[�̏����O�̃|�C���g��ڎw���Ĉړ�����
	/// </summary>
	void NextPos();
};

