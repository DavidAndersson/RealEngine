#pragma once

#ifdef RE_PLATFORM_WINDOWS


extern RealEngine::Application* RealEngine::CreateApplication();

	int main(int argc, char** argv) {

		RealEngine::Log::Init();
		RE_CORE_WARN("Initialized Log");
		
		RE_INFO("Hello! Var = {0}", 5);

		auto app = RealEngine::CreateApplication();
		app->Run();
		delete app;

	}

#endif