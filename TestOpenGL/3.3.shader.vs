#version 330 core
layout (location = 6) in vec3 aPos;
layout (location = 7) in vec3 aColor;
out vec3 ourColor;
void main()
{
   gl_Position = vec4(aPos, 1.0);
   ourColor = aColor;
}