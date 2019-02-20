#pragma once


namespace PhongLightingApp
{
	class Scene
		: public CommonLibOgl::IScene
	{
	public:
		Scene(const glm::vec3& backgroundColor,
			CommonLibOgl::CameraPtr& spCamera,
			GLuint programId);

		virtual ~Scene();

		virtual bool initialize() override;

		virtual void resize(GLfloat aspectRatio) override;

		// Render the derived scene.
		virtual void render() const override;

		//////////////////////////////////////////////////////////////////////////
		// Camera control.
		//////////////////////////////////////////////////////////////////////////

		virtual void translateCamera(const glm::vec3& diff) override;

		virtual void rotateCamera(const glm::vec3& degrees) override;

		virtual void scaleCamera(GLfloat amount) override;

		GLfloat getCameraScale() const;

	private:
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;

		// Initialize scene contents (usually something that will be rendered - e.g. a cube).
		bool initializeContents();

		// Update OpenGL uniforms such as ModelView matrix.
		void updateUniforms() const;

	private:
		glm::vec3 m_backgroundColor;

		CommonLibOgl::CameraPtr m_spCamera;

		// GLSL program ID.
		const GLuint m_programId = {};

		//////////////////////////////////////////////////////////////////////////

		// Ambient light color.
		glm::vec3 m_ambientColor;

		// Ambient light intensity.
		GLfloat m_ambientIntensity;

		// Light source.
		Light m_light;

		// Items in the scene: a triangle.

		GLuint m_vao = {};
		GLuint m_vbo = {};

		GLuint m_index = {};          // index buffer
		GLsizei m_indexCount = {};    // number of indices

		GLuint m_normal = {};         // normal buffer

		// Initial position of the cube in the scene. Can be useful if we will need to return to it.
		const glm::vec4 m_posInitial;

		// Material for the scene items.
		MaterialPhong m_material;

		// Ambient factor for the Phong lighting.
		const glm::vec3 m_ambientFactor;

		// A triangle primitive.
		CommonLibOgl::Triangle m_triangle;

		CommonLibOgl::Cube m_cube;
	};
}
