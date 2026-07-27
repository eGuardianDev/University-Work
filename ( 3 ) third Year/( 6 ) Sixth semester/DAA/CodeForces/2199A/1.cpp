

    #include <iostream>
    int main(){

        int t;

        std::cin >> t;



        while(t > 0){
        
            int alice = 0;
            int bob = 0;
            
            int al = 0;
            int bo= 0;
            
            int k;
            std::cin >> k;

            int a1,b1,a2,b2;


            std::cin >> a1 >> b1;
            alice += a1;
            bob += b1;

            if(a1 > b1) al++;
            else bo++;

            
            std::cin >> a1 >> b1;
            alice += a1;
            bob += b1;

            if(a1 > b1) al++;
            else bo++;


            if(alice - k >= bob) std::cout << "NO" << std::endl;
            else std::cout << "YES" << std::endl;


            t--;
        }


        return 0;
    }