#pragma once

#ifdef KR_PLATFORM_WINDOWS

extern KRYT::Application* KRYT::CreateApplication();
int main(int argc, char** argv)
{
	auto app = KRYT::CreateApplication();
	app->Run();
	delete app;
}
#endif // KR_PLATFORM_WINDOWS

