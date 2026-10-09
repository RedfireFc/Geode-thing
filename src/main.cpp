#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(AlwaysUprightInverted, PlayerObject) {
    void handleButton(PlayerButton button, bool holding, bool isPlayer1) {
        // Check if upside down and currently using Ship (m_isShip) or Wave/Dart (m_isDart)
        bool shouldInvert = this->m_isUpsideDown && (this->m_isShip || this->m_isDart);
        
        if (shouldInvert) {
            // Invert the holding state: holding makes it drop, letting go makes it hold
            holding = !holding;
        }
        
        PlayerObject::handleButton(button, holding, isPlayer1);
    }
};
