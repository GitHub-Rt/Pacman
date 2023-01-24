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
	/// Ÿ‚Ìƒ|ƒWƒVƒ‡ƒ“‚ğŒˆ‚ß‚éŠÖ”
	/// </summary>
	void NextPos();
};

