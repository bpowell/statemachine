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

