#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
    std::wifstream ifs("./list.txt", std::wifstream::in); // wif for wchar_t

    std::wstring lineBuffer;
    while (ifs)
    {
        while (std::getline(ifs, lineBuffer))
            std::wcout << lineBuffer; // wcout for wchar_t
    }

    std::cin.ignore(); // for console app

    return 0;
}