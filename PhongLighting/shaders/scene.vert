#version 440 core
#pragma debug(on)
#pragma optimize(off)

layout(location = 4) uniform vec3 lightPosition;

layout(location = 8)  uniform mat4 modelView;
layout(location = 9)  uniform mat4 view;
layout(location = 10) uniform mat4 projection;

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 normal;

out vec3 normalVector;
out vec3 lightVector;
out vec3 viewVector;

void main(void) 
{
	vec4 viewPos = modelView * vec4(pos, 1.0);

	normalVector = normalize(mat3(modelView) * normal);

	lightVector = normalize(lightPosition - viewPos.xyz);

	viewVector = normalize(-viewPos.xyz);

	gl_Position = projection * viewPos;
}
