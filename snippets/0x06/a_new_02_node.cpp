// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

struct node {                                               // (A)
    int content;
    node* next_;
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    sizeof(node)=" << sizeof(node) << endl; // (B)

    cout << "-----" << endl;

    node *p, *root;                                         // (C)
       
    root = p = new node{1,nullptr};                         // (D)
    for (int i=2; i<=5; ++i) {
        (*p).next_ = new node{i, nullptr};                  // (E)
        cout << "02|    p=" << p << ", (*p).next=" << (*p).next_ << endl;
        p = (*p).next_;
    }

    cout << "-----" << endl;
    
    cout << "03|    nodes:";
    p = root;
    while (p!=nullptr) {
        cout << " " << (*p).content;
        p = (*p).next_;                                     // (F)
        // p = p->next;
    }
    cout << endl;

    cout << "-----" << endl;

    cout << "04|    deletes:";
    p = root;
    while (p!=nullptr) {                                    // (G)
        cout << " " << p;
        //delete p;
        //p = p->next;
        node* pDel = p;
        p = (*p).next_;
        delete pDel;
    }
    root = nullptr;
    cout << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  'node' ist eine Datenstruktur, um eine verkettet Liste aus
 *      diesen Knoten aufzubauen. Sie enthält einen Inhalt (int)
 *      und einen Zeiger auf den nächsten Knoten oder nullptr.
 * 
 * (B)  Man sieht, dass die Größe einer 'node' aus dem Zeiger (8) und
 *      dem inhalt (4) besteht, was dann vom Compiler auf 16
 *      'aufgerundet' (alignment) wird.
 * 
 * (C)  Achtung, bei der Deklaration mehrerer Zeiger muss der *
 *      jeweils angegeben werden. D.h.
 *          int* a,b        
 *      deklariert einen Zeiger a und einen int b
 *          int *a, *b      
 *      dagegen zwei Zeiger a und b.
 *      Hier ist 'root' unsere erste 'node' und 'p' ein Hilfszeiger. 
 * 
 * (D)  Wir holen uns Speicher für eine 'node' mittels 'new' vom Heap.
 *      Das ist wie bei dynamischen Feldern, nur dass hier nur ein Element 
 *      allokiert wird und kein Feld. Daher können wir es auch direkt 
 *      initialisieren.
 * 
 * (E)  Hier holen wir uns nacheinander vier Elemente und speichern 
 *      die Adresse immer in 'next' der vorhergegangenen 'node'.
 *      So entsteht eine Kette von Elementen, unsere Liste.
 * 
 * (F)  Durchlaufen der Liste, solange es noch Nachfolger (next!=nullptr)
 *      gibt.
 * 
 * (G)  Am Ende geben wir die Liste, d.h. die Elemente, nacheinander
 *      wieder frei. Da es einzelne Elemente sind und kein Feld, nutzen
 *      wir 'delete'.
 * 
 */
 
