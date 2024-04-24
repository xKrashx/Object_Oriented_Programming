#include "Athlete.hpp"
#if !TEST_IN_MAIN
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#else
#define DOCTEST_CONFIG_DISABLE
#endif
#include "../../Doctest/doctest.h"
#include <cstring>

TEST_SUITE("Testing the getters"){

    Athlete a("Hristo", 3, 3, 3, false, "Tigri", Sport::Tennis);

    TEST_CASE("Name getter"){

        CHECK_EQ(strcmp(a.getName(), "Hristo"), 0);

    }

    TEST_CASE("Stamina getter"){

        CHECK_EQ(a.getStamina(), 3);

    }

    TEST_CASE("Power getter"){

        CHECK_GE(a.getPower(), 3);

    }

}

TEST_SUITE("Testing the constructor"){

    TEST_CASE("Name"){

        Athlete a("Hristo", 3, 3, 3, false, "Tigri", Sport::Tennis);
        CHECK_EQ(strcmp(a.getName(), "Hristo"), 0);

    }

}