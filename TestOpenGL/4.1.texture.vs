#version 330 core
layout (location = 6) in vec3 aPos;
layout (location = 7) in vec3 aColor;
layout (location = 8) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
    TexCoord = aTexCoord;
}