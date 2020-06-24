#include <toppra/geometric_path.hpp>
#include <toppra/geometric_path/piecewise_poly_path.hpp>
#include <toppra/toppra.hpp>
#include <toppra/parametrizer/const_accel.hpp>

#include "gtest/gtest.h"

#define TEST_PRECISION 1e-6


class ParamtrizeConstAccel : public testing::Test {
 public:
  ParamtrizeConstAccel() {
    toppra::Matrix coeff0{4, 2}, coeff1{4, 2}, coeff2{4, 2};
    coeff0 << -0.500000, -0.500000, 1.500000, 0.500000, 0.000000, 3.000000, 0.000000,
        0.000000;
    coeff1 << -0.500000, -0.500000, 0.000000, -1.000000, 1.500000, 2.500000, 1.000000,
        3.000000;
    coeff2 << -0.500000, -0.500000, -1.500000, -2.500000, 0.000000, -1.000000, 2.000000,
        4.000000;
    toppra::Matrices coefficents = {coeff0, coeff1, coeff2};
    path = std::make_shared<toppra::PiecewisePolyPath>(coefficents, std::vector<double>{0, 1, 2, 3});
  };
  std::shared_ptr<toppra::PiecewisePolyPath> path;
};


TEST_F(ParamtrizeConstAccel, Basic) {
  toppra::Vector gridpoints = toppra::Vector::LinSpaced(10, 0, 3);
  toppra::Vector vsquared = toppra::Vector::LinSpaced(10, 0.5, 1);
  auto p = toppra::parametrizer::ConstAccel(path, gridpoints, vsquared);
}