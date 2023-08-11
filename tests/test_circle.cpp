#include <cmath>
#include <curves/curves.h>
#include <gtest/gtest.h>

const auto almostZero = 1e-6;

TEST(CircleTest, CurveSoundness) {
  // try to create circle with negative radius and expect error
  EXPECT_THROW(curves::Circle circle(-1.0), std::invalid_argument);

  // try to create circle with zero radius and expect error
  EXPECT_THROW(curves::Circle circle(0.0), std::invalid_argument);

  // try to create circle with positive radius and expect no error
  EXPECT_NO_THROW(curves::Circle circle(1.0));
}

TEST(CircleTest, CorrectPoint) {
  curves::Circle circle(1.0);

  curves::Point point = circle.evaluate(0.0);
  EXPECT_NEAR(point.X(), 1.0, almostZero);
  EXPECT_NEAR(point.Y(), 0.0, almostZero);
  EXPECT_NEAR(point.Z(), 0.0, almostZero);

  point = circle.evaluate(M_PI / 2);
  EXPECT_NEAR(point.X(), 0.0, almostZero);
  EXPECT_NEAR(point.Y(), 1.0, almostZero);
  EXPECT_NEAR(point.Z(), 0.0, almostZero);

  point = circle.evaluate(M_PI);
  EXPECT_NEAR(point.X(), -1.0, almostZero);
  EXPECT_NEAR(point.Y(), 0.0, almostZero);
  EXPECT_NEAR(point.Z(), 0.0, almostZero);

  point = circle.evaluate(3 * M_PI / 2);
  EXPECT_NEAR(point.X(), 0.0, almostZero);
  EXPECT_NEAR(point.Y(), -1.0, almostZero);
  EXPECT_NEAR(point.Z(), 0.0, almostZero);
}

TEST(CircleTest, CorrectDerivative) {
  curves::Circle circle(1.0);

  curves::Vector3 vector = circle.derivative(0.0);
  EXPECT_NEAR(vector.X(), 0.0, almostZero);
  EXPECT_NEAR(vector.Y(), 1.0, almostZero);
  EXPECT_NEAR(vector.Z(), 0.0, almostZero);

  vector = circle.derivative(M_PI / 2);
  EXPECT_NEAR(vector.X(), -1.0, almostZero);
  EXPECT_NEAR(vector.Y(), 0.0, almostZero);
  EXPECT_NEAR(vector.Z(), 0.0, almostZero);

  vector = circle.derivative(M_PI);
  EXPECT_NEAR(vector.X(), 0.0, almostZero);
  EXPECT_NEAR(vector.Y(), -1.0, almostZero);
  EXPECT_NEAR(vector.Z(), 0.0, almostZero);

  vector = circle.derivative(3 * M_PI / 2);
  EXPECT_NEAR(vector.X(), 1.0, almostZero);
  EXPECT_NEAR(vector.Y(), 0.0, almostZero);
  EXPECT_NEAR(vector.Z(), 0.0, almostZero);
}