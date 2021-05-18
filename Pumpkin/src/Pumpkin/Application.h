#pragma once
#include"Core.h"

namespace Pumpkin {

	class PUMPKIN_API Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIE NT
	Application* CreateApplication();

}
