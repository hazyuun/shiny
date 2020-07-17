
#include "PPM.h"


PPM::PPM(unsigned int width, unsigned int height) {
	if (!width || !height) {
		width	= width == 0 ? 1 : width;
		height	= height == 0 ? 1 : height;
		std::cerr	<< "[ WARNING ] Since"
					<< ((width == 0) ?"width":"height")
					<<" can't be 0, it was initialized with 1 instead";
	}
	m_width = width;
	m_height = height;
	m_pixels = (vec3*) malloc(m_width * m_height * sizeof(vec3));
	memset(m_pixels, 0, m_width * m_height);
}
bool PPM::add_pixel(vec3 color) {
	if (m_cursor > 3 * m_width * m_height)
		return false;
	m_pixels[m_cursor++] = color;
	return true;
}

bool PPM::output(std::string path) {
	std::ofstream file(path.c_str());
	if (!file) return false;
	file<< "P3\n"<<m_width<<" "<< m_height<<"\n255\n";
	for (unsigned long i = 0; i < m_height; i++) {
		for (unsigned long j = 0; j < m_width; j++) {
			vec3 pixel = m_pixels[i * m_width + j];
			file << pixel.x << " " << pixel.y << " " << pixel.z<<"\t";
		}
		file<<"\n";
	}
	file.close();
	return true;
}

