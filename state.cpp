#include <map>
#include <iostream>
#include <string>

#include "statemachine.h"

using std::cout;
using std::string;

class WorldState: public IState
{
	public:
		WorldState(){};
		~WorldState(){};
		virtual void update(float dt);
		virtual void render();
		virtual void on_exit();
		virtual void on_enter();
};
class MenuState : public IState
{
	public:
		MenuState(){};
		~MenuState(){};
		virtual void update(float dt);
		virtual void render();
		virtual void on_exit();
		virtual void on_enter();
};

void WorldState::update(float dt)
{
	cout << dt;
}

void WorldState::render()
{
	cout << "WorldState\n";
}

void WorldState::on_enter()
{
	cout << "World enter\n";
}

void WorldState::on_exit()
{
	cout << "World exit\n";
}
void MenuState::update(float dt)
{
	cout << dt;
}

void MenuState::render()
{
	cout << "MenuState\n";
}

void MenuState::on_enter()
{
	cout << "Menu enter\n";
}

void MenuState::on_exit()
{
	cout << "Menu exit\n";
}

int main(int argc, char *argv[])
{
	IStatePtr menu(new MenuState());
	IStatePtr menu2(new WorldState());
	StateMachine *state = new StateMachine();

	state->add("menu", menu);
	state->add("menu2", menu2);
	state->set("menu");
	state->change("menu2");
	state->render();

	return 0;
}
