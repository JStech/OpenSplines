#include <Eigen/Dense>

namespace Splines {
template <typename Real, typename T, typename Combine>
class Spline {
    public:
        Spline(std::vector<T> control_points, std::vector<Real> knots) :
            control_points_(control_points),
            knots_(knots) {}
        virtual void interpolate(std::vector<T> data) = 0;
        virtual void interpolate(std::vector<T> data, std::vector<Real> parameters) = 0;
        virtual void fit(std::vector<T> data) = 0;
        virtual void fit(std::vector<T> data, std::vector<Real> parameters) = 0;
        virtual T operator()(Real parameter) const = 0;
        virtual std::string to_string() = 0;

    private:
        std::vector<Real> knots_;
        std::vector<T> control_points_;

}
}

// vim: filetype=cpp expandtab shiftwidth=4 autoindent smartindent smarttab tabstop=8 softtabstop=4
