#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "../Task1/Point.hpp"

class Player 
{
	public:
    	Player(const char* name);
    	Player(const Player& other);

    	~Player();

    	Player& operator=(const Player& other);

    	unsigned int GetPoints() const;
    	const Point& GetPosition() const;
		const char* GetName() const;

    	void SetPoints(unsigned int points);
    	void SetPosition(const Point& p);
    	void SetName(const char* name);

		void Print(std::ostream& os = std::cout) const;

	private:
		static const unsigned short MAX_NAME_LEN;

    	unsigned int points;
    	Point position;
    	char* name;
	
    	void Copy(const Player& other);
		void Deallocate();
};

#endif