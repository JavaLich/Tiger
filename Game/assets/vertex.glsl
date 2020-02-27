#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 texCoord;

out vec2 texCoord0;

uniform mat4 modelMatrix;
uniform mat4 viewProj;

void main()
{
    gl_Position = viewProj * modelMatrix * vec4(aPos, 1.0);
    texCoord0 = texCoord;
}