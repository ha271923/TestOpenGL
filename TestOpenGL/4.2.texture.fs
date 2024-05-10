#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTextureChannel;
uniform sampler2D ourFaceChannel;

void main()
{
    FragColor = texture(ourTextureChannel, TexCoord) * texture(ourFaceChannel, TexCoord);
}