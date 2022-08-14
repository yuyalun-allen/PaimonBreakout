#pragma once
#include <glad\glad.h>
#include <glm.hpp>

#include <iostream>
#include <string>

class Shader
{
public:
    Shader(){}
	Shader(const char* vsSrc, const char* fsSrc);
	Shader& Use();

    void setBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value);
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value);
    }

    void setFloat3(const std::string& name, const glm::vec3& value) const
    {
        glUniform3f(glGetUniformLocation(shaderID, name.c_str()), value.x, value.y, value.z);
    }

    void setMat4(const std::string& name, const glm::mat4& mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
private:
	unsigned int shaderID;
private:
    void CheckCompileErrors(unsigned int obj, std::string type);
};

