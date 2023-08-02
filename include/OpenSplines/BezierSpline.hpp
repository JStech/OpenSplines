#include "OpenSplines/Spline.hpp"

namespace Splines
{
template <typename Real, typename T, typename Combine>
class BezierSpline : public Spline<Real, T, Combine>
{
public:
  BezierSpline(int degree) : Spline<Real, T, Combine>::Spline(degree)
  {
  }

  BezierSpline(std::vector<T> control_points, std::vector<Real> knots)
    : Spline<Real, T, Combine>::Spline(control_points, knots)
  {
  }

  BezierSpline(int degree, std::vector<T> control_points, std::vector<Real> knots)
    : Spline<Real, T, Combine>::Spline(degree, control_points, knots)
  {
  }

  void interpolate(std::vector<T> data)
  {
  }

  void interpolate(std::vector<T> data, std::vector<Real> parameters)
  {
  }

  void fit(std::vector<T> data)
  {
  }

  void fit(std::vector<T> data, std::vector<Real> parameters)
  {
  }

  // T operator()(Real parameter) override
  // {
  //   return T();
  // }

  std::string to_string()
  {
    return "";
  }

private:
};
}  // namespace Splines
