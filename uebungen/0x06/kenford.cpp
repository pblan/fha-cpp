#include <iostream>
#include <memory>

// Realisieren Sie eine verkettete Liste, in der jeder Knoten einen 'int' und einen Zeiger ('unique_ptr') auf den nächsten Knoten enthält.
// Machen Sie aus der Liste ein Template für beliebige Datentypen (nicht nur 'int').
template <typename T>
class linked_list
{
    typedef T value_type;
    struct node
    {
        value_type value;
        std::unique_ptr<node> next;

        node(const value_type &value) : value{value} {}
    };

private:
    // Die Liste enthält einen Zeiger 'root' auf den ersten Knoten, sowie einen Zähler 'count'.
    std::unique_ptr<node> root;
    size_t count;

public:
    // Die Liste bietet eine Funktion 'add(int n)' zum Hinzufügen eines Knotes, [...]
    void add(value_type value)
    {
        auto new_node = std::make_unique<node>(value);

        if (root == nullptr)
        {
            root = std::move(new_node);
        }
        else
        {
            new_node->next = std::move(root);
            root = std::move(new_node);
        }

        ++count;
    }

    // [...] eine Funktion 'clear' zum Löschen bzw. Freigeben aller Daten, [...]
    void clear()
    {
        root.reset();
    }

    // [...] sowie einen Ausgabeoperator.
    friend std::ostream &operator<<(std::ostream &os, const linked_list &l)
    {
        auto *ptr = &(l.root);

        std::string delim{""};
        while (ptr->get() != nullptr)
        {
            os << delim << (*ptr)->value;
            ptr = &((*ptr)->next);

            delim = ", ";
        }

        return os;
    }
    linked_list() : count{0} {};
    ~linked_list() = default;
};

// new, dynamische Strukturen, smart pointer
int main()
{
    linked_list<int> l;

    l.add(1);
    l.add(2);
    l.add(3);

    std::cout << "l: " << l << std::endl;

    l.clear();

    std::cout << "l.clear();" << std::endl;
    std::cout << "l: " << l << std::endl;

    // Testen Sie Ihren Code auf Speicherlecks.

    /*
    $ valgrind ./kenford.out 
    ==1734== Memcheck, a memory error detector
    ==1734== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==1734== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
    ==1734== Command: ./kenford.out
    ==1734== 
    l: 3, 2, 1
    l.clear();
    l: 
    ==1734== 
    ==1734== HEAP SUMMARY:
    ==1734==     in use at exit: 0 bytes in 0 blocks
    ==1734==   total heap usage: 5 allocs, 5 frees, 73,776 bytes allocated
    ==1734== 
    ==1734== All heap blocks were freed -- no leaks are possible
    ==1734== 
    ==1734== For lists of detected and suppressed errors, rerun with: -s
    ==1734== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    */
}