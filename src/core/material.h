/*
 * File 		: material.h
 * Description 	: Self explanatory !
 * */

#pragma once
#include <glm/glm.hpp>

using namespace glm;

struct Material{
	float	m_albedo;
	vec3	m_diffuse;
	vec2	m_metal;
	vec2	m_specular;
};
