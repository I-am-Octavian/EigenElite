# BugAndFix

To configure the project, just run the relevant [setup](Setup) file

# Coding conventions
Functions - CapitalCamelCase
Class - CapitalCamelCase
private member variables - m_Variables
static variables - s_Variables
function parameters - theVariable
global variables - CAPTIAL
const global variables - CAPTIAL
macro - CAPITAL (except) data type
variable - aVariable


# Structure
## Utils
### Macros
- max(a, b)
- min(a, b)
- negate(a)
- inverseSqrt(a)
- square(a)

### functions
- pow(a, b)

## Classes

class Matrix\<row, column, dataType\>
member data
- dataType\[row][column]

member function
- print()
- getRow(int)
- getColumn(int)
- operator+(Matrix)
- operator-(Matrix)
- operator\*(Matrix)
- operator\*(int)
- operator=(Matrix)
- operator==(Matrix)
- operator\[]\[](int, int)
- transpose
- trace // sum of diagonals
- inverse
- determinant
- rank
- norm
- eigenValues
- vector_product(Vector)

--------------------------------------------------

class Transform
member function
// will specialize these functions only for matrices but will call them for vectors
// also for errors
- scale(\<dataType>, \<dataType>) // potential error dataType should be compatible
- rotate(\<dataType>, \<dataType>)
- translate(\<dataType>, \<dataType>)

--------------------------------------------------

class Vector\<data, dataTypes\>
member data
- dataType[data]

member functions
- print
- operator+(Vector)
- operator-(Vector)
- operator=(Vector)
- operator==(Vector)
- operator\[](int)
- push_back()
- emplace_back()
- reserve()
- getSize()


------------------------------------------
specialized in vec2
- dot(Vector)
- cross(Vector)
- magnitude
- distance(Vector)
- emplace(...)

--------------------------------------------------
Vector2


--------------------------------------------------
PHYSICS
--------------------------------------------------
class PhysicsObject: abstract
member data
position: vec2
velocity: vec2

member functions
set velocity
set position
update(Time t)

--------------------------------------------------

class PhysicsEngine
member data:
gravity: Vec2
Vector physicsObjs

member functions
set gravity
add physicsObjs
simulate(Time t)

--------------------------------------------------

class Collider: PhysicsObject
member data
Shape obj;

--------------------------------------------------
class Shape
member data
type

member function
get type()

--------------------------------------------------
enum Shape {
- ...
- ...
}

# Potential Errors

- if wrong_statements {} no else statements
- incorrect placement of \#error
- for loop i = 0 to i <= n will cause segmentation fault

# BUGS
## runtime
1. [X] Collider.cpp | 12 | 2 -- jiggling effect of balls since self colliding
2. [X] Collider.cpp | 33 | 3 -- pass through no collision
3. [X] Collider.cpp | 52 | 1 -- pass through no collision
4. [X] PhysicsEngine.cpp | 41 | 3 -- Subject to change - balls to go to bottom
5. [X] PhysicsEngine.cpp | 55 | 1 -- no balls will appear
6. [X] PhysicsEngine.cpp | 66 | 1 -- only one ball appears on screen
7. [X] PhysicsEngine.cpp | 62 | 3 -- no balls will appear
8. [X] PhysicsEngine.cpp | 54 | 3 -- no changes
9. [X] Matrix.cpp | 88 | 1 -- becaues of warning -- no change
10. [X] Matrix.cpp | 69 | 1 -- no change, should be in test file
10. [X] Vector.cpp | 141 | 1 -- no change, should be in test file
10. [X] Vector.cpp | 109 | 1 -- segmentation caused
11. [X] defines.h | 28 | 2 -- no boundary condition
### Potential Runtime
1. Vec2 | 79 | Preventing self assignment
## compile
Vector new delete 3
Matrix Template function 2
implementation template 3
singleton 2-3
collider static 1
public turn to private 1
return type different 1
restitution declared in h and cpp 2
utility
