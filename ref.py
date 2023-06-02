#!/usr/bin/env python3
import numpy as np
from math import sin, cos, acos

class Quaternion:
    def __init__(self, w, x, y, z):
        self.q = np.array([w, x, y, z])

    def w(self):
        return self.q[0]

    def x(self):
        return self.q[1]

    def y(self):
        return self.q[2]

    def z(self):
        return self.q[3]

    def __mul__(self, other):
        # i = j*k, j = k*i, k = i*j
        return Quaternion(
                self.w() * other.w() - self.x() * other.x() - self.y() * other.y() - self.z() * other.z(),
                self.w() * other.x() + self.x() * other.w() + self.y() * other.z() - self.z() * other.y(),
                self.w() * other.y() + self.y() * other.w() + self.z() * other.x() - self.x() * other.z(),
                self.w() * other.z() + self.z() * other.w() + self.x() * other.y() - self.y() * other.x(),
                )

    @staticmethod
    def log(q):
        alpha = acos(q.w())
        return Quaternion(0, alpha*q.x()/sin(alpha), alpha*q.y()/sin(alpha), alpha*q.z()/sin(alpha))

    @staticmethod
    def exp(q):
        alpha = np.linalg.norm(q.q[1:])
        n = q.q[1:] / alpha
        return Quaternion(cos(alpha), sin(alpha)*n[0], sin(alpha)*n[1], sin(alpha)*n[2])

    @staticmethod
    def interp(q0, q1, t):
        pass

q = Quaternion(0.5, 0.5, 0.5, 0.5)

print(Quaternion.log(q).q)
print(Quaternion.exp(Quaternion.log(q)).q)
print((q * q).q)
