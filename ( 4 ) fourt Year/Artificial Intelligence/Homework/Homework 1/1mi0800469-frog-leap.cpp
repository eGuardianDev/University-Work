    #include <iostream>
    #include <vector>

    using namespace std;

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

    bool dfs(vector<short> &list, int &index, int &size){
        if(is_list_solved(list)){
            return true;
        }

        for(int i =1;i<=2;++i){
            int frog_right = index + i;
            if(frog_right < size && list[frog_right] == 2) {
                swap(list[frog_right], list[index]);
                if(dfs(list,frog_right,size)){
                    print(list);
                    swap(list[frog_right], list[index]);
                    return true;
                }
                swap(list[frog_right], list[index]);
            }
        }

        for(int i =1;i<=2;++i){
            int frog_left = index - i;
            if(frog_left >= 0 && list[frog_left] == 1) {
                swap(list[frog_left], list[index]);
                if(dfs(list,frog_left,size)){
                    print(list);
                    swap(list[frog_left], list[index]);
                    return true;
                }
                swap(list[frog_left], list[index]);
            }
        }


        return false;
    }

    inline void start_dfs(vector<short> &list){
        int size = list.size();
        int middle = size/2;
        if(dfs(list, middle, size)){
            print(list);
        }else{
            std::cout << "Solution not found" << std::endl;
        }
    }


    int main(){

        int n =0;
        std::cin >> n;

        int size = 2*n+1;
        vector<short> list(size,0);

        populate(list);

        start_dfs(list);

        return 0;
    }
