#pragma once
#include "../Engine/GameObject.h"

#include "Astar.h"
#include "../Wall.h"

class Enemy_Red : public GameObject
{
	const int HOUSE_X = 21;
	const int HOUSE_Z = 21;


private :
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
	
public :
	Enemy_Red(GameObject* parent);
	~Enemy_Red();
	void Initialize() override;
	void Update()override;
	void Draw() override;
	void Release()override;
	

	/// <summary>
	/// �v���C���[�̌���ǂ�������T���֐�(�ړ�������)
	/// </summary>
	void NextPos();


	/// <summary>
	/// �꒣������邮�邷��֐�
	/// </summary>
	void MyHouse();

};

