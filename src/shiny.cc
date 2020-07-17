
/*
 * File 		: shiny.cpp
 * Description 	: Usage example
 * */

#include <iostream>
#include "shiny.h"

int main() {
	Camera cam = Camera(vec3(0.0f, 0.0f, 0.0f), 3.1415f/4);
	Scene scn = Scene(&cam);

	Sphere 	sph = Sphere(vec3(0.0f, 0.0f, -4.0f), 0.5f);
	Sphere	big = Sphere(vec3(-1.0f, -201.0f, -5.0f), 200.5f);

	/* Diffuse white */
	Material m1 = {0.8f, vec3(1.0f, 1.0f, 1.0f), vec2(0.0f)};

	/* "Yellowish" mirror */
	Material m2 = {0.8f, vec3(0.9f, 0.8f, 0.65f), vec2(0.95f, 0.25f)};

	sph.m_material = m2;
	big.m_material = m1;

	/* Little spheres around */
	for(int i = 14; i > 0; i--){
		Sphere	s = Sphere(vec3(1.0f*cos(2*i*3.14f/15 + 3.14f/2), -0.42f, 1.0f*sin(2*i*3.14f/15+ 3.14f/2)-3.5f), 0.1f);
		s.m_material = {0.8f, vec3(0.8f * i/15, 0.4f,  0.8f), vec2(0.0f)};
		scn.add_obj(s);
	}

	scn.add_obj(big);
	scn.add_obj(sph);

	scn.m_sky = vec3(0.95,0.9,1.0);

	/* Low res : */
	//scn.render(200*2,150*2,250,"output_low_res.ppm");
	/* High res : */
	scn.render(1080,720,600,"output_720p.ppm");
	//scn.render(1920,1080,600,"output_1080p.ppm");

	return 0;
}

