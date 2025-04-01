#include "User.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

void print(const std::vector<vertoker::User>& users, vertoker::UserStringPred_t printPred)
{
    for (const auto& user : users)
        std::wcout << printPred(user) << std::endl;
}

int main()
{
    setlocale(LC_ALL, "");

    std::vector<vertoker::User> users;

    std::wifstream ifs("./list.txt", std::wifstream::in);
    if (ifs)
    {
        std::wstring lineBuffer;
        while (std::getline(ifs, lineBuffer))
            users.emplace_back(lineBuffer);
    }

    std::wcout << users[0].GetSurname() << std::endl;

    uint8_t buf;
    std::wcout << L"По какому параметру сортировать: ";
    std::cin >> buf;

    if (buf == 1)
    {
        std::sort(users.begin(), users.end(), vertoker::nameLessPred);
        print(users, vertoker::Print_NameSurnamePhone);
    }
    else if (buf == 2)
    {
        std::sort(users.begin(), users.end(), vertoker::surnameLessPred);
        print(users, vertoker::Print_SurnameNamePhone);
    }
    else if (buf == 3)
    {
        std::sort(users.begin(), users.end(), vertoker::phoneLessPred);
        print(users, vertoker::Print_PhoneSurnameName);
    }

    std::cin.ignore(); // for console app

    return 0;
}