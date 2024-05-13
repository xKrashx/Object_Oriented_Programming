#include <iostream>

class Graphic{
public:
	virtual void Display() = 0;
	virtual ~Graphic() = default;
};

class Image : public Graphic{
public:
  	void Display() override{ std::cout << 1; }
};

class Proxy : public Graphic{
public:
  	void Display() override{
		try{ ImageProxy().Display(); }
		catch(std::bad_alloc const &ex){ std::cerr << ex.what() << '\n'; }
	}

	~Proxy() override{
		delete m_Ptr;
	}

protected:
	Image &ImageProxy(){
		if(!m_Ptr) m_Ptr = new Image;
		return *m_Ptr;
	}

private:
  	Image *m_Ptr;
};

int main() {
	Graphic *proxy = new Proxy;
	proxy -> Display();  // 1
	delete proxy;
	return 0;
}
