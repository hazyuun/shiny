/*
 * File 		: object.h
 * Description 	: A virtual class for all kinds of objects
 * */

#pragma once
#include <glm/glm.hpp>
#include "../ray.h"
#include "../material.h"

using namespace glm;

class Object{
public:
	Material m_material;
public:
	virtual float hit_test(Ray r){ return -1; };
	virtual ~Object(){};
};
