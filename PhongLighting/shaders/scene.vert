#version 440 core
#pragma debug(on)
#pragma optimize(off)

//layout(location = 0) uniform vec3 ambientFactor;

layout(location = 1) uniform vec3 lightDiffuse;
layout(location = 2) uniform vec3 lightSpecular;
layout(location = 3) uniform float lightIntensity;
layout(location = 4) uniform vec3 lightPosition;

//layout(location = 5) uniform vec3 materialDiffuse;
//layout(location = 6) uniform vec3 materialSpecular;
//layout(location = 7) uniform vec3 materialShininess;

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
	vec4 viewPos = modelView * pos;

	normalVector = mat3(modelView) * normal;

	lightVector = lightPosition - viewPos.xyz;

	viewVector = -viewPos.xyz;

	gl_Position = projection * viewPos;

	//gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
}
