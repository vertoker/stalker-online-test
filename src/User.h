#pragma once

#include <string>
#include <functional>
#include "stdint.h"

namespace vertoker
{
    class User
    {
    public:
        User( const std::wstring& str );
        User( std::wstring surname, std::wstring name, uint64_t phone );

        inline std::wstring GetSurname() const noexcept { return surname; }
        inline std::wstring GetName()    const noexcept { return name;    }
        inline uint64_t     GetPhone()   const noexcept { return phone;   }

    private:
        std::wstring surname;
        std::wstring name;
        uint64_t     phone;
    };

    std::wstring GetSurnameNamePhone( const User& user );
    std::wstring GetNameSurnamePhone( const User& user );
    std::wstring GetPhoneSurnameName( const User& user );

    typedef std::function< decltype(GetSurnameNamePhone) > UserStringPred_t;

    // Predicates for sorting

    struct {
        bool operator()( User& a, User& b ) const
            { return a.GetName() < b.GetName(); }
    } nameLessPred;

    struct {
        bool operator()( User& a, User& b ) const
            { return a.GetSurname() < b.GetSurname(); }
    } surnameLessPred;

    struct {
        bool operator()( User& a, User& b ) const
            { return a.GetPhone() < b.GetPhone(); }
    } phoneLessPred;

} // namespace vertoker
