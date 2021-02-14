// author: a.voss@fh-aachen.de

#include <iostream>
#include <string>
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

    // not copy-able ...
    // vector<std::unique_ptr<window>> w = {make_unique<button>(1),make_unique<checkbox>(2)};

    vector<std::unique_ptr<window>> v;
    v.push_back(make_unique<button>(2));
    v[0] = make_unique<checkbox>(1);
    //v[1] = make_unique<button>(2);

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

