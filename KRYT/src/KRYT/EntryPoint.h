#pragma once

#ifdef KR_PLATFORM_WINDOWS

extern KRYT::Application* KRYT::CreateApplication();
int main(int argc, char** argv)
{
	KRYT::Log::Init();
	KR_CORE_WARN("Initializer Log");
	KR_INFO("Hello!");
	auto app = KRYT::CreateApplication();
	app->Run();
	delete app;
}
#endif // KR_PLATFORM_WINDOWS

