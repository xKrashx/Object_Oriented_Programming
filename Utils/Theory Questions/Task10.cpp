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
        m_Health -= damage;
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
};

int main(int argc, char* argv[])
{
    // Game code goes here :)
	return 0;
}