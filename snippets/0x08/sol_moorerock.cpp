// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class window
{
public:
    window(unsigned long res_id) : m_visible(false), m_res_id(res_id) {
        cout << "-a|      ctor::window, id:" << m_res_id << endl;
    }
    
    void hide() { m_visible=false; }
    void show() { m_visible=true; }
    
    virtual void draw() = 0;

    virtual ~window() { 
        cout << "-b|      dtor::window, id:" << m_res_id << endl;
    }

protected:
    bool m_visible;
    unsigned long m_res_id;
};

class button : public window 
{
public:
    button(unsigned long res_id) : window(res_id) {}

    virtual void draw() { 
        cout << "-a|      button draw, id:" << m_res_id << endl; 
    } 
};

class checkbox : public window 
{
public:
    checkbox(unsigned long res_id) : window(res_id) {}

    virtual void draw() { 
        cout << "-b|      checkbox draw, id:" << m_res_id << endl; 
    } 
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    vector<unique_ptr<window>> windows;
    
    windows.push_back(make_unique<button>(1));
    windows.push_back(make_unique<checkbox>(2));

    cout << "01|    draw all:" << endl; 
    for (auto& window: windows) {
        window->hide();
        window->draw();
        window->show();
    }
   
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 */
 
