#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Wall : public GameObject
{
    //int hModel_;    //���f���ԍ�Wall�̕ϐ�
    //int hModel2_;    //���f���ԍ�Floar�̕ϐ�

    int hModel_[2]; //[0]���@[1]��

    int map_[15][15]; //15�~15��2�����z��




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

    //�����͕ǁH
    bool IsWall(int x, int z);

};