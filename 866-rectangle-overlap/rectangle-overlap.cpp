class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0],y1=rec1[1],x2=rec1[2],y2=rec1[3];
        int xx1=rec2[0],yy1=rec2[1],xx2=rec2[2],yy2=rec2[3];
        bool xoverlap= (x2>xx1 && x1 <xx2 ) ;
        bool yoverlap= (y2>yy1 && y1<yy2 ) ;
cout<<xoverlap<<" "<<yoverlap<<endl;
        return xoverlap && yoverlap ;
    }
};