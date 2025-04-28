#ifndef __PERSON_HPP
#define __PERSON_HPP

class Person{

public:
	Person() = default;
	Person(char const *name, int age);
	Person(Person const &other);
	Person(Person &&other);
	~Person();

	Person& operator=(Person const &other);
	Person& operator=(Person &&other);

	const char* GetName() const;
	int GetAge() const;

	void Print() const;

protected:
	void SetName(const char* name);
	void SetAge(unsigned age);

private:
	char *m_Name = nullptr;
	unsigned m_Age = 0;

	void Copy(Person const &other);
	void Move(Person &&other);
	void Free();

};

#endif