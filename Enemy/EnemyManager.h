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
	/// �ǂȂ�true
	/// </summary>
	/// <param name="trans"></param>
	/// <returns></returns>
	bool HaveWall(Transform* trans);


	/// <summary>
	/// EnemyType���ƂɃ��f���̃��[�h���s��
	/// </summary>
	/// <param name="EnemyType"></param>
	void ModelLoad(int TypeNum);

	/// <summary>
	/// Model�̕`��
	/// </summary>
	/// <param name="TypeNum"></param>
	void ModelDraw(int TypeNum, Transform& trans);
};

