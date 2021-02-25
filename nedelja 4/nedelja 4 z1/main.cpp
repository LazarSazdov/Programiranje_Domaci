#include <iostream>
#include <math.h>
using namespace std;
class XnaY
{
private:
    int X;
    int Y;
public:
    XnaY(int x,int y)
    {
        X = x;
        Y = y;
    }
    XnaY()
    {
        X=1;
        Y=1;
    }
    XnaY(const XnaY &o)
    {
        X = o.X;
        Y = o.Y;
    }

    void setX(int x)
    {
        X = x;
    }
    void setY(int y)
    {
        Y = y;
    }
    void setX_Y(int x, int y)
    {
        X = x;
        Y = y;
    }
    int getX()const
    {
        return X;
    }
    int getY()const
    {
        return Y;
    }
    int getXnaY()const
    {
        return pow(X,Y);
    }


};

int main()
{
    XnaY prvi;
    cout <<"PRVI: "<< prvi.getX() <<"\t" << prvi.getY() <<"\t" << prvi.getXnaY()<< endl;
    prvi.setX_Y(2,8);
    cout <<"PRVI: "<< prvi.getX() <<"\t" << prvi.getY() <<"\t" << prvi.getXnaY() << endl;
    XnaY drugi(2,2);
    cout <<"DRUGI: " << drugi.getX() <<"\t" << drugi.getY() <<"\t" << drugi.getXnaY() << endl;
    XnaY treci(prvi);
    cout <<"TRECI: " << treci.getX() <<"\t" << treci.getY() <<"\t" << treci.getXnaY() << endl;

    return 0;
}
