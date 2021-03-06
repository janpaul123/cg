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
#include "object.h"
#include "ray.h"
#include "sphere.h"
#include "hit.h"

class Light : public Object
{
public:
	Light(Point pos, Color c, double r);

	Point position;
	Color color;
	
	virtual ~Light() { delete boundingSphere; }
	
	Sphere * boundingSphere;

	virtual Hit intersect(const Ray &ray, bool closest, double maxT);
	virtual Point getRotationCenter() { return position; }
};

#endif /* end of include guard: LIGHT_H_PG2BAJRA */
