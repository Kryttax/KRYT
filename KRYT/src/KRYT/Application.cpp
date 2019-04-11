#include "KRpch.h"
#include "Application.h"

#include "KRYT/Events/ApplicationEvent.h"
#include "KRYT/Log.h"
#include <GLFW/glfw3.h>

namespace KRYT {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()
	{
	}

	void Application::Run() {

		/*WindowResizeEvent e(1280, 720);
		KR_TRACE(e);*/
		while (m_Running) 
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
