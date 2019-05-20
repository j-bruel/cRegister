//!
//! @file register_create.cpp
//! @author jbruel
//! @date 20/05/19
//!

#include <jbr/Register.hpp>
#include <doctest.h>
#include <iostream>
#include <string>

TEST_CASE("Register::create")
{
    jbr::Register   mRegister;

    SUBCASE("empty input path")
    {
        CHECK_THROWS(mRegister.create(""));
    }

    SUBCASE("Tmp print")
    {
        mRegister.create("testing path ...");
    }

}
