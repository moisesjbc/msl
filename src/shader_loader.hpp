/***
 * Copyright 2013, 2014 Moises J. Bonilla Caraballo (Neodivert)
 *
 * This file is part of MSL.
 *
 * MSL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License v3 as published by
 * the Free Software Foundation.
 *
 * MSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with COMO.  If not, see <http://www.gnu.org/licenses/>.
***/

#ifndef SHADER_LOADER_HPP
#define SHADER_LOADER_HPP

/***
 * Includes
 ***/

// OpenGL
// http://www.opengl.org/discussion_boards/showthread.php/172481-glGenBuffer-was-not-declared
extern "C" {
    #define GL_GLEXT_PROTOTYPES
    #include <GL/gl.h>
}

// STD
#include <fstream>
#include <stdexcept>

namespace msl {

/***
 * File main class
 ***/
class ShaderLoader
{
    public:
        /***
         * 1. Construction
         ***/
        ShaderLoader() = default;
        ShaderLoader( const ShaderLoader& ) = delete;
        ShaderLoader( ShaderLoader&& ) = delete;


        /***
         * 2. Destruction
         ***/
        ~ShaderLoader() = default;


        /***
         * 3. Shader loading
         ***/
        GLuint loadShaderProgram( const char* vertexShaderFile, const char* fragmentShaderFile );
        GLuint loadShaderProgram( const char* vertexShaderFile, const char* geometryShaderFile, const char* fragmentShaderFile );


        /***
         * 4. Operators
         ***/
        ShaderLoader& operator=( const ShaderLoader& ) = delete ;
        ShaderLoader& operator=( ShaderLoader&& ) = delete;


    private:
        /***
         * 5. Auxiliar methods
         ***/
        void loadShaderObject( GLenum shaderType, const char* shaderFile );
        void readFile( const char* file, GLchar* buffer, const unsigned int n );
        void throwLinkingError() const;
        void throwCompilingError( GLuint shaderObject ) const;


    private:
        /***
         * Attributes
         ***/
        // Current program being built.
        GLuint shaderProgram;
};

} // namespace msl

#endif // SHADER_LOADER_HPP
