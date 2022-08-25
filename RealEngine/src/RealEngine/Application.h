#pragma once
#include "Core.h"

namespace RealEngine
{
	class RE_API Application
	{
	public:
		Application() {};
		virtual ~Application() {};
		void Run();

	};

	// Tobe defined in a client
	Application* CreateApplication();

}

