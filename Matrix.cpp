#include "Matrix.h"
//�P�ʍs��֐�
Matrix4 Identity()
{
	Matrix4 matIdentity;
	/*
		1,0,0,0
		0,1,0,0
		0,0,1,0
		0,0,0,1
	*/
	matIdentity.m[0][0] = 1;
	matIdentity.m[1][1] = 1;
	matIdentity.m[2][2] = 1;
	matIdentity.m[3][3] = 1;
	return matIdentity;
}
//��]�s��
Matrix4 Rot(Vector3 worldTransform_)
{
	//�e���p��]�s���錾
	Matrix4 matRot;
	Matrix4 matRotX;
	Matrix4 matRotY;
	Matrix4 matRotZ;
	//x���̉�]�s��錾
	matRotX = Identity();
	//y���̉�]�s��錾
	matRotY = Identity();
	//z���̉�]�s��錾
	matRotZ = Identity();
	//x
	matRotX.m[1][1] = cos(worldTransform_.x);
	matRotX.m[1][2] = sin(worldTransform_.x);
	matRotX.m[2][1] = -sin(worldTransform_.x);
	matRotX.m[2][2] = cos(worldTransform_.x);
	//y
	matRotY.m[0][0] = cos(worldTransform_.y);
	matRotY.m[2][0] = sin(worldTransform_.y);
	matRotY.m[0][2] = -sin(worldTransform_.y);
	matRotY.m[2][2] = cos(worldTransform_.y);
	//z
	matRotZ.m[0][0] = cos(worldTransform_.z);
	matRotZ.m[0][1] = sin(worldTransform_.z);
	matRotZ.m[1][0] = -sin(worldTransform_.z);
	matRotZ.m[1][1] = cos(worldTransform_.z);
	return matRot = matRotZ *= matRotX *= matRotY;
}
//�X�P�[���s��
Matrix4 Scale(Vector3 worldTransform_)
{
	//�X�P�[�����O�s���錾
	Matrix4 matScale;
	matScale = Identity();
	/*
		sx,0,0,0
		0,sy,0,0
		0,0,sz,0
		0,0,0,1
	*/
	//�X�P�[�����O�{�����s��ɐݒ肷��
	matScale.m[0][0] = worldTransform_.x;//sx
	matScale.m[1][1] = worldTransform_.y;//sy
	matScale.m[2][2] = worldTransform_.z;//sz
	matScale.m[3][3] = 1;
	return matScale;
}
//���s�ړ��s��
Matrix4 Transform(Vector3 worldTransform_)
{
	//���s�ړ��s���錾
	Matrix4 matTrans;
	matTrans = Identity();
	//�ړ��ʂ��s��ɐݒ肷��
	//z�̈ړ��ʐݒ�
	matTrans.m[0][2] = 0;
	matTrans.m[1][2] = 0;
	matTrans.m[3][2] = worldTransform_.z;
	//x�̈ړ��ʐݒ�
	matTrans.m[1][0] = 0;
	matTrans.m[2][0] = 0;
	matTrans.m[3][0] = worldTransform_.x;
	//y�̈ړ��ʐݒ�
	matTrans.m[0][1] = 0;
	matTrans.m[2][1] = 0;
	matTrans.m[3][1] = worldTransform_.y;
	//�s��[0][4]�̐ݒ�
	matTrans.m[0][3] = 0;
	matTrans.m[1][3] = 0;
	matTrans.m[2][3] = 0;
	matTrans.m[3][3] = 1;
	return matTrans;
}

Vector3 BulletRot(Vector3 velocity, Matrix4 transform)
{
	Vector3 bulletMath;

	bulletMath.x = velocity.x * transform.m[0][0];
	bulletMath.x += velocity.y * transform.m[1][0];
	bulletMath.x += velocity.z * transform.m[2][0];
	bulletMath.x += velocity.x * transform.m[3][0];

	bulletMath.y = velocity.x * transform.m[0][1];
	bulletMath.y += velocity.y * transform.m[1][1];
	bulletMath.y += velocity.z * transform.m[2][1];
	bulletMath.y += velocity.y * transform.m[3][1];

	bulletMath.z = velocity.x * transform.m[0][2];
	bulletMath.z += velocity.y * transform.m[1][2];
	bulletMath.z += velocity.z * transform.m[2][2];
	bulletMath.z += velocity.z * transform.m[3][2];

	return bulletMath;
}

Vector3 Normalize(Vector3 vector)
{
	float len = Length(vector);
	if (len != 0)
	{
		return vector /= len;
	}
	return vector;
}

float Length(Vector3 vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

Vector3 Vectornorm(Vector3 vec1, Vector3 vec2)
{
	Vector3 vecPos = vec1 -= vec2;

	return vecPos;
}

//clamp�֐�
float Clamp(float min, float max, float num)
{

	if (min > num)
	{
		return min;
	}
	else if (max < num)
	{
		return max;
	}
	return num;
}