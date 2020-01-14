
#include <Tiger.h>

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