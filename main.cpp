#include <iostream>

using namespace std;

class CPoint {
private:
    int x, y;
public:
    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void printPoint() {
        cout << this->x << ":" << this->y << endl;
    }
    CPoint(){
        cout << "CPoint constructor..." << endl;
    }
    ~CPoint(){
        cout << "CPoint destructor..." << endl;
    }

    CPoint offset(int diff){
        x+=diff;
        y+=diff;
        return *this; //real use of this 把兩個點加位移然後回傳回去
    }
};

int main() {
    CPoint *cp = new CPoint;
    cp->setPoint(3,4);
    cp->printPoint();
    *cp = cp->offset(10);//回傳的值是CPoint型態把自己的實體資料覆蓋掉
    cp->printPoint();
    delete(cp);
    return 0;
}