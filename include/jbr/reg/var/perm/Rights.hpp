//!
//! @file jbr/reg/var/perm/Rights.hpp
//! @author jbruel
//! @date 30/07/19
//!

#ifndef JBR_CREGISTER_REGISTER_VAR_PERM_RIGHTS_HPP
# define JBR_CREGISTER_REGISTER_VAR_PERM_RIGHTS_HPP

# include <jbr/reg/Permission.hpp>

//!
//! @namespace jbr::reg::var::perm
//!
namespace jbr::reg::var::perm
{

    //!
    //! @struct Rights
    //! @brief All variables rights.
    //!
    struct Rights final : public jbr::reg::Permission
    {
        bool    mUpdate; //!< Allow to update a variable.
        bool    mRename; //!< Allow to rename a variable.
        bool    mCopy; //!< Allow to copy a variable.
        bool    mRemove; //!< Allow to remove a variable.

        //!
        //! @brief Structure initializer. All rights are true by default.
        //!
        Rights() : jbr::reg::Permission(), mUpdate(true), mRename(true), mCopy(true), mRemove(true) {}
        //!
        //! @brief Structure initializer with custom rights initialization.
        //! @param rd Reading rights.
        //! @param wr Writing rights.
        //! @param up Allow to update a variable.
        //! @param rn Allow to rename a variable.
        //! @param cp Allow to copy a variable.
        //! @param rm Allow to remove a variable.
        //!
        explicit Rights(bool rd, bool wr, bool up, bool rn, bool cp, bool rm) : jbr::reg::Permission(rd, wr), mUpdate(up),
                                                                                mRename(rn), mCopy(cp), mRemove(rm) {}
        //!
        //! @brief Equal operator overload.
        //! @param rights New rights to overload.
        //! @return New rights structure.
        //!
        Rights  &operator=(const jbr::reg::var::perm::Rights &rights) noexcept
        {
            mRead = rights.mRead;
            mWrite = rights.mWrite;
            mUpdate = rights.mUpdate;
            mRename = rights.mRename;
            mCopy = rights.mCopy;
            mRemove = rights.mRemove;
            return (*this);
        }

        //!
        //! @brief Equality overload operator.
        //! @param rights Rights to check.
        //! @return Status if rights are equals.
        //!
        inline bool operator==(const jbr::reg::var::perm::Rights &rights) noexcept { return (mRead == rights.mRead &&
                                                                                            mWrite == rights.mWrite &&
                                                                                            mUpdate == rights.mUpdate &&
                                                                                            mRename == rights.mRename &&
                                                                                            mCopy == rights.mCopy &&
                                                                                            mRemove == rights.mRemove); }
    };

}

#endif //JBR_CREGISTER_REGISTER_VAR_PERM_RIGHTS_HPP
