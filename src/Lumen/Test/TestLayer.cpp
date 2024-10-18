#include "Lumen/Test/TestLayer.hpp"
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
}

void TestLayer::OnUpdate()
{
}

void TestLayer::OnDraw()
{
}

} // namespace Lumen