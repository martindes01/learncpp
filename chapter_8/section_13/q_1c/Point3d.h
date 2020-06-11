#ifndef POINT3D_H
#define POINT3D_H

// forward declaration of Vector3d class
class Vector3d;

class Point3d
{
private:
  double m_x{ };
  double m_y{ };
  double m_z{ };

public:
  Point3d(double x=0.0, double y=0.0, double z=0.0) : m_x{ x }, m_y{ y }, m_z{ z } { }

  void print() const;

  // forward declaration of Point3d::moveByVector() member function
  void moveByVector(const Vector3d &v);
};

#endif
