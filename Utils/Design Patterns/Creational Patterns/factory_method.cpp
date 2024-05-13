#include <new>

class Door{
public:
  	virtual ~Door() = default;
};

class Window{
public:
  	virtual ~Window() = default;
};

class House{
public:
  	virtual void SetDoor(Door const &){}
  	virtual void SetWindow(Window const &){}
  	virtual ~House() = default;
};

class Life{
public:
	virtual Door *MakeDoor(){ return new(std::nothrow) Door; }

	virtual Window *MakeWindow(){ return new(std::nothrow) Window; }

	virtual House *MakeHouse(){ return new(std::nothrow) House; }

	House *CreateHouse(){
		Door *door = MakeDoor();
		Window *window = MakeWindow();
		House *house = MakeHouse();

		if(!door || !window || !house){

			delete door;
			delete window;
			delete house;

			return nullptr;

		}

		house -> SetDoor(*door);
		house -> SetWindow(*window);

		return house;
	}

	virtual ~Life() = default;
};

class WoodHouse : public House{};
class WoodDoor : public Door{};
class WoodWindow : public Window{};

class MyLife : public Life{
public:
	House *MakeHouse() override{
		return new(std::nothrow) WoodHouse;
	}

	Door *MakeDoor() override{
		return new(std::nothrow) WoodDoor;
	}

	Window *MakeWindow() override{
		return new(std::nothrow) WoodWindow;
	}
};

int main(){
	MyLife life;
	House *house = life.CreateHouse();
	delete house;
	return 0;
}
