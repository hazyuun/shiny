/*
 * File 		: light.h
 * Description 	: A virtual class for all kinds of lights
 * */

#pragma once
#include <glm/glm.hpp>

using namespace glm;

class Light{
public:
	virtual ~Light(){};
      virtual vec3 get_dir(){ return vec3(0.0f); };
      virtual double get_intensity() { return 0; };
};
