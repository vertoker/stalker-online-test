Тестовое задание в ООО Сталкер-Онлайн

`README.md` написан на русском, все комментарии в коде - на английском

Можете также посмотреть другие мои проекты
- [cpp-lua-testcase](https://github.com/vertoker/cpp-lua-testcase) - абстрактный
игровой-скриптовый движок, который содержит имплеметацию основного функционала `Lua`
- [vulkan-tech-demo](https://github.com/vertoker/vulkan-tech-demo) - мой
первый движок на Vulkan с базовыми шейдерами, интеграцией `ECS` и 
работой с игровыми ресурсами `res/`

Чтобы собрать проект - запустите `build.bat` (использует `g++`)


## Решения в разработке

Тут я хочу объяснить свои решения по поводу выбранных техник/подходов/решений

Сборка
- В качестве стандарта, я выбрал `C++17`. В тестовом он указан не был, 
поэтому я опирался на [вот эту статью](https://habr.com/ru/articles/894736/)
- Для сборки проекта из одного файла, я решил использовать только `.bat` файл.
Я мог бы сделать небольшой проект на `cmake`, но для такого маленького проекта,
считаю это не целесообразным

`list.txt`
- Исходный файл сохранён в кодировке `ANSI`, так как это самое
простое решение проблемы чтения русских символов через `wifstream`. 
Использовать сторонние библиотеки - не является частью задания, 
а писать свой аналог `wifstream` с поддержкой `UTF-8` - тоже к этому не относится

`main.cpp`
- Я использовать `wchar_t` везде где можно, так как нужна поддержка
широких строк для работы с русским языком
