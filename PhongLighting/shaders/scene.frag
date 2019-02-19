#version 440 core
#pragma debug(on)
#pragma optimize(off)

layout(location = 0) uniform vec3 ambientFactor;

layout(location = 1) uniform vec3 lightDiffuse;
layout(location = 2) uniform vec3 lightSpecular;
layout(location = 3) uniform float lightIntensity;

layout(location = 5) uniform vec3 materialDiffuse;
layout(location = 6) uniform vec3 materialSpecular;
layout(location = 7) uniform float materialShininess;

in vec3 normalVector;
in vec3 lightVector;
in vec3 viewVector;

out vec4 outColor;

void main()
{
	vec3 refl = reflect(-lightVector, normalVector);

	vec3 diffuse = max(dot(normalVector, lightVector), 0.0) * materialDiffuse * lightDiffuse * lightIntensity;

	vec3 specular = pow(max(dot(refl, viewVector), 0.0), materialShininess) * materialSpecular * lightIntensity;

	outColor = vec4(ambientFactor + diffuse + specular, 1.0);
}
