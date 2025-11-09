#include"point.h"
//fonction pour translater un point 
Point2f translated(Point2f p, float dx , float dy){
    Point2f resultat;
    resultat.x = p.x + dx;
    resultat.y = p.y + dy;
    return resultat;
}
 // fonction pour l,interpolation lineare entre deux point 
 Point2f interpolate(Point2f p1, Point2f p2, float t){
    Point2f resultat;
    resultat.x = (1 - t)  * p1.x + t *p2.x;
    resultat.y = (1 - t)  * p1.y + t *p2.y;
    return resultat;
}