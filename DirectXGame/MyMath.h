#pragma once
#include <cmath>
#include <math/Matrix4x4.h>
#include <math/Vector3.h>

using namespace KamataEngine;

struct AABB {
	Vector3 min;
	Vector3 max;
};

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 MakeRotateXMatrix(const Vector3& rotate);

Matrix4x4 MakeRotateYMatrix(const Vector3& rotate);

Matrix4x4 MakeRotateZMatrix(const Vector3& rotate);

Matrix4x4 MakeRotateZMatrix(const float& rotate);

Matrix4x4 MakeRotateMatrix(const Vector3& rotate);

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Vector3 Multiply(float scalar, const Vector3& v);

Vector3 Transform(Vector3 vector, Matrix4x4 matrix);

Vector3& operator+=(Vector3& v1, const Vector3& v2);

const Vector3 operator+(const Vector3& v1, const Vector3& v2);

Vector3& operator-=(Vector3& v1, const Vector3& v2);

const Vector3 operator-(const Vector3& v1, const Vector3& v2);

AABB operator+(const AABB& aabb);

Vector3 operator*(float s, const Vector3& v);

Vector3 operator*(const Vector3& v, float s);

Matrix4x4 operator*(Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 operator*=(Matrix4x4& m1, const Matrix4x4& m2);

float EaseInSine(float num);

float EaseOutSine(float num);

bool AABBCollision(const AABB& aabb1, const AABB& aabb2);

float Length(const Vector3& v);

Vector3 Normalize(const Vector3& v);

Matrix4x4 Inverse(const Matrix4x4& m);