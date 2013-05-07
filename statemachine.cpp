#include "statemachine.h"

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
void StateMachine::add(string name, IStatePtr state)
{
	states.insert(std::pair<string, IStatePtr>(name, state));
}
