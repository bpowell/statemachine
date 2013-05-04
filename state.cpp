#include <map>
#include <iostream>
#include <string>

using std::cout;
using std::string;

class IState
{
	public:
		IState(){};
		~IState(){};
		virtual void update(float dt)=0;
		virtual void render()=0;
		virtual void on_exit()=0;
		virtual void on_enter()=0;
};

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

class StateMachine
{
	private:
		std::map<string, IState*> states;	
		IState *current_state;

	public:
		void update(float dt);
		void render();
		void change(string name);
		void set(string name);
		void add(string name, IState *state);
};

void StateMachine::update(float dt)
{
	current_state->update(dt);
}

void StateMachine::render()
{
	current_state->render();
}

void StateMachine::change(string name)
{
	current_state->on_exit();
	current_state = states[name];
	current_state->on_enter();
}

void StateMachine::set(string name)
{
	current_state = states[name];
	current_state->on_enter();
}
void StateMachine::add(string name, IState *state)
{
	states.insert(std::pair<string, IState*>(name, state));
}

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
	MenuState *menu = new MenuState();
	WorldState *menu2 = new WorldState();
	StateMachine *state = new StateMachine();

	state->add("menu", menu);
	state->add("menu2", menu2);
	state->set("menu");
	state->change("menu2");
	state->render();

	return 0;
}
