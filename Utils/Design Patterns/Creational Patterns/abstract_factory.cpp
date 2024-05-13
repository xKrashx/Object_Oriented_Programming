#include <new>

class Door {
public:
	virtual ~Door() = default;
};

class Window {
public:
  	virtual ~Window() = default;
};

class House {
public:
  	virtual void SetDoor(Door *door) {
		this -> door = door;
	}
  	virtual void SetWindow(Window *window) {
		this -> window = window;
	}
  	virtual ~House(){
		delete door;
		delete window;
	}
private:
	Door *door;
	Window *window;
};

class HouseFactory {
public:
	virtual Door *MakeDoor() {
		return new(std::nothrow) Door;
	}

	virtual Window *MakeWindow() {
		return new(std::nothrow) Window;
	}

	virtual House *MakeHouse() {
		return new(std::nothrow) House;
	}

	virtual ~HouseFactory() = default;
};

class Life {
public:
	House *CreateHouse(HouseFactory& factory) {
		Door *door = factory.MakeDoor();
		Window *window = factory.MakeWindow();
		House *house = factory.MakeHouse();

		if(!door || !window || !house){

			delete door;
			delete window;
			delete house;

			return nullptr;

		}

		house -> SetDoor(door);
		house -> SetWindow(window);

		return house;
	}
};

class WoodDoor : public Door {};
class WoodWindow : public Window {};
class WoodHouse : public House {};

class WoodHouseFactory : public HouseFactory {
public:
	Door *MakeDoor() override {
		return new(std::nothrow) WoodDoor;
	}

	Window *MakeWindow() override {
		return new(std::nothrow) WoodWindow;
	}

	House *MakeHouse() override {
		return new(std::nothrow) WoodHouse;
	}
};

int main() {
	Life life;
	WoodHouseFactory factory;

	House *house = life.CreateHouse(factory);
	delete house;

	return 0;
}
