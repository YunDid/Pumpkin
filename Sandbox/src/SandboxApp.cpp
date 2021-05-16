#include "Pumpkin.h"

class Sandbox : public Pumpkin::Application {

public:
	Sandbox() {
	
	}
	~Sandbox() {
	
	}
};

Pumpkin::Application* Pumpkin::CreateApplication() {
	
	return new Sandbox();
}