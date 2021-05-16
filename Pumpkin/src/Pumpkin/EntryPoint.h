#pragma once

#ifdef PK_PLATFORM_WINDOWS

extern Pumpkin::Application* Pumpkin::CreateApplication();

int main(int argc, char** argv) {
	
	auto app = Pumpkin::CreateApplication();
	app->Run();
	delete app;
	  
}

#endif