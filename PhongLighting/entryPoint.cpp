#include "stdafx.h"

#include "Resource.h"
#include "Scene.h"

//////////////////////////////////////////////////////////////////////////

using namespace CommonLibOgl;
using namespace PhongLightingApp;

//////////////////////////////////////////////////////////////////////////


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// Redirect output from std::wcout and std::wcerr to the log file.
	std::wofstream out("log.txt");
	std::wcout.rdbuf(out.rdbuf());
	std::wcerr.rdbuf(out.rdbuf());

	int res = 1;

	try
	{
		// Window client area dimensions.
		const int ClientWidth = 800;
		const int ClientHeight = 600;

		// Window title ID, class ID, icon ID and menu ID were copied from the Visual Studio-generated window code.
		WindowInfo wndInfo(ClientWidth, ClientHeight, IDS_APP_TITLE, IDC_PHONGLIGHTING,
			IDI_PHONGLIGHTING, IDI_SMALL, IDC_PHONGLIGHTING);

		// OpenGL version.
		const int OpenGLVersionMajor = 4;
		const int OpenGLVersionMinor = 4;

		// Field of view angle.
		const GLfloat FOV = 45.0f;

		// Frustum boundaries.
		const GLfloat FrustumNear = 0.1f;
		const GLfloat FrustumFar = 1000.0f;

		OpenGLInfo openGLInfo(OpenGLVersionMajor, OpenGLVersionMinor, FOV, FrustumNear, FrustumFar);

		glm::vec3 cameraPosition = { 0.0f, 0.0f, -5.0f };

		// Initial scale factor for the camera.
		const GLfloat CameraScale = 1.0f;

		// Create an OpenGL camera.
		std::shared_ptr<Camera> spCamera = std::make_shared<Camera>(cameraPosition, CameraScale, FOV, FrustumNear, FrustumFar);

		// Create main window (sets up an OpenGL context internally).

		WindowMain mainWindow(hInstance, nCmdShow, wndInfo, openGLInfo);

		// Create a GLSL program.

		const ShaderCollection shaders = {
			{ GL_VERTEX_SHADER, "shaders\\scene.vert" },
			{ GL_FRAGMENT_SHADER, "shaders\\scene.frag" } };

		ProgramGLSL program(shaders);

		// Create an OpenGL scene and pass it to the main window.

		glm::vec3 backgroundColor(0.8f, 0.93f, 0.96f);    // very light blue

		std::shared_ptr<IScene> spScene = std::make_shared<Scene>(backgroundColor, spCamera, program.getProgram());

		if (!program.validate())
		{
			std::wcerr << L"GLSL program validation failed\n";
			ATLASSERT(FALSE); return 1;
		}

		res = mainWindow.runMessageLoop(spScene);
	}
	catch (const Exception& ex)
	{
		std::wcerr << ex.message() << '\n';
		return 1;
	}
	catch (const std::bad_alloc&)
	{
		std::wcerr << L"Memalloc failure\n";
		return 1;
	}
	catch (...)
	{
		std::wcerr << L"Unknown exception\n";
		return 1;
	}

	return res;
}
