#include <iostream>
#include <string>
#include <vector>

// Implementieren Sie eine Klasse 'states', die eine Menge von Zuständen enthalten kann, wovon genau einer aktiv ist.
// Beispiele von Zuständen: {'Locked', 'Unlocked'} oder auch {'Connected', 'Disconnected', 'Unknown'}.
// Nutzen Sie intern einen 'vector' von 'string' zum Speichern der States, und einen Index für den gerade aktuellen Zustand.
class states
{
private:
    std::vector<std::string> values;
    size_t index;

public:
    states()
        : index(0){};
    ~states() = default;

    // Implementieren Sie geeignete Operatoren bzw. Funktionen, so dass folgende Codeschnipsel für eine 'states'-Instanz 's' funktionieren:

    // 's += "home";' fügt Zustand 'home' zu 's' hinzu.
    states &operator+=(const std::string &state)
    {
        values.push_back(state);
        return *this;
    }

    // 's = 1;' setzt aktuellen Zustand auf den zweiten Zustand.
    states &operator=(size_t index)
    {
        if (index >= values.size())
        {
            throw std::runtime_error("index too big");
        }
        this->index = index;
        return *this;
    }

    // '++s;' setzt den aktuellen Zustand um eins weiter.
    // Beim Über- oder Unterlauf vorne bzw. hinten anfangen.
    states &operator++()
    {
        if (values.size() == 0)
        {
            throw std::runtime_error("no states");
        }

        if (index == (values.size() - 1))
        {
            index = 0;
        }
        else
        {
            ++index;
        }

        return *this;
    }

    // '--s;' setzt den aktuellen Zustand um eins zurück.
    // Beim Über- oder Unterlauf vorne bzw. hinten anfangen.
    states &operator--()
    {
        if (values.size() == 0)
        {
            throw std::runtime_error("no states");
        }

        if (index == 0)
        {
            index = values.size() - 1;
        }
        else
        {
            --index;
        }

        return *this;
    }

    // 's[s()]' gibt den aktuellen Zustand (string) zurück.
    size_t operator()()
    {
        return index;
    }

    std::string &operator[](size_t index)
    {
        if (index >= values.size())
        {
            throw std::runtime_error("index too big");
        }
        return values[index];
    }

    // 's.clear();' löscht alle Zustände.
    void clear()
    {
        values.clear();
        index = 0;
    }

    // 'cout << s;' gibt einen Vektor mit allen Zuständen aus.
    friend std::ostream &operator<<(std::ostream &os, const states &s)
    {
        std::string delim{""};

        os << "[";
        for (auto x : s.values)
        {
            os << delim << x;
            delim = ", ";
        }
        os << "]";
        return os;
    }
};

// Grundsätzlich soll ein bestimmter Zustand abgefragt und gesetzt werden können.
// Weiter kann man den aktuellen Zustand um eins weiter oder um eins zurück setzen.
// Natürlich sollen auch Zustände hinzugefügt werden und alle gelöscht werden können.

// Operatoren
int main()
{
    // Testen Sie Ihren Code aussagekräftig.
    states s;

    std::cout << s << std::endl;

    s += "unknown";

    std::cout << s << std::endl;

    s += "connected";
    s += "disconnected";

    std::cout << "aktuell: " << s[s()] << ", " << s << std::endl;

    s = 1;

    std::cout << "aktuell: " << s[s()] << ", " << s << std::endl;

    ++s;

    std::cout << "aktuell: " << s[s()] << ", " << s << std::endl;

    ++s;

    std::cout << "aktuell: " << s[s()] << ", " << s << std::endl;

    --s;

    std::cout << "aktuell: " << s[s()] << ", " << s << std::endl;

    s.clear();

    std::cout << s << std::endl;
}
