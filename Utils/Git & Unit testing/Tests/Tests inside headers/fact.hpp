#pragma once

int fact(int n){
    return n <= 1 ? n : fact(n - 1) * n;
}

#ifdef FACT_WITH_TESTS
#ifndef DOCTEST_LIBRARY_INCLUDED
#define DOCTEST_CONFIG_IMPLEMENT
#include "../../utils/doctest.h"
#endif

TEST_CASE("[fact] testing fact"){

    CHECK_EQ(fact(0), 1); // should fail
    CHECK_EQ(fact(1), 1);
    CHECK_EQ(fact(10), 3628800);

}

#endif