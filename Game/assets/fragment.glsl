#version 330 core
in vec2 texCoord0;

out vec4 FragColor;

uniform sampler2D Sampler;

void main()
{
    FragColor = texture(Sampler, texCoord0);
} 