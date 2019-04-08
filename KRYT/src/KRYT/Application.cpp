#include "Application.h"

#include "KRYT/Events/ApplicationEvent.h"
#include "KRYT/Log.h"

namespace KRYT {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		KR_TRACE(e);
		while (true);
	}
}
