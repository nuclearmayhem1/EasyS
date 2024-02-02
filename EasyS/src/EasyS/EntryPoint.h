#pragma once

#ifdef EZ_PLATFORM_WINDOWS

extern Easy::Application* Easy::CreateApplication();

int main(int argc, char** argv)
{
	Easy::Log::Init();

	auto app = Easy::CreateApplication();
	app->Run();
	delete app;
}

#endif
