# Curves 3D library

This library provides implementation of Circle, Ellipse and Helix curves in 3D space.

Task with curves is implemented in [main](main.cpp) file.

Tests are implemented in [tests](tests/) directory.

## Contents

* [Curves description](#curves-description)
  * [Circle](#circle)
  * [Ellipse](#ellipse)
  * [Helix](#helix)
* [Installation (Linux)](#installation-linux)
* [Running](#running)

## Curves description

### Circle

Circle is defined by its radius and defined only in XY-plane.

$$
f(t) = \begin{bmatrix}
r \cos(t) \\
r \sin(t) \\
0 \end{bmatrix}
$$

First derivative wrt parameter $t$ is:

$$
f'(t) = \begin{bmatrix}
-r \sin(t) \\
r \cos(t) \\
0 \end{bmatrix}
$$

### Ellipse

Ellipse is defined by its radiuses and defined only in XY-plane.

$$
f(t) = \begin{bmatrix}
a \cos(t) \\
b \sin(t) \\
0 \end{bmatrix}
$$

First derivative wrt parameter $t$ is:

$$
f'(t) = \begin{bmatrix}
-a \sin(t) \\
b \cos(t) \\
0 \end{bmatrix}
$$

### Helix

Helix is defined by its radius and step. In implementation Helix class is derived from Circle class.

$$
f(t) = \begin{bmatrix}
r \cos(t) \\
r \sin(t) \\
t * \frac{step}{2 * \pi} \end{bmatrix}
$$

First derivative wrt parameter $t$ is:

$$
f'(t) = \begin{bmatrix}
-r \sin(t) \\
r \cos(t) \\
\frac{step}{2 * \pi} \end{bmatrix}
$$

## Installation (Linux)

In order to build with tests you need to clone recursively with submodules.

Build with tests:

```bash
mkdir build && cd build
cmake ..
make
```

Without tests:

```bash
cmake -DCURVES_TESTS=OFF ..
make
```

## Running

Main task:

```bash
./curves_task
```

Tests:

```bash
./CurvesTests
```