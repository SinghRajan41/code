#include <iostream>
#include <cmath>
using namespace std;
struct point
{
   int x;
   int y;
};
void findClosestPoint(point points[], int n);
int main()
{
   int n;
   cout << "\nEnter the number of points = ";
   cin >> n;
   point points[n];
   cout << "\nEnter the points = ";
   for (int i = 0; i < n; i++)
   {
      cin >> points[i].x >> points[i].y;
   }
   findClosestPoint(points, n);
   return 0;
}
void findClosestPoint(point points[], int n)
{
   int dist = 99999999;
   point closePoint1 = {0, 0};
   point closePoint2 = {0, 0};
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         int d = pow((points[j].x - points[i].x), 2) + pow((points[j].y - points[i].y), 2);
         if (d < dist)
         {
            closePoint1 = points[i];
            closePoint2 = points[j];
            dist = d;
         }
      }
   }
   cout << endl
        << endl
        << "Closest points are = ";
   cout << closePoint1.x << " " << closePoint1.y << "\t, " << closePoint2.x << " " << closePoint2.y << endl;
}