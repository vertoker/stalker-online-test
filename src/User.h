#pragma once

#include <string>
#include "stdint.h"

namespace vertoker
{
    class User
    {
    public:
        User(const std::wstring& str);
        User(std::wstring surname, std::wstring name, uint64_t phone);

        inline std::wstring GetName()    const noexcept { return name; }
        inline std::wstring GetSurname() const noexcept { return surname; }
        inline uint64_t GetPhone()       const noexcept { return phone; }

    private:
    std::wstring surname;
        std::wstring name;
        uint64_t phone;
    };

    // Predicates for std::sort

    struct
    {
        bool operator()(User& a, User& b) const
            { return a.GetSurname() < b.GetName(); }
    } surnameLessPred;

    struct
    {
        bool operator()(User& a, User& b) const
            { return a.GetName() < b.GetName(); }
    } nameLessPred;

    struct
    {
        bool operator()(User& a, User& b) const
            { return a.GetPhone() < b.GetPhone(); }
    } phoneLessPred;

} // namespace vertoker
