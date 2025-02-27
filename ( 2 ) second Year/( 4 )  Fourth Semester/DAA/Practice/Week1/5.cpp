#include <bits/stdc++.h>
#include <cmath>

const int maxx =25;
long long a[maxx][maxx], b[maxx][maxx], c[maxx][maxx];

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin.tie(NULL);


    int n,m,k,i,j,t;

    std::cin >> n >> m >> k;

    for(i =1; i<=n; ++i)
        for(j = 1; j<=m;++j)
            std::cin >> a[i][j];
    
    
    for(i =1; i<=m; ++i)
        for(j = 1; j<=k;++j)
            std::cin >> b[i][j];
        
    for(i = 1;i<=n;++i)
        for(j = 1;j<=k;++j){
            for(t=1;t<=m;++t){
                c[i][j]= c[i][j]+ a[i][t]*b[t][j];
            }
        }
    
    for(i = 1;i<=n;++i){
        for(j=1; j<=k;++j)
            std::cout << c[i][j] << " ";
        std::cout << std::endl;    
    }



    return 0;
}