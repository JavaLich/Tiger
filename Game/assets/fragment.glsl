#version 330 core
in vec2 texCoord0;

out vec4 FragColor;

uniform sampler2D Sampler;
uniform vec4 color;

void main()
{
    FragColor = texture(Sampler, texCoord0)*color;
} 