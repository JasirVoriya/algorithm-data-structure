#include <bits/stdc++.h>
using namespace std;
struct Pos
{
    double x, y;
    void add(Pos &d)
    {
        x += d.x;
        y += d.y;
    }
};
class Sprit
{
private:
    Pos p1, p2, p3, pmid;

public:
    Sprit(Pos p1, Pos p2, Pos p3)
    {
        this->p1 = p1, this->p2 = p2, this->p3 = p3;
        this->pmid.x = (p1.x + p2.x + p3.x) / 2;
        this->pmid.y = (p1.y + p2.y + p3.y) / 2;
    }
    void Translate(Pos d)
    {
        p1.add(d), p2.add(d), p3.add(d);
    }
    void Rotate(double angle)
    {
    }
    void Scale(double s)
    {
        this->p1.x *= s, this->p2.x *= s, this->p3.x *= s;
        this->p1.y *= s, this->p2.y *= s, this->p3.y *= s;
        this->pmid.x = (p1.x + p2.x + p3.x) / 2;
        this->pmid.y = (p1.y + p2.y + p3.y) / 2;
    }
    void print()
    {
        printf("%.3lf %.3lf %.3lf %.3lf %.3lf %.3lf",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
    }
};
int main(void)
{
    Pos p[3];
    for (int i = 0; i < 3; i++)
        cin >> p[i].x >> p[i].y;
    Sprit s(p[0], p[1], p[2]);
    int n;
    cin>>n;
    string command;
    while(n--)
    {
        cin>>command;
        if(command=="translate")
        {
            Pos d;
            cin>>d.x>>d.y;
            s.Translate(d);
        }
        else if(command=="rotate")
        {
            double angle;
            cin>>angle;
            s.Rotate(angle);
        }
        else if(command=="scale")
        {
            double ratio;
            cin>>ratio;
            s.Scale(ratio);
        }
    }
    s.print();
    return 0;
}