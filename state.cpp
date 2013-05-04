#include <map>
#include <iostream>
#include <string>

using std::cout;
using std::string;

class IState
{
	public:
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

void StateMachine::add(string name, IState *state)
{
	states.insert(std::pair<string, IState*>(name, state));
}

