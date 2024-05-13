#include "Player.hpp"

#include <cstring>
#include <stdexcept>

const unsigned short Player::MAX_NAME_LEN = 50;

Player::Player(const char* name) : name(nullptr), points(0), position(0, 0)
{ 
	this->SetName(name);
}

Player::Player(const Player& other) : name(nullptr)
{
	this->Copy(other);
}

Player::~Player() 
{
	this->Deallocate();
}

Player& Player::operator=(const Player& other)
{
	if(this != &other) 
	{
		this->Deallocate();
		this->Copy(other);
	}
	return *this;
}

unsigned int Player::GetPoints() const 
{
	return this->points;
}

const Point& Player::GetPosition() const 
{
	return this->position;
}

const char* Player::GetName() const 
{
	return this->name;
}

void Player::SetPoints(unsigned int points) 
{
	this->points = points; 
}

void Player::SetPosition(const Point& position)
{
	this->position = position;
}

void Player::SetName(const char* name) 
{
	const unsigned short nameLen = strlen(name);

	if(!name || nameLen >= MAX_NAME_LEN)
	{
		throw std::invalid_argument("Invalid name!");
	}

	delete[] this->name;
	this->name = new char[nameLen + 1];
	strcpy(this->name, name);
}

void Player::Print(std::ostream& os) const 
{
    if(os.fail() || os.bad()) return;
	
    os << "name: " << (this->name ? this->name : "") << ", " << "position: ";  
	this->position.Print();
	os << ", points: " << this->points << std::endl;
}

void Player::Copy(const Player& other) 
{
	this->SetName(other.name);
	this->points = other.points;
	this->position = other.position;
} 

void Player::Deallocate()
{
	delete[] this->name;
	this->name = nullptr;
}
