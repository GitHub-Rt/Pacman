#pragma once
#include "../Engine/GameObject.h"

class EnemyManager : public GameObject
{
	enum EnemyType
	{
		Red = 0,
		Green,
		Pink,
		Orange,
		MAX_TYPE
	};
	EnemyType EnemyHandle;

public:
	EnemyManager(GameObject* parent);
	~EnemyManager();
	void Initialize() override;
	void Update()override;
	void Draw() override;
	void Release()override;

	
	/// <summary>
	/// 壁ならtrue
	/// </summary>
	/// <param name="trans"></param>
	/// <returns></returns>
	bool HaveWall(Transform* trans);


	/// <summary>
	/// EnemyTypeごとにモデルのロードを行う
	/// </summary>
	/// <param name="EnemyType"></param>
	void ModelLoad(int TypeNum);

	/// <summary>
	/// Modelの描画
	/// </summary>
	/// <param name="TypeNum"></param>
	void ModelDraw(int TypeNum, Transform& trans);
};

