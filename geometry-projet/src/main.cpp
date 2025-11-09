#include<iostream>
#include"geometry/utils.h"
#include "geometry/point.h"
#include "geometry/vector.h"
#include"geometry/vector.cpp"
Point2f rotateAroundpoint(Point2f p , Point2f center , float angle);
int main(){
     Vector2f v1 = {2, 3};
    Vector2f v2 = {1, 1};
    Point2f p = {3, 4};

    std::cout << "=== Calculs Vectoriels ===" <<std::endl;

    Vector2f sum = add(v1, v2);
    std::cout << "Addition: (" << sum.x << ", " << sum.y << ")" <<std::endl;

    Vector2f diff = soust(v1, v2);
    std::cout << "Soustraction: (" << diff.x << ", " << diff.y << ")" << std::endl;

    Vector2f scaled = homothety(v1, 2);
    std::cout << "Homothétie: (" << scaled.x << ", " << scaled.y << ")" << std::endl;

    std::cout << "Norme de v1: " << norm(v1) <<std::endl;

    Point2f transl = translated(p, v1);
    std::cout << "Translation du point p: (" << transl.x << ", " << transl.y << ")" <<std::endl;
    Point2f interp = interpolate({0, 0}, {10, 10}, 0.5);
    std::cout << "Interpolation: (" << interp.x << ", " << interp.y << ")" <<std::endl;

    Vector2f rotated = rotate(v1, 90);
    std::cout << "Rotation de v1 (90°): (" << rotated.x << ", " << rotated.y << ")" << std::endl;

    Point2f rotateAroundPoint(Point2f p, Point2f center , float angle);
   // pour faire tourner le point p autour de center , sans cela rotateAroundpoint ne sera pas definit 
    
    
 Point2f rotatedP = rotateAroundpoint({4, 2}, {1, 1}, 90);
    std::cout << "Rotation du point (4,2) autour de (1,1): (" << rotatedP.x << ", " << rotatedP.y << ")" << std::endl;

return 0 ;
}



