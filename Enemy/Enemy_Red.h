#pragma once
#include "EnemyManager.h"
class Enemy_Red : public EnemyManager
{
private :
	int hModel;

public :

	void Initialize();
	void Draw();

	/// <summary>
	/// ���̃|�W�V���������߂�֐�
	/// </summary>
	void NextPos();
};

