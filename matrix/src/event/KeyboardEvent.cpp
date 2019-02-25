#include "matrix/src/event/KeyboardEvent.h"

#include <string>

namespace Matrix {

    void KeyboardEvent::printEventType() const {
        if (event == 2)
            INFO("Event: DefaultKeyboard");
    }

    void KeyboardButtonPressed::printEventType() const {
        if (event == 4) 
            INFO("Event: KeyboardButtonPressed: " + std::to_string(m_KeyCode));
    }

    void KeyboardButtonReleased::printEventType() const {
        if (event == 5)
            INFO("Event: KeyboardButtonReleased: " + std::to_string(m_KeyCode));
    }
}