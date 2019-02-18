#version 440 core
#pragma debug(on)
#pragma optimize(off)

layout(location = 0) uniform vec3 ambientFactor;

layout(location = 5) uniform vec3 materialDiffuse;
layout(location = 6) uniform vec3 materialSpecular;
layout(location = 7) uniform float materialShininess;

in vec3 normalVector;
in vec3 lightVector;
in vec3 viewVector;

out vec4 outColor;

void main()
{
	vec3 N = normalize(normalVector);
	vec3 L = normalize(lightVector);
	vec3 V = normalize(viewVector);

	vec3 R = reflect(-L, N);

	vec3 diffuse = max(dot(N, L), 0.0) * materialDiffuse;

	vec3 specular = pow(max(dot(R, V), 0.0), materialShininess) * materialSpecular;

	outColor = vec4(ambientFactor + diffuse + specular, 1.0);

	//outColor = vec4(ambientFactor, 1.0f);

	//outColor = vec4(0.0f, 0.2f, 0.8f, 1.0f);
}
