#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

// Legen Sie eine Struktur 'address' an, die einen Namen und eine Tel.Nr., beides vom Typ 'string', enthält.
struct address
{
    std::string tel;
    std::string name;

    address(const std::string &tel, const std::string &name)
        : tel(tel), name(name) {}
};

std::ostream &operator<<(std::ostream &os, const std::unordered_map<int, address *> &m);
std::ostream &operator<<(std::ostream &os, const std::unordered_map<int, std::unique_ptr<address>> &m);

// new, dynamische Strukturen, smart pointer
int main()
{
    // Speichern Sie drei fiktive Datensätze jeweils unter einer ID in einer 'unordered_map<int, address*>'.
    // Die 'address'-Sruktur erhalten Sie dynamisch mit 'new' und speichern nur den Zeiger.
    std::unordered_map<int, address *> m = {
        {0, new address{"1234", "Alexander"}},
        {1, new address{"5678", "Bertram"}},
        {2, new address{"9012", "Carl"}}};

    // Geben Sie die komplette Map aus.
    std::cout << m;

    // Erweiterung:
    // Geben Sie die Daten der Map am Ende wieder frei.
    std::unordered_map<int, address *>::iterator it{m.begin()};

    while (it != m.end())
    {
        delete it->second;
        it = m.erase(it);
    }

    std::cout << "map size after cleanup: " << m.size() << std::endl;

    // Testen Sie Ihren Code auf Speicherlecks.

    /* 
    $ valgrind ./rosepond.out
    ==467== Memcheck, a memory error detector
    ==467== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==467== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
    ==467== Command: ./rosepond.out
    ==467== 
    [2] : [Carl, 9012]
    [1] : [Bertram, 5678]
    [0] : [Alexander, 1234]
    map size after cleanup: 0
    ==467== 
    ==467== HEAP SUMMARY:
    ==467==     in use at exit: 0 bytes in 0 blocks
    ==467==   total heap usage: 9 allocs, 9 frees, 74,016 bytes allocated
    ==467== 
    ==467== All heap blocks were freed -- no leaks are possible
    ==467== 
    ==467== For lists of detected and suppressed errors, rerun with: -s
    ==467== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    */

    // Verwenden Sie 'unique_ptr' statt 'address*'.
    std::unordered_map<int, std::unique_ptr<address>> m2;

    m2[0] = std::make_unique<address>("1234", "Alexander");
    m2[1] = std::make_unique<address>("5678", "Bertram");
    m2[2] = std::make_unique<address>("9012", "Carl");

    std::cout << m2;

    m2.clear();

    std::cout << "map size after cleanup: " << m2.size() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const std::unordered_map<int, address *> &m)
{
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        os << "[" << it->first << "] : "
           << "[" << it->second->name << ", " << it->second->tel << "]" << std::endl;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::unordered_map<int, std::unique_ptr<address>> &m)
{
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        os << "[" << it->first << "] : "
           << "[" << it->second->name << ", " << it->second->tel << "]" << std::endl;
    }
    return os;
}