#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
    setlocale(LC_ALL, "Rus");

    // wif for wchar_t
    std::wifstream ifs("./list.txt", std::wifstream::in);

    while (ifs)
    {
        wchar_t buffer;
        ifs >> buffer;
        std::cout << buffer; // wcout for wchar_t
    }

    std::cin.ignore(); // for console app

    return 0;
}