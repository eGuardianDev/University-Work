
#ifndef HELPER
#define HELPER

inline bool print(const vector<short> &list){
    for(int a : list){
        switch(a){
            case 1:
                cout << "<";
            break;
            case 2:
                cout << ">";
            break;
            case 0:
                cout << "_";
            break;
        }
    }
    cout <<endl;
    return 0;
}

inline bool is_list_solved(const vector<short> &list){
    int top1 = list.size()/2;
    int begin2 =top1+1;

    for(int i =0;i<top1;++i){
        if(list[i] != 2){
            return 0;
        }
    }
    for(int i =begin2; i<list.size();++i){
        if(list[i] != 1){
            return 0;
        }
    }

    return 1;
}

inline bool populate(vector<short> &list){
    int top1 = list.size()/2;
    int begin2 =top1+1;

    for(int i =0;i<top1;++i){
        list[i]= 1;
    }
    for(int i =begin2; i<list.size();++i){
        list[i]=2;
    }

    return 1;
}

#endif // HELPER
