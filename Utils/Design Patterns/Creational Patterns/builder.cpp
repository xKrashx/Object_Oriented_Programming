#include <string>

class DeviceSuite {
public:
	void SetMouse(std::string) {}
	void SetKeyboard(std::string) {}
	void SetHeadphone(std::string) {}
};

class GameDevice {
public:
	virtual void BuildMouse() = 0;
	virtual void BuildKeyboard() = 0;
	virtual void BuildHeadphone() = 0;
	virtual DeviceSuite& Device() const = 0;
	virtual ~GameDevice() = default;
};

class LOLGameDevice : public GameDevice {
public:
	LOLGameDevice() : m_Device(new DeviceSuite) {}
	~LOLGameDevice(){ delete m_Device; }

	void BuildMouse() override { m_Device->SetMouse("Logitech"); }

	void BuildKeyboard() override { m_Device->SetKeyboard("Filco"); }

	void BuildHeadphone() override { m_Device->SetHeadphone("Sennheiser"); }

	DeviceSuite& Device() const override { return *m_Device; }

private:
  	DeviceSuite *m_Device;
};

class DNFGameDevice : public GameDevice {
public:
	DNFGameDevice() : m_Device(new DeviceSuite) {}
	~DNFGameDevice(){ delete m_Device; }

	void BuildMouse() override { m_Device->SetMouse("Razer"); }

	void BuildKeyboard() override { m_Device->SetKeyboard("Cherry"); }

	void BuildHeadphone() override { m_Device->SetHeadphone("Beyerdynamic"); }

	DeviceSuite& Device() const override { return *m_Device; }

private:
  	DeviceSuite *m_Device;
};

class Life {
public:
	DeviceSuite& CreateDevice(GameDevice& builder) {
		builder.BuildMouse();
		builder.BuildKeyboard();
		builder.BuildHeadphone();
		return builder.Device();
	}
};

int main() {
	Life life;
	LOLGameDevice LOLBuilder;
	DNFGameDevice DNFBuilder;

	DeviceSuite LOLDevice = life.CreateDevice(LOLBuilder);
	DeviceSuite DNFDevice = life.CreateDevice(DNFBuilder);

	return 0;
}
