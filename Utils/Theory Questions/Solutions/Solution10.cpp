/*
    You are working on a Space Simulator game. For some reason, ships in your game are sometimes failing to die (but sometimes they work). 
    Debugging has shown that the Ship::GetHit method is properly called with the proper damage. 

    Fix the problems in the class below.
*/

class Ship
{
    Ship() : m_IsAlive(true) {}

    void GetHit(unsigned damage)
    {
        // There are two ways to fix it.
        // First one is with an if statement of some sort.
        // The second is by just changing the type of m_Health to signed int.
        // 1. If the damage is >= than the health just make the health 0.
        m_Health = m_Health <= damage ? 0 : m_Health - damage;
        // m_Health -= damage;
        if (m_Health <= 0)
        {
            GetDestroyed();
        }
    }

    void GetDestroyed()
    {
        m_IsAlive = false;
        //Plays an animation for getting destroyed
    }	

private:
    bool m_IsAlive;
    unsigned m_Health;
    // 2. Change the type to signed integer.
    // int m_Health;
};

int main(int argc, char* argv[])
{
    // Game code goes here :)
	return 0;
}