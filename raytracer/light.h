//
//  Framework for a raytracer
//  File: light.h
//
//  Created for the Computer Science course "Introduction Computer Graphics"
//  taught at the University of Groningen by Tobias Isenberg.
//
//  Authors:
//    Maarten Everts
//    Jasper van de Gronde
//    Roan Kattouw
//    Jan Paul Posma
//
//  This framework is inspired by and uses code of the raytracer framework of 
//  Bert Freudenberg that can be found at
//  http://isgwww.cs.uni-magdeburg.de/graphik/lehre/cg2/projekt/rtprojekt.html 
//

#ifndef LIGHT_H_PG2BAJRA
#define LIGHT_H_PG2BAJRA

#include <iostream>
#include <limits>
#include "triple.h"

class Light
{
public:
	Light(Point pos,Color c) : position(pos), color(c)
	{ }

	Point position;
	Color color;
};

class Ray
{
public:
	Point O;
	Vector D;

	Ray(const Point &from, const Vector &dir)
		: O(from)
	{ D = dir.normalized(); }

	Point at(double t) const
	{ return O + t*D; }

};

class Hit
{
public:
	double t;
	Vector N;

	Hit(const double t, const Vector &normal)
		: t(t), N(normal)
	{ }
	
	Hit() { Hit(std::numeric_limits<double>::infinity(),Vector()); }

	static const Hit NO_HIT();
};

#endif /* end of include guard: LIGHT_H_PG2BAJRA */
