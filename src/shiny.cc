
/*
 * File 		: shiny.cpp
 * Description 	: Usage example
 * */

#include <iostream>
#include "shiny.h"
char usage(char* prgrm){
	fprintf(stdout, "usage: %s width height samples output\n", prgrm);
	return 1;
}
int main(int argc, char **argv) {
	if(argc != 5){
		return usage(argv[0]);
	}
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int samples = atoi(argv[3]);
	const char* path = argv[4];

	Camera cam = Camera(vec3(0.0f, 0.0f, 0.0f), 3.1415f/4);
	Scene scn = Scene(&cam);

	Sphere 	sph = Sphere(vec3(0.0f, 0.0f, -4.0f), 0.5f);
	Sphere	big = Sphere(vec3(-1.0f, -201.0f, -5.0f), 200.5f);

	/* Diffuse white */
	Material m1 = {0.8f, vec3(1.0f, 1.0f, 1.0f), vec2(0.0f), vec2(16.0f, 64.0f)};

	/* "Yellowish" mirror */
	Material m2 = {0.8f, vec3(0.5f, 0.4f, 0.3f), vec2(1.0f, 0.0f), vec2(16.0f, 128.0f)};

	sph.m_material = m2;
	big.m_material = m1;

	/* Little spheres around */

	for(int i = 14; i > 0; i--){
		Sphere	s = Sphere(vec3(1.0f*cos(2*i*3.14f/15 + 3.14f/2), -0.42f, 1.0f*sin(2*i*3.14f/15+ 3.14f/2)-3.5f), 0.1f);
		s.m_material = {0.8f, vec3(0.8f * i/15, 0.4f,  0.8f), vec2(0.0f), vec2(16.0f, 64.0f)};
		scn.add_obj(s);
	}


	scn.add_obj(big);
	scn.add_obj(sph);

	DirLight sun = DirLight(vec3(0.5, -1, -0.25), 4);
	
	scn.add_light(sun);
	
	scn.m_sky = vec3(0.4, 0.3, 0.9);

	
	scn.render(width, height, samples, path);
	
	return 0;
}

