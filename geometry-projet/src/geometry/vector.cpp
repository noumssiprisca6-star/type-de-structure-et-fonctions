#include"vector.h"
#include<iostream>
 //addition de deux vecteurs
 Vector2f add(Vector2f v1,Vector2f v2){
    Vector2f resultat;
    resultat.x = v1.x + v2.x;
    resultat.y = v1.y + v2.y;

    return resultat;
 }

 //soustraction de deux vecteurs
 Vector2f soust(Vector2f v1,Vector2f v2){
    Vector2f resultat;
    resultat.x = v1.x - v2.x;
    resultat.y = v1.y - v2.y;
    return resultat;
 }

 //translation d'un point
  Point2f translated(Point2f p ,Vector2f v){
    Point2f resultat;
    resultat.x = p.x + v.x;
    resultat.y = p.y + v.y ;
    return resultat ;
  }

  //homothetie d'un vecteur 
  Vector2f homothety(Vector2f v , float k){
    Vector2f resultat;
    resultat.x = v.x * k;
    resultat.y = v.y * k;
    return resultat;
  }

  // norme(longueur du vecteurs )
  float norm(Vector2f v){
    return sqrt(pow(v.x,2) + pow(v.y,2));
  }

  //interpolarisation lineaire entre deux points 
  Point2f interpolate(Point2f p1, Point2f p2 ,float t){
    Point2f resultat;
    resultat.x = (1 - t) * p1.x + t * p2.x;
    resultat.y = (1 - t) * p1.y + t * p2.y;
    return resultat;
  }

  //rotation d'un vecteur autour de l'origine 
  Vector2f rotate(Vector2f v, float angleDeg){
    // convertion du dégré en radian
    float angleRad = angleDeg * M_PI / 180.0 ;
    Vector2f resultat;
    resultat.x=v.x * cos(angleRad) - v.y*sin(angleRad);
    resultat.y=v.x * sin(angleRad) - v.y*cos(angleRad);
    return resultat;
  }