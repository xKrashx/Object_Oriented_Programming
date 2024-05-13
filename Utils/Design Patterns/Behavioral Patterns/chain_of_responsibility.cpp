#include <iostream>

class Handler {
public:
	virtual void Process(int i) {
		if (m_Handler) {
			m_Handler->Process(i);
		} else {
			std::cout << i << "can't be processed\n";
		}
	}

	void SetNext(Handler *handler) { m_Handler = std::move(handler); }

	virtual ~Handler(){ delete m_Handler; }

private:
  	Handler *m_Handler;
};

class A : public Handler {
public:
	void Process(int i) override {
		if (i < 10) {
			std::cout << i << " processed by A\n";
		} else {
			Handler::Process(i);
		}
	}
};

class B : public Handler {
public:
	void Process(int i) override {
		if (i < 100) {
			std::cout << i << " processed by B\n";
		} else {
			Handler::Process(i);
		}
	}
};

class C : public Handler {
public:
	void Process(int i) override {
		if (i < 1000) {
			std::cout << i << " processed by C\n";
		} else {
			Handler::Process(i);
		}
	}
};

int main() {
	A a;
	B b;
	C c;

	a.SetNext(&b);
	b.SetNext(&c);

	a.Process(9);     // 9 processed by A
	a.Process(999);   // 999 processed by C
	a.Process(99);    // 99 processed by B
	a.Process(9999);  // 9999 can't be processed

	return 0;
}
