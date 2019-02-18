#pragma once


namespace PhongLightingApp
{
	// Light characteristics.
	// Don't include "renderable" settings like vertex buffer, etc.;
	// if you need these, create a separate LightSource object.
	struct Light
	{
	public:
		Light() = default;

		Light(const glm::vec3& diffuse, const glm::vec3& specular, GLfloat intensity, const glm::vec3& position)
			: m_diffuse(diffuse), m_specular(specular), m_intensity(intensity), m_position(position)
		{
		}

	public:
		// Diffuse color.
		glm::vec3 m_diffuse;

		// Specular color.
		glm::vec3 m_specular;

		// Light intensity.
		GLfloat m_intensity = {};

		// Position of the light in the scene.
		glm::vec3 m_position;
	};
}
