#ifndef CUSTOM_STRING_TABLE
#define CUSTOM_STRING_TABLE


#include <map>

class StringTable {
    std::map<std::string, int> ids;
    int next_id = 1;
    
    public:
    int get_id(const std::string& s) {
        auto it = ids.find(s);
        if (it != ids.end()) return it->second;
        int id = next_id++;
        ids[s] = id;
        return id;
    }
    
    const std::map<std::string,int>& all() const {
        return ids;
    }
};

#endif// CUSTOM_STRING_TABLE