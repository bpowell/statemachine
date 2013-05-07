#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include <map>
#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>

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

typedef boost::shared_ptr<IState> IStatePtr;

class StateMachine
{
	private:
		std::map<string, IStatePtr> states;	
		IStatePtr current_state;

	public:
		void update(float dt);
		void render();
		void change(string name);
		void set(string name);
		void add(string name, IStatePtr state);
};
#endif
