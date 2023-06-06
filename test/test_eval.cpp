//#include <OpenSplines/Spline>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <iostream>

int main(int argc, char* argv[]) {
    constexpr int num_segments = 3;
    Eigen::Matrix3Xd control_pts(3, 2*num_segments+2);
    control_pts <<  0.,  3.,  6.,  4.,  5.,  7.,  8.,  8.,
                    0., -2., -3., -4., -4., -2.,  0.,  1.,
                    0.,  4.,  5.,  2.,  3.,  4.,  6.,  5.;
    Eigen::RowVectorXd knots(num_segments+1);
    knots << 0., 1., 2., 3.;

    constexpr int num_query_params = 61;
    Eigen::VectorXd query_params(num_query_params);
    query_params = Eigen::VectorXd::LinSpaced(num_query_params, knots[0], knots[3]);

    Eigen::Matrix4d B;
    B <<  1,  0,  0,  0,
         -3,  3,  0,  0,
          3, -6,  3,  0,
         -1,  3, -3,  1;
    
    Eigen::SparseMatrix<double> r;
    for (int i = 0; i < num_query_params; ++i) {
        std::cout << query_params[i] << "\n";
    }

}

// vim: filetype=cpp expandtab shiftwidth=4 autoindent smartindent smarttab tabstop=8 softtabstop=4
