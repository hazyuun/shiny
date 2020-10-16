/*
 * File 		: directionnal.h
 * Description 	: Self explanatory !
 * */

#pragma once

#include <glm/glm.hpp>
#include "light.h"

using namespace glm;

class DirLight: public Light{
      double m_intensity;
	vec3 m_dir;
public:
	DirLight(vec3 dir, double intensity) :m_dir(dir), m_intensity(intensity){}

	inline double get_intensity() const { return m_intensity; }
	inline vec3 get_dir() const { return m_dir; };
      ~DirLight(){};
};
