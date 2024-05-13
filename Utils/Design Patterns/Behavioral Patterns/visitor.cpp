#include <iostream>
#include <vector>

class Element;

class Visitor{
public:
	virtual void VisitA(Element const &) = 0;
	virtual void VisitB(Element const &) = 0;
	virtual ~Visitor() = default;
};

class ConcreteVisitor : public Visitor{
public:
	void VisitA(Element const &) override{ std::cout << "Visit A\n"; }
	void VisitB(Element const &) override{ std::cout << "Visit B\n"; }
};

class Element{
public:
	virtual void Accept(Visitor *visitor) = 0;
	virtual ~Element() = default;
};

class ElementA : public Element{
public:
	void Accept(Visitor *visitor) override{
		visitor -> VisitA(*this);
  	}
};

class ElementB : public Element{
public:
	void Accept(Visitor *visitor) override{
		visitor -> VisitB(*this);
	}
};

class ObjectStructure{
public:
	void Append(Element *element){
		m_Elements.emplace_back(element);
	}

	void Remove(Element *element){
		for(std::vector<Element *>::iterator iter = m_Elements.begin(); iter != m_Elements.end(); ++iter)
			if(*iter == element)
				m_Elements.erase(iter);
	}

	void Accept(Visitor *visitor){
		for (Element * const &element : m_Elements) {
			element -> Accept(visitor);
		}
	}

private:
  	std::vector<Element *> m_Elements;
};

int main(){
	ElementA a;
	ElementB b;

	ObjectStructure o;
	o.Append(&a);
	o.Append(&b);

	Visitor *visitor = new ConcreteVisitor;
	o.Accept(visitor);  // visit A\nvisit B\n

	delete visitor;

	return 0;
}
