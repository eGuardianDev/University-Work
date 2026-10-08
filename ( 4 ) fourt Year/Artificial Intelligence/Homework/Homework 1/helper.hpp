
#ifndef HELPER
#define HELPER




bool print(vector<int> list){
    for(int a : list){
        printf("%d ",a);
        // if(a == 1){
        //     cout << "\033[1;31m" << a;
        // }
        // if(a == 2){
        //     cout << "\033[1;32m" << a;
        // }
        // if(a == 0){
        //     cout << "\033[0m" << a;
        // }
    }
    printf("\n");

    return 0;
}

bool is_list_solved(vector<int> list){
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

bool populate(vector<int> & list){
     int top1 = list.size()/2;
    int begin2 =top1+1;

    for(int i =0;i<top1;++i){
        list[i]= 1;
    }
    for(int i =begin2; i<list.size();++i){
        (list[i]=2);
    }

    return 1;
}

#endif // HELPER
