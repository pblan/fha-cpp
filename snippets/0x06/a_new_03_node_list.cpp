// author: a.voss@fh-aachen.de

#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::ostream;
using std::initializer_list;

template<typename T>                                        // (A)
class node_list;

template<typename T>                                        // (B)
class node {
public:
    typedef T value_type;
    value_type content;
private:
    node(const value_type &content, node *next)
            : content(content), next_(next) {}

    node * next_;

    friend class node_list<T>;                              // (C)
};

template<typename T>
class node_list {
public:
    typedef T value_type;

    node_list() = default;

    node_list(const initializer_list<value_type> &list) {
        for (const auto &x : list)
            push_front(x);
    }

    size_t count() const { return count_; }

    node_list& push_front(const value_type &value) {
        root_ = new node<value_type>{value, root_};
        ++count_;
        return *this;
    }

    void clear() {
        auto it = root_;
        while (it != nullptr) {
            auto *current = it;                             // (D)
            it = (*it).next_;
            delete current;
        }
        root_ = nullptr;
        count_ = 0;
    }

    class iterator {                                        // (E)
    public:
        node<value_type> *node;

                                                            // (F)
        iterator operator++() { return iterator{node = node->next_}; }

        friend bool operator==(const iterator &it1, const iterator &it2) {
            return it1.node == it2.node;
        }

        friend bool operator!=(const iterator &it1, const iterator &it2) {
            return !(it1 == it2);
        }

        value_type &operator*() { return node->content; }
    };

    iterator begin() const { return iterator{root_}; }      // (G)

    iterator end() const { return iterator{nullptr}; }

    friend ostream &operator<<(ostream &os, const node_list &list) {
        os << "[";
        for (const auto &x : list)
            os << " " << x;
        os << " ] (" << list.count() << ")";
        return os;
    }

private:
    node<value_type> *root_{nullptr};                       // (H)
    size_t count_{0};
};

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    // btw: die Klasse kann nur wachsen...
    node_list<int> list{1, 2, 3};
    list.push_front(4)
        .push_front(5)
        .push_front(6);
    cout << "01) " << list << endl;
    cout << "02) einzeln:" << endl;
    // for (auto it = list.begin(); it != list.end(); ++it) {
    //     cout << "    " << (*it) << endl;
    // }
    // for (node_list<int>::value_type & it : list) {
    //     cout << "    " << it << endl;
    // }
    for (auto & it : list) {
        cout << "    " << it << endl;
    }

    list.clear();
    cout << "03) " << list << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Vorwärts-Deklaration der Klasse. Diese wird in node referenziert, daher ist
 *      das notwendig, da der Compiler immer nur das kennt, was er bis zum jeweiligen
 *      Punkt gesehen hat, nicht den Rest der Datei.
 *
 * (B)  Eine node-Klasse. Diese soll vom Nutzer der node_list eigentlich nicht
 *      verwendet werden, daher wäre sie als innere Klasse von node_list auch geeignet.
 *      Insbesondere ist nur content public, auch der ctor ist private.
 *
 * (C)  friend class sagt, dass diese Klasse auf alle privaten Member zugreifen darf,
 *      als wenn die Klasse Teil der Klasse ist.
 *      friend gibt es auch für Methoden bzw. Operatoren.
 *
 * (D)  Wichtig ist hier, zuerst den Zeiger auf das nächste Element zu sichern, bevor
 *      man mit delete die node freigibt. Der Zeiger wird wahrscheinlich (!) noch auf
 *      die node mit gültigen Einträgen zeigen, aber im Prinzip könnte der Speicher
 *      nach delete sofort vergeben werden und dann ist der Zugriff auf next einfach
 *      nicht mehr erlaubt.
 *
 * (E)  Eine iterator-Klasse, um ein einfaches range-based-for zu realisieren.
 *
 * (F)  Zu den Operatoren kommen wir später noch, aber sie sind notwendig. Inhaltlich
 *      sollte klar sein, was passiert.
 *
 * (G)  Hier werden zwei Iteratoren erzeugt, die den Anfang und das Ende der
 *      Liste beschreiben. Dies brauchen wir für range-based-for.
 *
 * (H)  Start der Liste.
 *
 */
 
