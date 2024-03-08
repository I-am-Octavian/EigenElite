#include "test.h"
#include "raylib.h"

using std::cout, std::endl;

class App {
        PhysicsEngine* m_Engine;
        static i32 m_Fps;
    public:
        App() {
            InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TITLE");
            SetTargetFPS(m_Fps);
            m_Engine = PhysicsEngine::GetInstance();
            m_Engine->SetGravity(0, 2);
        }

        void Add(Collider* theCollider) {
            m_Engine->PushPhyObject(theCollider);
        }

        void Update() {
            while (!WindowShouldClose()) {
                m_Engine->Simulate();
                BeginDrawing();
                DrawFPS(0, 0);
                ClearBackground(BLACK);
                for (i32 i = 0; i < m_Engine->GetSize(); i++) {
                    DrawCircle((int)m_Engine->GetPhysicsObject(i)->GetPosition().GetX(),
                            (int)m_Engine->GetPhysicsObject(i)->GetPosition().GetY(), 10.0f,
                            Color{(unsigned char)(10 * (i * 10)), 0, 255, 255});
                }
                EndDrawing();
            }
            CloseWindow();
        }


};
i32 App::m_Fps = CURR_FPS;

i32 main(void)
{
    Collider a(Vec2(4, 0), Vec2(100, 100),  false, true, Shape::Type::Circle);
    Collider b(Vec2(-1, 1), Vec2(200, 100), false, true, Shape::Type::Circle);
    Collider c(Vec2(-1, 1), Vec2(300, 300), false, true, Shape::Type::Circle);
    Collider d(Vec2(-1, 1), Vec2(300, 800), false, true, Shape::Type::Circle);
    Collider e(Vec2(-1, 1), Vec2(300, 500), false, true, Shape::Type::Circle);

    App app;

    for (int i  = 0; i < 85; i++) {
        Collider* A = new Collider(Vec2(2, 2), Vec2(i * 20, i * 10), false, true,
                                    Shape::Type::Circle);
        app.Add(A);
    }
    app.Add(&a);
    app.Add(&b);
    app.Add(&c);
    app.Add(&d);
    app.Add(&e);

    app.Update();

    return 0;
}
