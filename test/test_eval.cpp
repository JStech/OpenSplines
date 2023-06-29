// #include <OpenSplines/Spline>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <iostream>

int main(int argc, char* argv[])
{
  constexpr int num_segments = 3;
  Eigen::Matrix3Xd control_pts(3, 2 * num_segments + 2);
  control_pts << 0., 3., 6., 4., 5., 7., 8., 8., 0., -2., -3., -4., -4., -2., 0., 1., 0., 4., 5., 2., 3., 4., 6., 5.;
  Eigen::RowVectorXd knots(num_segments + 1);
  knots << 0., 1., 2., 3.;

  constexpr int num_query_params = 61;
  Eigen::VectorXd query_params(num_query_params);
  query_params = Eigen::VectorXd::LinSpaced(num_query_params, knots[0], knots[3]);

  Eigen::Matrix4d B;
  B << 1, 0, 0, 0, -3, 3, 0, 0, 3, -6, 3, 0, -1, 3, -3, 1;

  Eigen::SparseMatrix<double> r(num_query_params, 4 * num_segments);
  for (int i = 0; i < num_query_params; ++i)
  {
    int ipart = std::floor(query_params[i]);
    double fpart = query_params[i] - ipart;
    if (ipart >= num_segments)
    {
      ipart -= (ipart - num_segments) + 1;
      fpart = query_params[i] - ipart;
    }
    r.insert(i, ipart * 4 + 0) = 1;
    r.insert(i, ipart * 4 + 1) = fpart;
    r.insert(i, ipart * 4 + 2) = fpart * fpart;
    r.insert(i, ipart * 4 + 3) = fpart * fpart * fpart;
  }

  Eigen::Matrix<double, 4 * num_segments, 4 * num_segments> C;
  C.setZero();
  for (int i = 0; i < num_segments; ++i)
  {
    // could be a tensor product
    C.block<4, 4>(4 * i, 4 * i) = B;
  }

  // calculate implied control points
  Eigen::Matrix<double, 4, 4> d;
  d << 0, 1, 0, 0, -1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;

  Eigen::Matrix<double, 4 * num_segments, 2 * num_segments + 2> D;
  D.setZero();
  D.topLeftCorner<4, 4>() = Eigen::Matrix4d::Identity();
  for (int i = 0; i < num_segments - 1; ++i)
  {
    D.block<4, 4>(4 * i + 4, 2 * i + 2) = d;
  }

  Eigen::Matrix3Xd all_cps = (D * control_pts.transpose()).transpose();

  Eigen::Matrix3Xd interpolated_pts = (r * C * all_cps.transpose()).transpose();
}

// vim: filetype=cpp expandtab shiftwidth=4 autoindent smartindent smarttab tabstop=8 softtabstop=4
