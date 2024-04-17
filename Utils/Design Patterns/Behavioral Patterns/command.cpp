#include <iostream>
#include <vector>
#include <string>

class ElectronicDevice {
public:
	ElectronicDevice(std::string const &name): m_Name(name){}

  	void TurnOn(){ std::cout << m_Name << " is now ON.\n"; }
  	void TurnOff(){ std::cout << m_Name << " is now OFF.\n"; }

private:
	std::string m_Name;
};

class Command {
public:
	virtual void Execute() = 0;
	virtual ~Command() = default;
};

class TurnOnCommand : public Command {
public:
	TurnOnCommand(ElectronicDevice &device): m_Device(device){}

	void Execute() override { m_Device.TurnOn(); }
private:
	ElectronicDevice &m_Device;
};

class TurnOffCommand : public Command {
public:
	TurnOffCommand(ElectronicDevice &device): m_Device(device){}

	void Execute() override { m_Device.TurnOff(); }
private:
	ElectronicDevice &m_Device;
};

class RemoteControl {
public:
	void Append(Command *c) { m_Commands.push_back(c); }

	void Remove(Command *c) {
		for(std::vector<Command *>::iterator iter = m_Commands.begin(); iter != m_Commands.end(); ++iter)
			if(*iter == c)
				m_Commands.erase(iter--);
	}

	void PressButton(size_t number) {
		if(number >= m_Commands.size()) return;
		m_Commands[number] -> Execute();
	}

private:
  	std::vector<Command *> m_Commands;
};

int main() {
	ElectronicDevice tv("TV");
	ElectronicDevice lights("Lights");

    // Create commands for turning devices on and off
    TurnOnCommand turnOnTV(tv);
    TurnOffCommand turnOffTV(tv);
    TurnOnCommand turnOnLights(lights);
    TurnOffCommand turnOffLights(lights);
 
    // Create a remote control
    RemoteControl remote;
 
    // Set commands for remote buttons
    remote.Append(&turnOnTV); // Button 0: Turn on TV
    remote.Append(&turnOffTV); // Button 1: Turn off TV
    remote.Append(&turnOnLights); // Button 2: Turn on Lights
    remote.Append(&turnOffLights); // Button 3: Turn off Lights
 
    // Press buttons on the remote
    remote.PressButton(0); // Turn on TV
    remote.PressButton(3); // Turn off Lights
    remote.PressButton(1); // Turn off TV
    remote.PressButton(2); // Turn on Lights

	return 0;
}
