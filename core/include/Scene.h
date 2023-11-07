#pragma once

#include "CUDABuffer.h"
#include "LaunchParams.h"
#include "Model.h"

enum struct LightType {
	None = 0,
	Envmap = 1,
	Rect = 2,
	Sphere = 3,
};

struct Light {
	//��Դ����
	LightType type = LightType::None;

	//���Դradiance
	vec3f radiance{ 1.0f };

	//����/���ε���ʼ����
	vec3f position{ 0.0f };

	//���ι�������
	vec3f du{ 1.0f };
	vec3f dv{ 1.0f };

	//��뾶
	float radius = 1.0f;

	//HDR
	Texture* texture = nullptr;

	//���Դ�Ƿ�˫��
	bool doubleSided = false;
};

class Scene {
public:
	Scene(const Model* model, const Light& light) :
		model(model), light(light) {}

	~Scene() {
		if (model != NULL) {
			delete model;
			model = NULL;
		}
	}

public:
	/*! the model we are going to trace rays against */
	const Model* model;
	const Light light;
};