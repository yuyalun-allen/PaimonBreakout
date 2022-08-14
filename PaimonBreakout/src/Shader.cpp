#include "Shader.h"

Shader::Shader(const char* vsSrc, const char* fsSrc)
{
	unsigned int vs, fs;
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vsSrc, nullptr);
	glCompileShader(vs);
	CheckCompileErrors(vs, "VERTEX SHADER");

	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fsSrc, nullptr);
	glCompileShader(fs);
	CheckCompileErrors(fs, "FRAGMENT SHADER");

	this->shaderID = glCreateProgram();
	glAttachShader(shaderID, vs);
	glAttachShader(shaderID, fs);
	glLinkProgram(shaderID);
	CheckCompileErrors(shaderID, "PROGRAM");

	glDeleteShader(vs);
	glDeleteShader(fs);
}

Shader& Shader::Use()
{
	glUseProgram(this->shaderID);
	return *this;
}

void Shader::CheckCompileErrors(unsigned int obj, std::string type)
{
	int success;
	char infoLog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(obj, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(obj, 1024, nullptr, infoLog);
			std::cerr << "ERROR: Failed to compile a " << type << '\n' 
				<< infoLog << '\n' << std::endl;
		}
	}
	else
	{
		glGetProgramiv(obj, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(obj, 1024, nullptr, infoLog);
			std::cerr << "ERROR: Failed to compile a " << type << '\n'
				<< infoLog << '\n' << std::endl;
		}
	}

}
