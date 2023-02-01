#include "Wall.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "Wall.h"

//�R���X�g���N�^
Wall::Wall(GameObject* parent)
    :GameObject(parent, "Wall")//,hModel_(-1)
{
    hModel_[0] = -1;
    hModel_[1] = -1;
}

//�f�X�g���N�^
Wall::~Wall()
{
}

//������
void Wall::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_[1] = Model::Load("Wall.fbx");
    assert(hModel_[1] >= 0);

    //���f���f�[�^�̃��[�h
    hModel_[0] = Model::Load("Floar.fbx");
    assert(hModel_[0] >= 0);

    CsvReader csv;
    csv.Load("Map.csv"); //Map�̃f�[�^�����[�h

    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            map_[i][j] = csv.GetValue(i, j);
        }
    }
}

//�X�V
void Wall::Update()
{
}

//�`��
void Wall::Draw()
{
    for (int x = 0; x < MAP_ROW; x++)                               //Wall�̏o���̏���
    {
        transform_.position_.x = x;                    //�`�}�X�ǔz�u

        for (int z = 0; z < MAP_COL; z++)                        //Wall�̏o���̏���

        {
            int type = map_[x][z]; //&&�ǂ������������� �}�b�v�Ƀu���b�N�̏���
            transform_.position_.z = z ;                   //�`�}�X�ǔz�u
            Model::SetTransform(hModel_[type], transform_); //�z��[0]��[1]�ŕǂ����������ł���
            Model::Draw(hModel_[type]);                    //�z��[0]��[1]�ŕǂ����������ł���
        }
    }
}

//�J��
void Wall::Release()
{
}

//�����͕ǂ��ǂ���
bool Wall::IsWall(int x, int z)
{
    //return map_[x][z] == 0 ? false : true;       �O�����Z�q

    return map_[x][z] == 1; //x z ���Preturn�ŕԂ�

    if (map_[x][z] == 1) //�܂��Ղ̂��A������[1]��������yes��no��return�Ԃ�
    {
        return false;
    }
    else
    {
        return true;
    }
}
