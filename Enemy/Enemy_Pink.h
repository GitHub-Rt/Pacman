#pragma once
#include "../Engine/GameObject.h"

#include "Astar.h"
#include "../Wall.h"

class Enemy_Pink : public GameObject
{
	const int HOUSE_X = 1;
	const int HOUSE_Z = 21;


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



	/// <summary>
	/// �꒣������邮�邷��֐�
	/// </summary>
	void MyHouse();

};

