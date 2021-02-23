#include <iostream>
#include <vector>
#include <memory>

// Definieren Sie eine Klasse 'window'.
// Sie dient als Superklasse und besitzt [...]
class window
{
protected:
    // [...] eine id, [...]
    size_t id;
    bool visible;

public:
    window(size_t id)
        : id{id}, visible{false}
    {
        std::cout << "class: window, ctor" << std::endl;
        std::cout << id << std::endl;
    };

    // [...] Methoden zum Anzeigen ('show') [...]
    void show()
    {
        std::cout << "class: window, method: show" << std::endl;
        visible = true;
    }

    // [...] und Verstecken ('hide'), [...]
    void hide()
    {
        std::cout << "class: window, method: hide" << std::endl;
        visible = false;
    }

    // [...] sowie eine rein virtuelle Methode 'draw'.
    virtual void draw() = 0
    {
        std::cout << "class: window, method: draw" << std::endl;
        std::cout << "id: " << id << std::endl;
    }
};

class button : public window
{
private:
    /* data */
public:
    button(size_t id) : window(id)
    {
        std::cout << "class: button, ctor" << std::endl;
        std::cout << id << std::endl;
    };

    virtual void draw()
    {
        std::cout << "class: button, method: draw" << std::endl;
        std::cout << "id: " << id << std::endl;
    }
};

class checkbox : public window
{
private:
    /* data */
public:
    checkbox(size_t id) : window(id)
    {
        std::cout << "class: checkbox, ctor" << std::endl;
        std::cout << id << std::endl;
    };

    virtual void draw()
    {
        std::cout << "class: checkbox, method: draw" << std::endl;
        std::cout << "id: " << id << std::endl;
    }
};

int main()
{
    std::vector<std::unique_ptr<window>> vec;
    vec.push_back(std::make_unique<window>(1));
    vec.push_back(std::make_unique<button>(2));
    vec.push_back(std::make_unique<checkbox>(3));
}
