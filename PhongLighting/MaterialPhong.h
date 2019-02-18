#pragma once


namespace PhongLightingApp
{
	struct MaterialPhong 
	{
	public:
		MaterialPhong() = default;

		MaterialPhong(const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular, GLfloat shininess)
			: m_ambient(ambient), m_diffuse(diffuse), m_specular(specular), m_shininess(shininess)
		{
		}

	public:
		// Ambient color.
		const glm::vec3 m_ambient = {};

		// Diffuse color.
		const glm::vec3 m_diffuse = {};

		// Specular color.
		const glm::vec3 m_specular = {};

		// Specular shininess factor.
		GLfloat m_shininess = {};
	};
}
