// author: a.voss@fh-aachen.de

#if !defined(_TS)
#define _TS 1

#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <string>
#include <array>
#include <thread>

std::string ts() {
    static auto tm_start = std::chrono::system_clock::now();
    static std::array<std::string,5> thread_names = {"Main","Paul","Lisa","Hans","Rosi"};
    static std::unordered_map<std::thread::id,size_t> tm_ids;
    static size_t tm_id = 0;
    
    size_t id = tm_ids[std::this_thread::get_id()];
    if (id==0) {
        id = (tm_ids[std::this_thread::get_id()]=++tm_id);
    }
        
    std::string name;
    if (id-1<thread_names.size()) {
        name = thread_names[id-1];
    } else {
        std::stringstream s; s << "000" << std::this_thread::get_id();
        name = "x"+s.str().substr(s.str().size()-3);
    }
    //std::stringstream stname;
    //stname << std::hex << std::this_thread::get_id();
    //std::string tname = stname.str();
    //if (tname.size()>6) tname = tname.substr(tname.size()-6,6);
    
    std::stringstream s; s << std::fixed << std::setw(6) << std::setprecision(3) 
        << (double)(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-tm_start).count())/1000.0
        << " [" << name << "]";
    return s.str();
}

#endif
