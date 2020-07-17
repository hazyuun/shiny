/*
 * File 		: PPM.h
 * Description 	: A utility to export images in PPM format
 * */

#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <glm/glm.hpp>

using namespace glm;

class PPM {
	vec3*			m_pixels;
	unsigned int	m_width, m_height;
	unsigned long	m_cursor = 0;
public:
	PPM(unsigned int width, unsigned int height);
	bool add_pixel(vec3 color);
	bool output(std::string path);
};
