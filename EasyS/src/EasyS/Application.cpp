#include "ezpch.h"
#include "Application.h"
#include "EasyS/Log.h"
#include "EasyS/Events/ApplicationEvent.h"

namespace Easy
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			EZ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			EZ_TRACE(e);
		}
		while (true);
	}
}