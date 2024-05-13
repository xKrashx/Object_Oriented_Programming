#include <iostream>

class Connection;

class State{
public:
	virtual void Open(const Connection&) const = 0;
	virtual void Close(const Connection&) const = 0;
	virtual ~State() = default;
};

class Connection{
public:
	Connection(State *state): m_State(std::move(state)){}
	~Connection(){ delete m_State; }

	void ChangeState(State *state){ delete m_State; m_State = std::move(state); }

	void Open() const{ m_State->Open(*this); }

	void Close() const{ m_State->Close(*this); }

private:
	State *m_State;
};

class StateA : public State{
public:
	void Open(Connection const &) const override{
		std::cout << "open in stateA\n";
	}

	void Close(Connection const &) const override{
		std::cout << "close in stateA\n";
	}
};

class StateB : public State{
public:
	void Open(Connection const &) const override{
		std::cout << "open in stateB\n";
	}

	void Close(Connection const &) const override{
		std::cout << "close in stateB\n";
	}
};

int main() {
	Connection connection{new StateA};

	connection.Open();   // open in stateA
	connection.Close();  // close in stateA

	connection.ChangeState(new StateB);
	connection.Open();   // open in stateB
	connection.Close();  // close in stateB

	return 0;
}
