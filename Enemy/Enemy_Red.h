#pragma once
#include "EnemyManager.h"
class Enemy_Red : public EnemyManager
{
private :
	int hModel;

public :

	void Initialize() override;
	void Update() override;
	void Draw() override;
	

	/// <summary>
	/// 次のポジションを決める関数
	/// </summary>
	void NextPos();
};

