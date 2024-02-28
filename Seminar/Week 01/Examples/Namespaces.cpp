#include <iostream>
#include <vector>


namespace mine{

    template<typename T>
    class vector{};

}

using namespace std;
using namespace mine;

namespace A
{
    int i;
}
 
namespace B
{
    int i;
    int j;
 
    namespace C
    {
        namespace D
        {
            using namespace A; // all names from A injected into global namespace
 
            int j;
            int k;
            int a = i;         // i is B::i, because A::i is hidden by B::i
        }
 
        using namespace D; // names from D are injected into C
                           // names from A are injected into global namespace
 
        int k = 89; // OK to declare name identical to one introduced by a using
        int l = k;  // ambiguous: C::k or D::k
        int m = i;  // ok: B::i hides A::i
        int n = j;  // ok: D::j hides B::j
    }
}

namespace Q
{
    namespace V   	// V is a member of Q, and is fully defined within Q
    { 			 	// namespace Q::V // C++17 alternative to the lines above
        class C		// C is a member of V and is fully defined within V
		{ 
			 void m(); // C::m is only declared
		};
        void f(); // f is a member of V, but is only declared here
    }
 
    void V::C::m() // definition of V::C::m outside of the namespace (and the class body)
    {}             // enclosing namespaces are the global namespace, Q, and Q::V
}

int main(){

    vector<int> vec; // Ambiguous because we don't know which one we want to address.

}