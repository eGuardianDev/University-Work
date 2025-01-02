#ifndef _Word_Struct__
#define _Word_Struct__

#include <string>
struct Word{
    std::string data;
    int val;
    int count = 0;
    void Destruction(){
        data = "";
        val = -1;
        count = 0;
    }

    bool operator==(const Word& other) const {
        return data == other.data && val == other.val && count == other.count;
    }
};

#endif