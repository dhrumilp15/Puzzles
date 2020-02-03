// DMOPC 19 Contest 4 P5 - Financial Trouble
#include <bits/stdc++.h>

using namespace std;

int n, m, q, d[300000], l, r, x, c;

int main() {

    scanf("%d%d%d", &n, &m, &q);
    for (int i=0; i<n; ++i) {
        scanf("%d",&d[i]);
    }
    for (int i=0; i<q; ++i) {
        x = m;
        scanf("%d%d",&l,&r);
        for (int j=l-1; j<r; ++j) {
            x += d[j];
            if (x < 0) {
                x = 0;
                ++c;
            }
        }
        printf("%d %d\n",x,c);
        c = 0;
    }

}