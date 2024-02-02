#pragma once

#include "Core.h"

namespace Easy
{
	class EASY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}

