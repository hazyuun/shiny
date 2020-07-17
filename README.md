# shiny
A tiny raytracer just for fun ! <br /> ![C/C++ CI](https://github.com/A-Rain-Lover/shiny/workflows/C/C++%20CI/badge.svg)
# Output example
|Diffuse spheres around a reflective one| Same with perturbated reflexion |
|----|----|
|<img src="https://github.com/A-Rain-Lover/shiny/blob/master/output/1.png" />|<img src="https://github.com/A-Rain-Lover/shiny/blob/master/output/2.png" />|
# TODO : 
Objects : 
- [x] Spheres
- [ ] Planes
- [ ] Cubes
- [ ] Any 3D mesh 

Materials :
- [x] Lambertian diffuse
- [x] Reflective metal
- [ ] Refractive glass
- [ ] Textures

Lights : 
- [ ] Emissive materials

# Getting started
## Dependencies
I used `glm` math library in this project, you can install it using your package manager
## Usage example
Use `src/shiny.cc` as a usage example.<br />
compile it with :
```
$ mkdir bin
```
```
$ make all
```
Then execute it to render the output image.
