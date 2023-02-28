#pragma once
#include "Engine/GameObject.h"

const int MAP_SIZE = 23;


//�X�e�[�W���Ǘ�����N���X
class Wall : public GameObject
{
    const int MAP_ROW = 23;
    const int MAP_COL = 23;



    //int hModel_;    //���f���ԍ�Wall�̕ϐ�
    //int hModel2_;    //���f���ԍ�Floar�̕ϐ�

    int hModel_[2]; //[0]���@[1]��

    int map_[23][23]; //2�����z��




public:
    //�R���X�g���N�^
    Wall(GameObject* parent);

    //�f�X�g���N�^
    ~Wall();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    /// <summary>
    /// �ǂ��ǂ����𔻒f
    /// </summary>
    /// <param name="x"></param>
    /// <param name="z"></param>
    /// <returns>�ǂ�������true</returns>
    bool IsWall(int x, int z);

};