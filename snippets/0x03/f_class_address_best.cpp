// author: a.voss@fh-aachen.de

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

// one not-so-bad-choice (IMHO) of an address class according to many discussion...
// as we already know this class, I add comments directly nearby

class address {

    // I do not like this attribute style, but get_xy is worse, so...
    int id_;
    string name_;
    string number_;
    unsigned int age_;

    // explanation of "move" follows in near future, but in a nutshell (!):
    //   we have to copy string data anyway, so one way is to copy from
    //   a const reference, the other is using move to reuse resources...
    //   anyway, there are discussions on it, more can be read here
    //   https://clang.llvm.org/extra/clang-tidy/checks/modernize-pass-by-value.html
    address(int id, string name, string number, unsigned int age)
            : id_{id}, name_{std::move(name)}, number_{std::move(number)}, age_{age} {
    }

public:
    // "static" is a class function, i.e. there is no "this" available;
    // here we have a factory method, hiding the actual creation process
    // and thus we get a private ctor
    static address make(int id, string name, string number, unsigned int age) {
        return address(id, std::move(name), std::move(number), age);
    }

    // "default" means to use default implementation, what helps to avoid
    // boiler plate code
    address(const address &a) = default;

    // now here we only have getter to access single attributes

    // "[[nodiscard]]" suppress compiler warnings in case return value is not used
    [[nodiscard]] int id() const { return this->id_; }

    [[nodiscard]] string name() const { return name_; }

    [[nodiscard]] string number() const { return number_; }

    [[nodiscard]] unsigned int age() const { return age_; }

    // and with the following functions I like to stress that instead of
    // providing plain setters, and thus show internal structures/states implicitly,
    // functions with a concrete purpose may be a better choice (even if they simply
    // set some data)
    // "[[maybe_unused]]" suppress compiler warnings for no using the functions
    [[maybe_unused]] void correct_data(const string &new_name, unsigned int new_age) {
        name_ = new_name;
        age_ = new_age;
    }

    [[maybe_unused]] void set_number(const string &new_number) {
        number_ = new_number;
    }

    // for "default" see above
    ~address() = default;

};

ostream &operator<<(ostream &os, const address &a) {
    os << "{id:" << a.id() << ",name:'" << a.name()
       << ",number:" << a.number() << ",age:" << a.age()
       << "}";
    return os;
}

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    address a = address::make(1, "Max Mustermann", "0241/12345", 46);

    cout << "01|    a=" << a << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

