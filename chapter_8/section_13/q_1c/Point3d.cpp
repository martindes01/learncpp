#include "Point3d.h"

#include "Vector3d.h"

#include <iostream>

void Point3d::print() const
{
  std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}

// define Point3d::moveByVector() member function
void Point3d::moveByVector(const Vector3d &v)
{
  m_x += v.m_x;
  m_y += v.m_y;
  m_z += v.m_z;
}
