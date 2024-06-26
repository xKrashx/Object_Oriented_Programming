const unsigned int MAX_NAME = 128;

class Beer {
public:
	Beer(const char* nm, unsigned quant);
	Beer();
	~Beer();
	Beer(const Beer& other);
	Beer& operator =(const Beer& other);
	unsigned Getquantity()const;
	const char* Getmark()const;
	void Setquantity(unsigned newquant);
	void Free();
	void Copy(const Beer& other);
	void add(Beer& other,unsigned refill);
	void refill(Beer& other,const unsigned ref);
	bool check(const char *name);
private:
	 char* mark;
	unsigned quantity;

};
