#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(AlwaysUprightInverted, PlayerObject) {
    // Suppress or fix visual rotation if needed, or handle input inversion:
    void pushButton(PlayerButton button) {
        // Check if upside down and currently using Ship (m_isShip) or Dart/Wave (m_isDart)
        bool shouldInvert = this->m_isUpsideDown && (this->m_isShip || this->m_isDart);
        
        if (shouldInvert) {
            // Invert input: treat a press as a release so holding drops and letting go holds
            PlayerObject::releaseButton(button);
            return;
        }
        
        PlayerObject::pushButton(button);
    }

    void releaseButton(PlayerButton button) {
        bool shouldInvert = this->m_isUpsideDown && (this->m_isShip || this->m_isDart);
        
        if (shouldInvert) {
            // Invert input: treat a release as a press
            PlayerObject::pushButton(button);
            return;
        }
        
        PlayerObject::releaseButton(button);
    }
};
