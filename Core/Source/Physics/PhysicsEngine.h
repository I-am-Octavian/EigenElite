#pragma once

#include "Linear/Vector.h"
#include "Physics/Vec2.h"
#include "Physics/PhysicsObject.h"

class PhysicsEngine {
    private:
        Vec2 m_Gravity;
        Vector<PhysicsObject*> m_Objs;
        PhysicsEngine();

    public:

        void SetGravity(f32, f32);
        inline Vec2 GetGravity() {return m_Gravity;}

        static PhysicsEngine* GetInstance();

        PhysicsObject* GetPhysicsObject(i32);
        void PushPhyObject(PhysicsObject*);
        PhysicsObject* PopPhyObject();

        void UpdateObjects();
        void Simulate(i32);

    private:
        static PhysicsEngine* m_Instance;
};

PhysicsEngine* PhysicsEngine::m_Instance = nullptr;

