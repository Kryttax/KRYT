#pragma once

#include "Core.h"
namespace KRYT {

	class KRYT_API Application
	{
	public:
		Application();
		virtual ~Application();
	
		void Run();
	
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}


