// Mr. Pepcoder has a 2D Array, and his Friend love to do operations on thearray. The operations can be a query or an update.

// For each query the Friend say four indices x1, y1, x2 and y2, and their father answers back with the sum of the elements of the rectangle whose top left index is x1, y1 and bottom right is x2, y2.

// When there is an update, the friend says index (x1,y1) and a value x , and Pepcoder will add x to arr[x1][y1] (so the new value of arr[x1][y1]  is arr[x1][y1] + x ).

// Because indexing the array from zero is too obscure for friend, all indices start from 1.

#include "../header.h";

const int m=4;
int t[4*m][4*m],a[m][m];
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else //cout<<lx<<" "<<ly<<endl,
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    
    build_y(vx, lx, rx, 1, 0, m-1);
}
int main(){
    int val=1;
    for(int i=0;i<m;i++)for(int j=0;j<m;j++)a[i][j]=val++;
    build_x(1,0,m-1);
    return 0;
}








// 3 3
// 1 2 3 
// 4 5 6
// 7 8 9
// 5
// q 1 1 2 2
// q 1 2 3 3
// q 2 1 3 2
// u 1 1 1
// q 1 1 2 2

