#include <cmath>
#include <curves/curves.h>
#include <gtest/gtest.h>

const auto almostZero = 1e-6;

TEST(HelixTest, CurveSoundness) {
  // try to create helix with negative radius and expect error
  EXPECT_THROW(curves::Helix helix(-1.0, 0.0), std::invalid_argument);

  // try to create circle with negative step and expect error
  EXPECT_THROW(curves::Helix helix(1.0, -2.0), std::invalid_argument);

  // try to create helix with positive radius and step and expect no error
  EXPECT_NO_THROW(curves::Helix ellipse(1.0, 2.0));
}

TEST(HelixTest, HeightChange) {
  // test that z position of point will change by step after 2pi rotation
  auto step = 2.0;
  curves::Helix helix(1.0, step);

  auto point = helix.evaluate(0.0);
  EXPECT_NEAR(point.Z(), 0.0, almostZero);

  auto point2 = helix.evaluate(2 * M_PI);
  EXPECT_NEAR(point2.Z(), step, almostZero);
}

TEST(HelixTest, DerivativeDirection) {
  // test that z component of helix derivative is equal to step / 2pi
  auto step = 2.0;
  curves::Helix helix(1.0, step);

  auto vector = helix.derivative(0.0);
  EXPECT_NEAR(vector.Z(), step / (2 * M_PI), almostZero);
}