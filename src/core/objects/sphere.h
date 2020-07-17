/*
 * File 		: sphere.h
 * Description 	: Self explanatory !
 * */

#pragma once
#include "object.h"

class Sphere: public Object{
public:
	vec3	m_center;
	float 	m_radius;
	Sphere(vec3 center, float radius)
	:m_center(center), m_radius(radius){}

	float hit_test(Ray r){
		vec3 d = r.get_org() - m_center;
		float a = dot(r.get_dir(), r.get_dir());
		float b = 2 * dot(r.get_dir(), d);
		float c = dot(d, d) - m_radius * m_radius;
		float delta = b*b - 4*a*c;
		return delta > 0? (-b - sqrt(delta))/2*a :-1;
	};

	~Sphere(){};
};
