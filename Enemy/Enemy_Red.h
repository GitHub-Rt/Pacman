#pragma once
#include "../Engine/GameObject.h"

class Enemy_Red : public GameObject
{
private :
	int hModel;

public :
	Enemy_Red(GameObject* parent);
	~Enemy_Red();
	void Initialize() override;
	void Update()override;
	void Draw() override;
	void Release()override;
	

	/// <summary>
	/// ƒvƒŒƒCƒ„[‚ÌŒã‚ë‚ğ’Ç‚¢‚©‚¯‚é’TõAI
	/// </summary>
	void NextPos();
};

