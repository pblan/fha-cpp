#include <iostream>

// Definieren Sie eine Klasse 'befoerderungsmittel', die eine Anzahl von Sitzplätzen als Member enthält.
class befoerderungsmittel
{
public:
    size_t m_sitze;

    befoerderungsmittel(size_t sitze)
        : m_sitze{sitze}
    {
        std::cout << "ctor befoerderungsmittel: sitze = " << sitze << std::endl;
    };

    ~befoerderungsmittel()
    {
        std::cout << "dtor befoerderungsmittel" << std::endl;
    };
};

// Definieren Sie eine Klasse 'fahrzeug', die eine Höchstgeschwindigkeit als Member enthält.
class fahrzeug
{
public:
    size_t m_hoechst;

    fahrzeug(size_t hoechst)
        : m_hoechst{hoechst}
    {
        std::cout << "ctor fahrzeug: hoechst = " << hoechst << std::endl;
    };
    ~fahrzeug()
    {
        std::cout << "dtor fahrzeug" << std::endl;
    };
};

// --------------------------------------------------------------------------------
// Leiten Sie die Klassen 'automobile' und 'boot' jeweils von 'befoerderungsmittel' und von 'fahrzeug' ab.
// Die Klasse 'befoerderungsmittel' soll virtuell geerbt werden.
// Erweiterung:
// Ergänzen Sie 'automobile' und 'boot' um weitere Member, die auhc jeweils den Konstruktoren übergeben werden.
class automobile : public virtual befoerderungsmittel, public fahrzeug
{
public:
    size_t m_raeder;

    automobile(size_t sitze, size_t hoechst, size_t raeder)
        : befoerderungsmittel(sitze), fahrzeug(hoechst), m_raeder{raeder}
    {
        std::cout << "ctor automobile: sitze: " << sitze << ", hoechst = " << hoechst << ", raeder = " << raeder << std::endl;
    };
    ~automobile()
    {
        std::cout << "dtor automobile" << std::endl;
    };
};

class boot : public virtual befoerderungsmittel, public fahrzeug
{
public:
    size_t m_luftkissen;

    boot(size_t sitze, size_t hoechst, size_t luftkissen)
        : befoerderungsmittel(sitze), fahrzeug(hoechst), m_luftkissen{luftkissen}
    {
        std::cout << "ctor boot: sitze = " << sitze << ", hoechst = " << hoechst << ", luftkissen = " << luftkissen << std::endl;
    };
    ~boot()
    {
        std::cout << "dtor boot" << std::endl;
    };
};

// --------------------------------------------------------------------------------
// Implementieren Sie eine Klasse 'amphibie', die von 'boot' und von 'automobile' erbt.
// Instanzen sollten dann nur eine Anzahl Sitzplätze besitzen, aber zwei Höchstgeschwindigkeiten.
class amphibie : public automobile, public boot
{
public:
    // Übergeben Sie den Konstruktoren jeweils alle notwendigen Parameter, d.h. die Initialisierung einer 'amphibie' mit vier Sitzplätzen und zwei Geschwindigkeiten sieht so aus:
    // 'amphibie a{4,120,15};'
    amphibie(size_t sitze, size_t hoechst_auto, size_t hoechst_boot, size_t raeder, size_t luftkissen)
        : befoerderungsmittel(sitze), automobile(sitze, hoechst_auto, raeder), boot(sitze, hoechst_boot, luftkissen)
    {
        std::cout << "ctor amphibie: sitze = " << sitze << ", hoechst_auto = " << hoechst_auto << ", hoechst_boot = " << hoechst_boot << ", raeder = " << raeder << ", luftkissen = " << luftkissen << std::endl;
    };
    ~amphibie()
    {
        std::cout << "dtor amphibie" << std::endl;
    };
};

int main()
{
    // Schreiben Sie aussagekräftigen Testcode und geben Sie insbesondere die Sitzplätze unt die Geschwindigkeiten aus.
    amphibie a{4, 120, 15, 4, 2};

    std::cout << "a.m_sitze = " << a.m_sitze << std::endl;
    std::cout << "a.m_luftkissen = " << a.m_luftkissen << std::endl;
    std::cout << "a.m_raeder = " << a.m_raeder << std::endl;
    std::cout << "a.boot::m_hoechst = " << a.boot::m_hoechst << std::endl;
    std::cout << "a.automobile::m_hoechst = " << a.automobile::m_hoechst << std::endl;
};
