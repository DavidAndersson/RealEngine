#include <RealEngine.h>


class Sandbox : public RealEngine::Application 
{
public:
	Sandbox() {};
	~Sandbox() {};

private:
	

};


RealEngine::Application* RealEngine::CreateApplication() {

	return new Sandbox();

}