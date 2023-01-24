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
	/// 次のポジションを決める関数
	/// </summary>
	void NextPos();
};

