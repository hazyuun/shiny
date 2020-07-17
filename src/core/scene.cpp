
#include "scene.h"


vec3 Scene::color(Ray r, long d){
	if(d<=0) return vec3(0,0,0);

	Sphere s = m_objects[0];
	float t = s.hit_test(r);
	bool hit = false;

	for(Sphere current: m_objects){
		float d = current.hit_test(r);
		if(d > 0 && (d <= t || t < 0)){
			t = d;
			s = current;
			hit = true;
		}
	}

	if(!hit) return m_sky;
	if (s.m_material.m_metal[0])
		return s.m_material.m_metal[0] * s.m_material.m_diffuse * color(Ray(r.point_at(t), reflect(r.get_dir(), normalize( r.point_at(t) - s.m_center) + s.m_material.m_metal[1] * rand_unit())), d-1);

	return s.m_material.m_albedo*s.m_material.m_diffuse * color(Ray(r.point_at(t), normalize( r.point_at(t) - s.m_center) + rand_unit()), d-1) ;
}


void Scene::render(float width, float height, long samples, std::string filename){
	PPM out = PPM(width, height);

	for(int j = 0; j < height; j++){
		for(int i = 0; i < width; i++){
			vec3 clr = vec3(0.0);
			long s = samples;
			while(s --> 0){
				clr += color(m_camera->ray(i+drand48(), j+drand48(), width, height), 16);
			}
			clr /= samples;

			/* Only floats from 0 to 1 */
			clr.x = (clr.x > 1.0)?1.0f:clr.x;
			clr.y = (clr.y > 1.0)?1.0f:clr.y;
			clr.z = (clr.z > 1.0)?1.0f:clr.z;

			clr.x = (clr.x < 0.0)?0.0f:clr.x;
			clr.y = (clr.y < 0.0)?0.0f:clr.y;
			clr.z = (clr.z < 0.0)?0.0f:clr.z;

			/* Gamma correction */
			if(m_gamma_correction){
				clr.r = sqrt(clr.r);
				clr.g = sqrt(clr.g);
				clr.b = sqrt(clr.b);
			}
			clr *= 255.0f;
			out.add_pixel((ivec3)(clr));
			std::cout<< (int)(100*(i+width*j)/(height*width)) <<"%"<<std::endl;
		}
	}
	out.output(filename);
}

