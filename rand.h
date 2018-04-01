// Copyright 2018, Vahid Kazemi

#ifndef RAND_H_
#define RAND_H_

#include <random>

#include "./vec3.h"

template<class T>
class RandomPointInUnitSphere {
 public:
  RandomPointInUnitSphere() : uniform_dist_(-1, 1) {}

  template<class URNG>
  Vec3<T> operator()(URNG& g) {
    Vec3<T> u;
    do {
      u = Vec3<T>(uniform_dist_(g), uniform_dist_(g), uniform_dist_(g));
    } while (SquaredLength(u) >= 1.0);
    return u;
  }

 private:
  std::uniform_real_distribution<T> uniform_dist_;
};

class Random {
 public:
  static std::mt19937& Generator() {
    thread_local static std::mt19937 generator;
    return generator;
  }

  static float Uniform() {
    static std::uniform_real_distribution<float> uniform_dist(0, 1);
    return uniform_dist(Generator());
  }

  static Vec3f PointInUnitSphere() {
    static RandomPointInUnitSphere<float> sphere_dist;
    return sphere_dist(Generator());
  }
};

#endif  // RAND_H_
