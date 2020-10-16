
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


	
	if(!hit) return 0.75f*m_sky;

	DirLight l = m_lights[0];
	
	bool light_hit = false;
	float brightness = 0.0f;
	for(DirLight current_l: m_lights){
		Ray dd = 
			Ray(r.point_at(t),
				-current_l.get_dir());
		if(glm::length(color(dd, d/10) - 0.75f*m_sky) < 0.01f){
			light_hit = true;
			brightness += 0.4+current_l.get_intensity()*std::max(0.0f, glm::dot(normalize(r.point_at(t) - s.m_center), -current_l.get_dir()));
			brightness /= 3.1415;
		}
		
	}
	if(!light_hit) brightness = 0.25f;

	float specular = 2*s.m_material.m_specular[0]*glm::pow(std::max(0.0f, glm::dot(normalize(reflect(r.get_dir(), normalize( r.point_at(t) - s.m_center) + rand_unit())),
									   -normalize(l.get_dir())) ), s.m_material.m_specular[1]);
	specular += 1;
	if (s.m_material.m_metal[0])
		return specular*(brightness*s.m_material.m_metal[0] * s.m_material.m_diffuse * color(Ray(r.point_at(t), reflect(r.get_dir(), normalize( r.point_at(t) - s.m_center) + s.m_material.m_metal[1] * rand_unit())), d-1));

	
	return specular*(brightness*s.m_material.m_albedo*s.m_material.m_diffuse * color(Ray(r.point_at(t), normalize( r.point_at(t) - s.m_center) + rand_unit()), d-1)) ;
}


void Scene::render(float width, float height, long samples, std::string filename){
	std::cout<<"\n> Generating "<<filename;
	std::cout<<"\n\t"<<(int)width<<"x"<<(int)height<<" | "<<samples<<" samples\n";
		
	PPM out = PPM(width, height);
	static int progress = 0;
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
			int p = (int)(100*(i+width*j)/(height*width));
			if(p != progress) {
				progress = p;
				
				std::cout<< progress <<"%";
				std::cout<<" [\033[32m";
				for(int i = 0; i < 50; i++){
					if(i<=progress/2)std::cout<<"#";
					else std::cout<<" ";
				}
				std::cout<<"\033[0m]";
				std::cout<<"\r";
				fflush(stdout);
			}
		}
	}
	out.output(filename);
}

