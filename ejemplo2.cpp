#include
using namespace std
struct Point 
{
    int x, y;
};
int main()
{
    Point p1, p2;
    p1.x=0;
    p1.y=0;
    p2.x=10;
    p2.y=5;
    char character = 't';
    int a =89;
    float b=152461.98;
    cout<<"char + int: "<<character+a<<endl;
    cout<<"float + int: "<<b+a<<endl;
    p2.x++;
    a+p2.y++;
    int c=++a;
    c+8;
    c*=3;
    return 0;

}