types de structure dans les fonctions , usages des vecteurs dans le temps et l'espace


 RÉCAPITULATIF DU PROJET : Geometry Project

 Objectif

Ce projet permet de manipuler des points et des vecteurs en C++.
On peut calculer la distance entre deux points et la longueur d’un vecteur.
C’est un exercice de base pour comprendre les classes, fichiers d’en-tête (.h) et fichiers source (.cpp).
j'ai pu apprendre de nombreuses notions grace à cet exercice 
comprenant ainsi que le c++ est un langage qui demande non seulement beaucoup de concentration mais egalement une bonne formation


---

🗂 Structure complète du projet

geometry-project/
└── src/
    ├── main.cpp
    ├── utils.h
    └── geometry/
        ├── point.cpp
        ├── point.h
        ├── vector.cpp
        └── vector.h


---

 Contenu des fichiers

 main.cpp

#include <iostream>
#include "geometry/utils.h"
#include "geometry/point.h"
#include "geometry/vector.h"

int main() {
    Point p1(1, 2);
    Point p2(4, 6);

    Vector v1(p1, p2);

    std::cout << "Distance between points: " << p1.distanceTo(p2) << std::endl;
    std::cout << "Vector length: " << v1.length() << std::endl;

    return 0;
}


---

utils.h

#pragma once
#include <cmath>

double square(double x) {
    return x * x;
}


---

 point.h

#pragma once
#include <cmath>

class Point {
public:
    double x, y;

    Point(double x=0, double y=0) : x(x), y(y) {}

    double distanceTo(const Point& other) const {
        return std::sqrt((x - other.x)(x - other.x) + (y - other.y)(y - other.y));
    }
};


---

 point.cpp

#include "point.h"
et les structure de manipulation requises


---

 vector.h

#pragma once
#include "point.h"
#include <cmath>

class Vector {
public:
    double x, y;

    Vector(const Point& from, const Point& to) {
        x = to.x - from.x;
        y = to.y - from.y;
    }

    double length() const {
        return std::sqrt(x*x + y*y);
    }
};


---

vector.cpp

#include "vector.h"

---
🔹 point.h

#ifndef POINT_H
#define POINT_H

#include <string>
#include "vector.h"

struct Point2f {
    float x;
    float y;
};

Point2f MakeP2f(float x, float y);
Point2f Translate(const Point2f& p, float dx, float dy);
Point2f Translate(const Point2f& p, const Vector2f& v);
Point2f Scale(const Point2f& p, float sx, float sy);
Point2f Scale(const Point2f& p, const Vector2f& s);
Point2f Rotate(const Point2f& p, float angleDegree);

std::string ToString(const Point2f& p);

#endif

🔹 vector.h

#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <cmath>

struct Vector2f {
    float x;
    float y;
};

Vector2f MakeV2f(float x, float y);
Vector2f MakeV2f(const Point2f& a, const Point2f& b);
Vector2f Add(const Vector2f& a, const Vector2f& b);
Vector2f Sub(const Vector2f& a, const Vector2f& b);
Vector2f Scale(const Vector2f& v, float scalar);
float Dot(const Vector2f& a, const Vector2f& b);
float Length(const Vector2f& v);
Vector2f Normalize(const Vector2f& v);
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);
float Determinant(const Vector2f& a, const Vector2f& b);

std::string ToString(const Vector2f& v);

#endif

🔹 utils.h

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// Templates ToString et Print
template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
std::string ToString(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << ToString(v[i]);
        if (i + 1 < v.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

template<typename K, typename V>
std::string ToString(const std::map<K, V>& m) {
    std::ostringstream oss;
    oss << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        oss << ToString(it->first) << ": " << ToString(it->second);
        if (std::next(it) != m.end()) oss << ", ";
    }
    oss << "}";
    return oss.str();
}

template<typename T, typename... Args>
void Print(const T& first, const Args&... args) {
    std::cout << ToString(first);
    ((std::cout << ", " << ToString(args)), ...);
    std::cout << std::endl;
}

#endif

🔹 main.cpp

#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"

int main() {
    Point2f p = MakeP2f(2.0f, 3.0f);
    Print("Point:", ToString(p));

    Vector2f v = MakeV2f(1.0f, -1.0f);
    Point2f p2 = Translate(p, v);
    Print("Translated:", ToString(p2));

    return 0;
}


