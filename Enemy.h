#include "WorldTransform.h"
#include "ViewProjection.h"
#include "Model.h"

class Enemy
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(Model* model,uint32_t textureHandle);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw(ViewProjection& viewProjection);

	//���[���h���W���擾
	Vector3 GetWorldPosition();

private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//���f��
	Model* model_ = nullptr;
	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;
};