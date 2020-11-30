/*
 * File 		: scene.h
 * Description 	: A scene is a collection of objects and a camera
 * */

#pragma once
#include <vector>

#include "objects/objects.h"
#include "../util/PPM.h"
#include "material.h"
#include "camera.h"
#include "ray.h"
#include "lights/directionnal.h"


class Scene {
	Camera*					m_camera;
	/* Only spheres for now */
	std::vector<Sphere> 	m_objects;

	std::vector<DirLight> 	m_lights;

public:
	bool m_gamma_correction = true;
	vec3 m_sky = vec3(0.99,0.99,0.99);

	Scene(Camera* cam) :m_camera(cam) {}

	inline void add_obj(Sphere o){
		m_objects.push_back(o);
	}

	inline void add_light(DirLight l){
		m_lights.push_back(l);
	}

	inline vec3 grad_bg(Ray r, vec3 color1, vec3 color2){
		float t = (r.get_dir().y+1)/2;
		return t * color1 + (1 - t) * color2;
	}

	static inline vec3 rand_unit(){
		float phi = acos(-1) * drand48();
		float theta = 2 * acos(-1) * drand48();

		float x = sin(phi) * cos(theta);
		float y = sin(phi) * sin(theta);
		float z = cos(phi);

		return (float)drand48()*vec3(x, y, z);
	}

	static inline vec3 reflect(const vec3 I, const vec3 N) {
	    return I - 2.0f*dot(I,N)*N;
	}

	vec3 color(Ray r, long d);
	void render(float width, float height, long samples, std::string filename);

};
