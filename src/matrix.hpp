#include "vector.hpp"

template <typename T> class Matrix4 {
  public:
    Matrix4() {}
    ~Matrix4() {}

  private:
    Vector4<T> x;
    Vector4<T> y;
    Vector4<T> z;
    Vector4<T> w;
};
