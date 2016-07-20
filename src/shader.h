#pragma once
#include <stdint.h>
#include <GL/glew.h>
#include <map>
#include <string>


class Shader {
public:
    Shader(const char *, const char *);
    ~Shader();

    void bind();
    void addUniform(const std::string &);

    void updateUniform1i(const std::string &, int) const;
    void updateUniform2i(const std::string &, int, int) const;
    void updateUniform1f(const std::string &, float) const;
    void updateUniform2f(const std::string &, float, float) const;
    void updateUniform2fv(const std::string &, int, float *) const;

    inline const int getProgram() const {return program;};

private:
    std::map<const std::string, int32_t> uniformMap;
    int compile(const char *, uint32_t);
    void link(uint32_t, uint32_t);

    int program;
};
