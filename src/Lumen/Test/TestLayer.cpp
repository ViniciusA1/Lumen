#include "Lumen/Test/TestLayer.hpp"
#include "Lumen/Scene/Entity/System/MovementSystem.hpp"
#include "Lumen/Scene/Entity/System/SpriteRendererSystem.hpp"
#include "Lumen/Scene/SceneManager.hpp"
#include <iostream>

namespace Lumen
{

TestLayer::TestLayer() : Layer("TestLayer", true)
{
    KeyboardListener keyboardListener;
    keyboardListener.BindPressedAction(KeyCode::W,
                                       {"Move W", []() { std::cout << "W pressed\n"; }});
    keyboardListener.BindPressedAction(KeyCode::A,
                                       {"Move A", []() { std::cout << "A pressed\n"; }});
    keyboardListener.BindPressedAction(KeyCode::S,
                                       {"Move S", []() { std::cout << "S pressed\n"; }});
    keyboardListener.BindPressedAction(KeyCode::D,
                                       {"Move D", []() { std::cout << "D pressed\n"; }});
    AddKeyboardListener(keyboardListener);

    MouseListener mouseListener;
    mouseListener.BindButtonPressedAction(MouseCode::ButtonLeft,
                                          {"Left Button", [](int x, int y) {
                                               std::cout << "Left Button pressed: (" << x
                                                         << ", " << y << ")\n";
                                           }});
    AddMouseListener(mouseListener);

    m_TestScene = SceneManager::CreateScene("TestScene");
    World &world = m_TestScene->GetWorld();
    world.AddSystem<MovementSystem>();
    world.AddSystem<SpriteRendererSystem>();
    EntityManager &entityManager = world.GetEntityManager();
    Entity entity = entityManager.CreateEntity();
    entityManager.AddComponent<SpriteRendererComponent>(entity);
    entityManager.AddComponent<VelocityComponent>(
        entity, VelocityComponent({15.0f, 15.0f, 0.0f}));
}

void TestLayer::OnUpdate()
{
    m_TestScene->OnUpdate();
}

void TestLayer::OnDraw()
{
}

} // namespace Lumen