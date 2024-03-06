#include <iostream>
#include <cmath>

using namespace std;

struct Punkt {
    int x;
    int y;
};

int polygonArea(Punkt p[], int n) 
{
    int area = 0;
    for (int i = 0; i < n - 1; ++i) 
    {
        area += (p[i].x * p[i + 1].y - p[i + 1].x * p[i].y);
    }
    area += (p[n - 1].x * p[0].y - p[0].x * p[n - 1].y);
    return abs(area) / 2;
}

int main() 
{
    int l;
    cin >> l;

    while (l != 0)
    {

        int n; // ile wierzcholkow
        cin >> n;
        Punkt* polygon = new Punkt[n]; //alokacja pamieci dla n-elementow
        n = n / 2; // n dzielone na dwa bo wprowadzamy x i y razem

        for (int i = 0; i < n; i++)
        {
            cin >> polygon[i].x >> polygon[i].y;
        }

        cout << polygonArea(polygon, n) << endl;

        delete[] polygon; //czyszczenie zaalokowanej pamieci
        l--;

    }
    return 0;
}
