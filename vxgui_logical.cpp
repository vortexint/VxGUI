
#include "vxgui.hpp"

GuiHandle::GuiHandle(std::unique_ptr<GuiContext> context) : ctx(std::move(context)) {}

GuiHandle::~GuiHandle() = default;

GuiContext* GuiHandle::get() const { 
    return ctx.get(); 
}

Gui::Gui(std::unique_ptr<GuiContext> context) : ctx(std::move(context)) {}

void Gui::add(std::unique_ptr<Widget> widget) { 
    widgets.emplace_back(std::move(widget)); 
}

Widget& Gui::operator[](std::size_t index) { 
    return *widgets[index]; 
}

void GuiContext::set_fill(Color color) {}

void GuiContext::draw_rect(const vec2& pos, const vec2& size) {}

void Button::paint(GuiContext& ctx) {}

void Button::update(Gui& ctx) {}

void Container::paint(GuiContext& ctx) {}

void Container::update(Gui& ctx) {}

void Container::add_widget(std::unique_ptr<Widget> widget) { 
    children.emplace_back(std::move(widget)); 
}

void Graph::paint(GuiContext& ctx) {}

void Graph::update(Gui& ctx) {}

RichText::RichText(const std::string& text) : content(text) {}

void RichText::paint(GuiContext& ctx) {}

void RichText::update(Gui& ctx) {}
