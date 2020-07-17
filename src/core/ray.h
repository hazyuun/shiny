/*
 * File 		: ray.h
 * Description 	: A ray is basically an origin point and a direction
 * */

#pragma once
#include <glm/glm.hpp>

using namespace glm;

class Ray{
	vec3 m_org, m_dir;
public:
	Ray(vec3 org, vec3 dir) :m_org(org), m_dir(dir){}

	inline vec3 point_at(float t) const { return m_org+t*m_dir; }
	inline vec3 get_org() const { return m_org; };
	inline vec3 get_dir() const { return m_dir; };

};
