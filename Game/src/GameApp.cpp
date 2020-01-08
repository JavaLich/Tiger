
#include <Tiger.h>

#include <iostream>

class GameApp : public Tiger::Application {
public:
	GameApp() {

 	}
	~GameApp() {

	}
};

Tiger::Application* Tiger::createApplication() {
	return new GameApp();
}