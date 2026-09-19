class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
       int xmin=( abs(x1-xCenter)>=abs(x2-xCenter) )?x2:x1;
       int ymin=( abs(y1-yCenter)>=abs(y2-yCenter) )?y2:y1;
       int xdiff=xmin-xCenter , ydiff=ymin-yCenter;
xdiff*=xdiff;
ydiff*=ydiff;
 if( (xCenter<=x2 && xCenter>=x1 ) )
return !(y1>(yCenter+radius) || y2<(yCenter-radius) ); 
 else if(yCenter>=y1 && yCenter<=y2)
 return !(x1>(xCenter+radius) || x2<(xCenter-radius) ); 

        return ( sqrt(xdiff+ydiff)<=radius);
    }
};