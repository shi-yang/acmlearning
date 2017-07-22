#include <cstdio>  
#include <cmath>  
#include <vector>  
#include <algorithm>  
#include <cstring>  
#include <iostream>  
using namespace std;  
  
const double PI = acos(-1.0);  
const double eps = 1e-10;  
//    定义点  
struct Point  
{  
    double x, y;  
    Point(double x = 0, double y = 0) : x(x), y(y) {}    //构造函数，方便代码编写  
};  
//  
typedef Point Vector;       //向量是点的一个别名  
//重载 +, -, *, /, <, == 运算符  
Vector operator + (Vector A, Vector B)    //“+”运算符，向量+向量=向量  
{  
    return Vector(A.x + B.x, A.y + B.y);  
}  
Vector operator - (Point A, Point B)        //“-”运算符，点-点=向量  
{  
    return Vector(A.x - B.x, A.y - B.y);  
}  
Vector operator * (Vector A, double p)      //“*”运算符，向量*数=向量  
{  
    return Vector(A.x * p, A.y * p);  
}  
Vector operator / (Vector A, double p)     //“/”运算符，向量/数=向量  
{  
    return Vector(A.x / p, A.y / p);  
}  
bool operator < (const Point& a, const Point& b)    //“<”运算符  
{  
    return a.x < b.x || (a.x == b.x && a.y > b.y);  
}  
//叉积，两向量组成的三角形的有向面积的两倍  
double Cross(Vector A, Vector B)  
{  
    return A.x * B.y - A.y * B.x;  
}  
//向量旋转   
Vector Rotate(Vector A, double rad)  
{  
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));  
}  
//多边形有向面积   
double PolygonArea(Point* p, int n)   
{  
    double area = 0;  
    for (int i = 1; i < n - 1; i++)  
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);  
    return area / 2;  
}  
//角度转换成弧度   
double torad(double deg)  
{  
    return deg / 180 * PI;  
}  
//计算凸包，输入点数组p，个数为n，输出点数组ch，函数返回凸包顶点数。  
//输入不能有重复点，函数执行完后输入的点的顺序被破坏  
//如果不希望在凸包的边上有输入点，把两个<=改成<  
//在精度要求高时建议用dcmp比较  
int ConvexHull(Point* p , int n, Point* ch)  
{  
    sort(p, p + n);     //先比较x坐标，再比较y坐标   
    int m = 0;  
    for (int i = 0; i < n; i++) {  
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;  
        ch[m++] = p[i];  
    }  
    int k = m;  
    for (int i = n - 2; i >= 0; i--) {  
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 1]) <= 0) m--;  
        ch[m++] = p[i];  
    }  
    if (n > 1) m--;  
    return m;  
}  
  
int main()  
{  
    int T;  
    Point P[2500], ch[2500];  
    scanf("%d", &T);  
    while (T--)  
    {  
        int n, pc = 0;  
        double area1 = 0;  
        scanf("%d", &n);  
        for (int i = 0; i < n; i++)  
        {  
            double x, y, w, h, j, ang;  
            scanf("%lf%lf%lf%lf%lf", &x, &y, &w, &h, &j);  
            Point o(x, y);  
            ang = -torad(j);            //顺时针旋转   
            P[pc++] = o + Rotate(Vector(-w/2, -h/2), ang);//先旋转从中心出发的向量   
            P[pc++] = o + Rotate(Vector(w/2, -h/2), ang);  
            P[pc++] = o + Rotate(Vector(-w/2, h/2), ang);  
            P[pc++] = o + Rotate(Vector(w/2, h/2), ang);  
            area1 += w * h;                     //累加木板总面积   
              
        }  
        int m = ConvexHull(P, pc, ch);  
        for (int i = 0; i < m; i++)
            cout << ch[i].x << ' ' << ch[i].y << endl;
        double area2 = PolygonArea(ch, m);  
        printf("%.1lf %%\n", area1 * 100 / area2);  
    }  
    return 0;  
}