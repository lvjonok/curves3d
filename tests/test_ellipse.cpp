#include <cmath>
#include <curves/curves.h>
#include <gtest/gtest.h>

const auto almostZero = 1e-6;

TEST(EllipseTest, CurveSoundness) {
  // try to create circle with negative radius and expect error
  EXPECT_THROW(curves::Ellipse ellipse(-1.0, -2.0), std::invalid_argument);

  // try to create circle with zero radius and expect error
  EXPECT_THROW(curves::Ellipse ellipse(0.0, 2.0), std::invalid_argument);

  // try to create circle with positive radius and expect no error
  EXPECT_NO_THROW(curves::Ellipse ellipse(1.0, 2.0));
}

TEST(EllipseTest, CorrectPoint) {
  curves::Ellipse ellipse(1.0, 2.0);

  curves::Point point = ellipse.evaluate(0.0);
  EXPECT_NEAR(point.X(), 1.0, almostZero);
  EXPECT_NEAR(point.Y(), 0.0, almostZero);
  EXPECT_NEAR(point.Z(), 0.0, almostZero);

  point = ellipse.evaluate(M_PI / 2);
  EXPECT_NEAR(point.X(), 0.0, almostZero);
  EXPECT_NEAR(point.Y(), 2.0, almostZero);
  EXPECT_NEAR(point.Z(), 0.0, almostZero);

  point = ellipse.evaluate(M_PI);
  EXPECT_NEAR(point.X(), -1.0, almostZero);
  EXPECT_NEAR(point.Y(), 0.0, almostZero);
  EXPECT_NEAR(point.Z(), 0.0, almostZero);

  point = ellipse.evaluate(3 * M_PI / 2);
  EXPECT_NEAR(point.X(), 0.0, almostZero);
  EXPECT_NEAR(point.Y(), -2.0, almostZero);
  EXPECT_NEAR(point.Z(), 0.0, almostZero);
}

TEST(EllipseTest, CorrectDerivative) {
  curves::Ellipse ellipse(1.0, 2.0);

  curves::Vector3 vector = ellipse.derivative(0.0);
  EXPECT_NEAR(vector.X(), 0.0, almostZero);
  EXPECT_NEAR(vector.Y(), 2.0, almostZero);
  EXPECT_NEAR(vector.Z(), 0.0, almostZero);

  vector = ellipse.derivative(M_PI / 2);
  EXPECT_NEAR(vector.X(), -1.0, almostZero);
  EXPECT_NEAR(vector.Y(), 0.0, almostZero);
  EXPECT_NEAR(vector.Z(), 0.0, almostZero);

  vector = ellipse.derivative(M_PI);
  EXPECT_NEAR(vector.X(), 0.0, almostZero);
  EXPECT_NEAR(vector.Y(), -2.0, almostZero);
  EXPECT_NEAR(vector.Z(), 0.0, almostZero);

  vector = ellipse.derivative(3 * M_PI / 2);
  EXPECT_NEAR(vector.X(), 1.0, almostZero);
  EXPECT_NEAR(vector.Y(), 0.0, almostZero);
  EXPECT_NEAR(vector.Z(), 0.0, almostZero);
}