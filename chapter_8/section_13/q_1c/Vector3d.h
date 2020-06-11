#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3d.h"

class Vector3d
{
private:
  double m_x{ };
  double m_y{ };
  double m_z{ };

public:
  Vector3d(double x=0.0, double y=0.0, double z=0.0) : m_x{ x }, m_y{ y }, m_z{ z } { }

  void print() const;

  // set Point3d::moveByVector() member function as friend of Vector3d
  // Point3d::moveByVector() member function is visible to compiler since its declaration is #included above
  friend void Point3d::moveByVector(const Vector3d &v);
};

#endif
