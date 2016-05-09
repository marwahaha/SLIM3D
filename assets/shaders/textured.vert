#version 300 es

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec4 vColor;
layout (location = 2) in vec2 vTexture;
layout (location = 3) in vec3 vNormal;

uniform mat4	projectionMatrix;
uniform mat4	viewMatrix;
uniform mat4	modelMatrix;

out	vec4	color;
out	vec2	textureCoord;

void	main()
{
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vPosition, 1.0);
    color = vec4(1.0, 1.0, 1.0, 1.0);
    textureCoord = vTexture;
}