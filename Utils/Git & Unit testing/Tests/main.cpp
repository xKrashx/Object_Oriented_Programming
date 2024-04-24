#include "Athlete.hpp"
#if TEST_IN_MAIN
#define DOCTEST_CONFIG_IMPLEMENT
#else
#define DOCTEST_CONFIG_DISABLE
#endif
#include "../../Doctest/doctest.h"
#include <cstring>

TEST_SUITE("Testing the getters"){

    TEST_CASE("Testing with parametric constructor"){

        Athlete a("Hristo", 3, 3, 3, false, "Tigri", Sport::Tennis);

        SUBCASE("Name"){
            CHECK_EQ(strcmp(a.getName(), "Hristo"), 0);
        }

        SUBCASE("Stamina"){
            CHECK_EQ(a.getStamina(), 3);
        }

        SUBCASE("Power"){
            CHECK_GE(a.getPower(), 3);
        }


    }

}

#if TEST_IN_MAIN
int main(){
    
    doctest::Context().run();

}
#endif