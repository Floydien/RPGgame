#include "shader.h"
#include <stdio.h>

Shader::Shader(const char *vertexShaderSource,
    const char *fragmentShaderSource) {

    uint32_t vs,fs;
    vs = compile(vertexShaderSource, GL_VERTEX_SHADER);
    fs = compile(fragmentShaderSource, GL_FRAGMENT_SHADER);
    link(vs, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
}

Shader::~Shader() {
    glDeleteProgram(program);
}

int Shader::compile(const char *vertexShaderSource, uint32_t shaderType) {
    int shaderID = glCreateShader(shaderType);
    glShaderSource(shaderID, 1, &vertexShaderSource, NULL);
    glCompileShader(shaderID);

    int success;
    char info[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shaderID, 512, NULL, info);
        printf("ERROR: Failed to compile shader: %s\n", info);
        return 0;
    }

    return shaderID;
}

void Shader::link(uint32_t vertexShader, uint32_t fragmentShader) {
    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    int success;
    char info[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, info);
    }
}

void Shader::bind() {
    glUseProgram(program);
}

void Shader::addUniform(const std::string &name) {
    int32_t location = glGetUniformLocation(program, name.c_str());
    uniformMap.insert(std::pair<const std::string, int32_t>(name, location));
}

void Shader::updateUniform1i(const std::string &name, int x) const {
    glUniform1i(uniformMap.at(name), x);
}

void Shader::updateUniform2i(const std::string &name, int x, int y) const {
    glUniform2i(uniformMap.at(name), x, y);
}

void Shader::updateUniform1f(const std::string &name, float x) const {
    glUniform1f(uniformMap.at(name), x);
}

void Shader::updateUniform2f(const std::string &name, float x, float y) const {
    glUniform2f(uniformMap.at(name), x, y);
}

void Shader::updateUniform2fv(const std::string &name, int n, float *v) const {
    glUniform2fv(uniformMap.at(name), n, v);
}