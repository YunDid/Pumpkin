#pragma once

#ifdef PK_PLATFORM_WINDOWS

extern Pumpkin::Application* Pumpkin::CreateApplication();

int main(int argc, char** argv) {
	
	Pumpkin::Log::Init();
	PK_CORE_WARN("Initialized Log!");
	int a = 5;
	PK_CLIENT_INFO("Hello! Var={0}",a);
	auto app = Pumpkin::CreateApplication();
	app->Run();
	delete app;
	  
}
 
#endif