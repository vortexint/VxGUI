#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <string>
#include <cstdint>

#include <cglm/types.h>

// Forward declarations
struct GuiContext;
class Gui;
class Widget;

struct Color {
    uint32_t value;
    explicit Color(uint32_t val) : value(val) {}
};

// RAII Wrapper for GuiContext
class GuiHandle {
public:
    explicit GuiHandle(std::unique_ptr<GuiContext> context);
    ~GuiHandle();
    GuiContext* get() const;
private:
    std::unique_ptr<GuiContext> ctx;
};

enum class ButtonState {
    Normal,
    Hovered,
    Pressed
};

// Base class for all widgets
class Widget {
public:
    virtual ~Widget() = default;
    virtual void paint(GuiContext& ctx) = 0;
    virtual void update(Gui& ctx) = 0;

protected:
    vec2 position{0, 0}; // Position relative to the parent widget
    vec2 size{0, 0};     // Size of this widget in pixels
    std::vector<std::unique_ptr<Widget>> children;
};

// Gui class managing the GUI context and widgets
class Gui {
public:
    using OnSubmit = std::function<void()>;

    explicit Gui(std::unique_ptr<GuiContext> context);
    void add(std::unique_ptr<Widget> widget);
    Widget& operator[](std::size_t index);

private:
    std::vector<std::unique_ptr<Widget>> widgets;
    std::unique_ptr<GuiContext> ctx;
};

// GuiContext class handling low-level drawing operations
struct GuiContext {
    void set_fill(Color color);
    void draw_rect(const vec2& pos, const vec2& size);
};


struct ButtonProps {
    Color bg{0xff2b2e4a};
    Color fg{0xff1d1f21};
};

class Button : public Widget {
public:
    Button() = default;
    void paint(GuiContext& ctx) override;
    void update(Gui& ctx) override;

private:
    ButtonState state = ButtonState::Normal;
    ButtonProps props;
    std::string label = "Button";
};

class Container : public Widget {
public:
    void paint(GuiContext& ctx) override;
    void update(Gui& ctx) override;
    void add_widget(std::unique_ptr<Widget> widget);
};

class Graph : public Widget {
public:
    void paint(GuiContext& ctx) override;
    void update(Gui& ctx) override;
};

// RichText widget for displaying text with formatting
class RichText : public Widget {
public:
    explicit RichText(const std::string& text);
    void paint(GuiContext& ctx) override;
    void update(Gui& ctx) override;

private:
    std::string content;

};
