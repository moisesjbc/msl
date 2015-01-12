# MSL - Moi's Shader Loader

## About
MSL is a small static library that inplements a simple shader loader for 
OpenGL. Just call one method and load your precious shader program (*).

(*) Only shader programs including vertex + fragment shaders or 
vertex + geometry + fragment shaders can be loaded currently using MSL.

## Instalation (only tested on Ubuntu 14.04)

1. Clone this repository in local.

2. Enter in the downloaded directory.

3. Install the library on your system.

```
cmake .
make
sudo make install
```

## Sample code

```c++
#include "msl.hpp"
// OpenGL setup
... 

try {
	// Load the shader program.
	msl::ShaderLoader shaderLoader;
	GLuint programID = 
		shaderLoader.loadShaderProgram( "basicVertexShader.shader", 
						"/basicFragmentShader.shader" );

	// Make the shader program the active one.
	glUseProgram( programID );

	// Use the shader program.
	...

	// Free resources.
	glDestroyProgram( programID );
}catch( std::runtime_error& ex ){
	// Cleanup code.
	...
}
```

