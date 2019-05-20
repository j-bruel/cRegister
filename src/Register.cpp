//!
//! @file Register.cpp
//! @author jbruel
//! @date 20/05/19
//!

#include "jbr/Register.hpp"
#include "jbr/reg/exception.hpp"
#include <iostream>
#include <fstream>

namespace jbr
{
    void    Register::create(const std::string &path) const
    {
        if (path.empty())
            throw jbr::reg::exception("To create a register the path must not be empty.");

        const std::string   absolutePath = jbr::reg::getAbsolutePath(path);

        if (exist(absolutePath))
            throw jbr::reg::exception("The register " + path + " already exist. You must remove it before create it or open it.");
        std::ofstream(absolutePath.c_str());
    }

    void    Register::open(const std::string &path) const
    {
        if (path.empty())
            throw jbr::reg::exception("To open a register the path must not be empty.");

        const std::string   absolutePath = jbr::reg::getAbsolutePath(path);

        if (!exist(absolutePath))
            throw jbr::reg::exception("The register " + path + " does not exist. You must create it before.");
    }

    void    Register::destroy(const std::string &path) const
    {
        if (path.empty())
            throw jbr::reg::exception("To destroy a register the path must not be empty.");

        const std::string   absolutePath = jbr::reg::getAbsolutePath(path);

        if (!exist(absolutePath))
            throw jbr::reg::exception("Impossible to destroy a not existing register : " + path + ".");

        std::error_code     ec;

        if (!std::filesystem::remove(path, ec))
            throw jbr::reg::exception("Impossible to destroy this next register : " + path + ". Error code : " + std::to_string(ec.value()) + ", why : " + ec.message());
    }

}