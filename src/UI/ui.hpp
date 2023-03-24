#include "ftxui/component/component.hpp"

using namespace ftxui;

class UI : public ComponentBase {
    public:
        UI() = default;
        Component RenderInstallerUI();
};