#include <Tiger.h>
#include <Tiger/EntryPoint.h>

#include "GameLayer.h"

class GameApp : public Tiger::Application {
public:
	GameApp() {
		stack.push(new GameLayer());
 	}
	~GameApp() {

	}
};

Tiger::Application* Tiger::createApplication() {
	return new GameApp();
}