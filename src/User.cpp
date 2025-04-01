#include "User.h"

#include <regex>
#include <iostream>

vertoker::User::User(const std::wstring& str)
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

vertoker::User::User(std::wstring surname, std::wstring name, uint64_t phone)
    : surname{std::move(surname)}, name{std::move(name)}, phone{phone} {}

std::wstring vertoker::Print_SurnameNamePhone(const User& user)
{
    std::wstringstream ss;
    ss << user.GetSurname() << " " << user.GetName() << ": " << user.GetPhone();
    return ss.str();
}
std::wstring vertoker::Print_NameSurnamePhone(const User& user)
{
    std::wstringstream ss;
    ss << user.GetName() << " " << user.GetSurname() << ": " << user.GetPhone();
    return ss.str();
}
std::wstring vertoker::Print_PhoneSurnameName(const User& user)
{
    std::wstringstream ss;
    ss << user.GetPhone() << ": " << user.GetSurname() << " " << user.GetName();
    return ss.str();
}
