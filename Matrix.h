#pragma once
#include "WorldTransform.h"
#include "DirectXCommon.h"
//�P�ʍs��֐�
Matrix4 Identity();

//��]�s��
Matrix4 Rot(Vector3 worldTransform_);

//�X�P�[���s��
Matrix4 Scale(Vector3 worldTransform_);

//���s�ړ��s��
Matrix4 Transform(Vector3 worldTransform_);

//�e�̉�]�p�v�Z
Vector3 BulletRot(Vector3 velocity, Matrix4 transform);

//���K���p
Vector3 Normalize(Vector3 vector);

//����
float Length(Vector3 vector);

Vector3 Vectornorm(Vector3 vec1, Vector3 vec2);

float Clamp(float min, float max, float num);