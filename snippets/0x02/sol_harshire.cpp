// author: a.voss@fh-aachen.de

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::string;

const size_t stack_dim{3};
struct stack {
    int buffer[stack_dim];
    size_t next{0};
};

struct stack_exception {
    string what;
    char level;
};

void init(stack& st) {
    for (size_t i=0; i<stack_dim; ++i)
        st.buffer[i]=0;
}

void out(stack& st) {
    cout << "-a|      [ ";
    for (size_t i=0; i<stack_dim; ++i)
        cout << st.buffer[i] << " ";
    cout << "] (next:" << st.next << ",top:";
    if (st.next>0)
        cout << st.buffer[st.next-1];
    else
        cout << "-";
    cout << ")" << endl;
}

void push(stack& st, int n) {
    if (st.next>=stack_dim)
        throw stack_exception{"stack full",'E'};
    st.buffer[st.next++]=n;
}

int pop(stack& st) {
    if (st.next<=0)
        throw stack_exception{"stack empty",'E'};
    return st.buffer[--st.next];
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    stack st;
    
    cout << "01|    st:" << endl;
    out(st);
    
    cout << "02|    init:" << endl;
    init(st);
    out(st);
    
    cout << "03|    push:" << endl;
    try {
        push(st,2);
        out(st);
        
        push(st,3);
        out(st);
        
        push(st,5);
        out(st);
        
        push(st,7);
        out(st);
    } catch (const stack_exception& e) {
        cout << "04|    stack_exception: '" 
             << e.what << "' (" << e.level << ")" << endl;
    }

    cout << "-----" << endl;

    cout << "05|    pop:" << endl;
    int n;
    try {
        n = pop(st);
        cout << "06|      n:" << n << endl;
        out(st);
        
        n = pop(st);
        cout << "07|      n:" << n << endl;
        out(st);
        
        n = pop(st);
        cout << "08|      n:" << n << endl;
        out(st);
        
        n = pop(st);
    } catch (...) {
        cout << "09|    exception: reason unknow" << endl;
    }
       
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
