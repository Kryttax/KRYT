#include <KRYT.h>

class Sandbox : public KRYT::Application{

public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

KRYT::Application* KRYT::CreateApplication() {
	return new Sandbox();
 }