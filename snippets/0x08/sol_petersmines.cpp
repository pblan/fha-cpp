// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// fahrzeuge

class befoerderungsmittel {
public:
    unsigned int sitze;
    
    befoerderungsmittel(unsigned int sitze) : sitze(sitze) {}
};

class fahrzeug {
public:
    unsigned int topspeed;

    fahrzeug(unsigned int topspeed) : topspeed(topspeed) {}
};

class automobile : public virtual befoerderungsmittel, public fahrzeug {
public:
    unsigned int raeder;
    
    automobile(unsigned int sitze, unsigned int topspeed, unsigned int raeder)
        : befoerderungsmittel(sitze), fahrzeug(topspeed), raeder(raeder)
    {}
};

class boot : public virtual befoerderungsmittel, public fahrzeug {
public:
    unsigned int schrauben;

    boot(unsigned int sitze, unsigned int topspeed, unsigned int schrauben)
        : befoerderungsmittel(sitze), fahrzeug(topspeed), schrauben(schrauben)
    {}
};

class amphibie : public automobile, public boot {
public:
    amphibie(unsigned int sitze, 
            unsigned int topspeed_auto, unsigned int raeder, 
            unsigned int topspeed_boot, unsigned int schrauben)
        : befoerderungsmittel(sitze), 
        automobile(sitze,topspeed_auto,raeder), 
        boot(sitze,topspeed_boot,schrauben)
    {}
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    amphibie a{4,120,6,15,2};
    cout << "01|    sizeof(a): " << sizeof(a) << endl; 

    cout << "02|    a.sitze: " << a.sitze << endl; 
    cout << "03|    a.auto::top: " << a.automobile::topspeed << endl; 
    cout << "04|    a.auto::raeder: " << a.raeder << endl; 
    cout << "05|    a.boot::top: " << a.boot::topspeed << endl; 
    cout << "06|    a.boot::schrauben: " << a.schrauben << endl; 
   
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 */
 
