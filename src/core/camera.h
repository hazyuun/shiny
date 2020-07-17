/*
 * File 		: camera.h
 * Description 	: Self explanatory !
 * */

#pragma once

#include <glm/glm.hpp>
#include "ray.h"

using namespace glm;

class Camera{
	vec3	m_org;
	float	m_fov;
public:
	Camera(vec3 org, float fov): m_org(org), m_fov(fov){};

	inline Ray ray(float i, float j, float width, float height) const {
		float x =  (2*(i + 0.5f)/(float)width - 1)*tan(m_fov/2.0f)*width/(float)height;
		float y = -(2*(j + 0.5f)/(float)height - 1)*tan(m_fov/2.0f);
		vec3 dir = normalize(vec3(x, y, -1));
		return Ray(m_org, dir);
	};

};
