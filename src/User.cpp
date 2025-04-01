#include "User.h"

#include <regex>

vertoker::User::User(const std::wstring& str)
{
    const std::wstring expression = L"[а-яА-Я0-9]+"; // simple regex
    const std::wregex re(expression);

    std::wsmatch match;
    if (std::regex_match(str, match, re) && match.size() >= 3)
    {
        surname = std::move(match[0]);
        name = std::move(match[1]);
        phone = std::stoull(match[2]);
    }
}

vertoker::User::User(std::wstring surname, std::wstring name, uint64_t phone)
    : surname{std::move(surname)}, name{std::move(name)}, phone{phone} {}
