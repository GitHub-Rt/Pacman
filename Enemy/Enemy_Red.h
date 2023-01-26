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
	/// Ÿ‚Ìƒ|ƒWƒVƒ‡ƒ“‚ğŒˆ‚ß‚éŠÖ”
	/// </summary>
	void NextPos();
};

