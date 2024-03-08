#pragma once

#include "defines.h"

#include "Linear/Matrix.h"
#include "Linear/Vector.h"

#include "Physics/PhysicsEngine.h"
#include "Physics/PhysicsObject.h"
#include "Physics/Collider.h"
#include "Physics/Shape.h"
#include "Physics/Vec2.h"

using std::cout, std::endl;

bool TestSelfCollision() {
    cout << "Self Collision\n";
    Collider a(Vec2(-1, 1), Vec2(300, 500), false, true, Shape::Type::Circle);
    Collider b(Vec2(-1, 1), Vec2(300, 600), false, true, Shape::Type::Circle);

    if (!a.Intersects(b)) {
        return true;
    }

    return false;
}

bool TestCollisionSetVelocity() {
    cout << "Collision set Velocity\n";
    Collider a(Vec2(-1, 1), Vec2(300, 500), false, true, Shape::Type::Circle);
    Collider b(Vec2(-2, 1), Vec2(300, 600), false, true, Shape::Type::Circle);

    Collider::ResolveCollision(a, b);
    if (a.GetVelocity() != Vec2(-1.0, 1.0)) {
        return true;
    }

    return false;
}

bool TestCollisionDist() {
    cout << "Collision Dist \n";
    Collider a(Vec2(-1, 1), Vec2(300, 500), false, true, Shape::Type::Circle);
    Collider b(Vec2(-2, 1), Vec2(300, 500), false, true, Shape::Type::Circle);

    if (a.Intersects(b)) {
        return true;
    }
    return false;
}

bool TestGravity() {
    Collider a(Vec2(-1, 1), Vec2(300, 500), true, true, Shape::Type::Circle);
    PhysicsEngine* engine = PhysicsEngine::GetInstance();


    engine->PushPhyObject(&a);
    engine->UpdateObjects();

    if (a.GetVelocity() == Vec2(-1, 1) + engine->GetGravity()) {
        return true;
    }
    return false;
}

bool TestMatrixColumn() {
    cout << "Test Matrix Column\n";
    Cybug::Matrix<f32> mat1(2, 2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;
    Vector<f32> vec = mat1.GetColumn(0);

    if (vec[0] == 1) {
        return true;
    }

    return false;
}

bool TestMatrixTrace() {
    cout << "Test Trace\n";
    Cybug::Matrix<f32> mat1(2, 2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    i64 trace = mat1.Trace();

    if (trace != 5) {
        return true;
    }

    return false;
}

bool TestVectorLast() {
    cout << "Vector Last\n";
    Vector<f32> vec;
    vec.PushBack(1);
    vec.PushBack(2);
    vec.PushBack(3);

    if (vec.Last()) {
        return true;
    }
    return false;
}

bool TestVectorPushBack() {
    cout << "Vector PushBack\n";
    Vector<f32> vec;
    vec.PushBack(1);

    if (vec.Last()) {
        return true;
    }
    return false;
}

bool TestDefinesABS() {
    cout << "ABS\n";
    i32 x = -1;

    if (ABS(x)) {
        return true;
    }
    return false;
}
