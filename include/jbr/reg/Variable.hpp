//!
//! @file Variable.hpp
//! @author jbruel
//! @date 07/06/19
//!

#ifndef JBR_CREGISTER_REGISTER_VARIABLE_HPP
# define JBR_CREGISTER_REGISTER_VARIABLE_HPP

# include <jbr/Register.hpp>
# include <jbr/reg/var/perm/Rights.hpp>
# include <string>

//!
//! @namespace jbr::reg
//!
namespace jbr::reg
{

    //!
    //! @class Variable
    //! @brief Unique register variable.
    //!
    class Variable final : private jbr::Register
    {
    private:
        std::string mPath; //!< Register path handle for this variable.

    public:
        //!
        //! @brief Register variable constructor.
        //! @warning Not usable.
        //!
        Variable() = delete;
        //!
        //! @brief Register variable constructor with register owner path.
        //! @param registerPath Owner register path.
        //!
        explicit Variable(const std::string &registerPath);
        //!
        //! @brief Copy constructor
        //! @warning Not usable.
        //!
        Variable(const Variable &) = delete;
        //!
        //! @brief Equal overload operator.
        //! @warning Not usable.
        //!
        Variable    &operator=(const Variable &) = delete;
        //!
        //! @brief Register variable class destructor.
        //!
        ~Variable() = default;

    public:
        //!
        //! @brief Set (create or update) a variable from the current target register.
        //! @param key Target key to create or update.
        //! @param value Value link to the key.
        //! @param rights Variable rights.
        //!
        void        set(const std::string &key, const std::string &value,
                        const std::optional<jbr::reg::var::perm::Rights> &rights = std::nullopt) noexcept(false);
        //!
        //! @brief Extract a variable from the target register.
        //! @param key Key to extract.
        //! @return Value link to the key extracted.
        //!
        [[nodiscard]]
        std::string get(const std::string &key) noexcept(false);
        //!
        //! @brief Remove a key from the target register.
        //! @param key Key to extract.
        //!
        void        remove(const std::string &key) noexcept(false);
        //!
        //! @brief Check if a key exist on the target register.
        //! @param key Key to check.
        //! @return Key status, true if exist.
        //!
        bool        available(const std::string &key) noexcept(false);

    private:
        //!
        //! @static
        //! @brief Write rights information's on variable.
        //! @param reg XML document object.
        //! @param nodeVariable Variable node from register.
        //! @param valueElement Value element node from variable.
        //! @param rights Register rights.
        //! @warning This function must be call into a process, no check on pointers, object validity are done. File must be saved after call.
        //!
        static void                 writeVariableRights(tinyxml2::XMLDocument *reg,
                                                        tinyxml2::XMLNode *nodeVariable,
                                                        tinyxml2::XMLElement *valueElement,
                                                        const jbr::reg::var::perm::Rights &rights) noexcept(false);
    };
}

#endif //JBR_CREGISTER_REGISTER_VARIABLE_HPP
