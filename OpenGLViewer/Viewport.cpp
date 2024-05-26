#include "Viewport.h"
#include "SVertex.h"

void HandleFramebufferSize(GLFWwindow* _window, int _width, int _height)
{
	glViewport(0, 0, _width, _height);
}


int SViewport::Initialize(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, M_I_GLFW_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, M_I_GLFW_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_pWindow = glfwCreateWindow(M_I_WIDTH, M_I_HEIGHT, M_S_TITLE, NULL, NULL);
	glfwSetFramebufferSizeCallback(m_pWindow, HandleFramebufferSize);

	if (!m_pWindow)
	{
		std::cout << "ERROR: GLFW Window Creation failed!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(m_pWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR: GLAD Initialisation failed" << std::endl;
		return -2;
	}

	return 0;
}

int SViewport::Update(void)
{
    if (SInput::GetKey(GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(m_pWindow, GLFW_TRUE);
    }
	return 0;
}

int SViewport::Draw(void)
{
	glClearColor(M_F_RED, M_F_GREEN, M_F_BLUE, M_F_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	return 0;
}

int SViewport::LateDraw(void)
{
	glfwSwapBuffers(m_pWindow);
	return 0;
}

void SViewport::Finalize(void)
{
	glfwTerminate();
}
