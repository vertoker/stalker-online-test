#include "User.h"

#include <regex>
#include <iostream>

// constructors

vertoker::User::User( const std::wstring& str )
{
    const std::wregex rx(L"[а-яА-Я0-9]+");

    std::wsregex_token_iterator tokenIter(str.begin(), str.end(), rx);

    if (!tokenIter->matched) return;
    surname = std::move(tokenIter->str());
    
    ++tokenIter;
    if (!tokenIter->matched) return;
    name = std::move(tokenIter->str());
    
    ++tokenIter;
    if (!tokenIter->matched) return;
    phone = std::stoull(tokenIter->str());
}
vertoker::User::User( std::wstring surname, std::wstring name, uint64_t phone )
    : surname{ std::move(surname) }, name{ std::move(name) }, phone{ phone } {}

// functions

std::wstring vertoker::GetSurnameNamePhone( const User& user )
{
    std::wstringstream ss;
    ss << user.GetSurname() << " " << user.GetName() << ": " << user.GetPhone();
    return ss.str();
}
std::wstring vertoker::GetNameSurnamePhone( const User& user )
{
    std::wstringstream ss;
    ss << user.GetName() << " " << user.GetSurname() << ": " << user.GetPhone();
    return ss.str();
}
std::wstring vertoker::GetPhoneSurnameName( const User& user )
{
    std::wstringstream ss;
    ss << user.GetPhone() << ": " << user.GetSurname() << " " << user.GetName();
    return ss.str();
}
