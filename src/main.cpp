#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
    void pushButton(PlayerButton p0) {
        // When upside down and playing as Ship or Wave, invert push to act as a release
        if (m_isUpsideDown && (m_isShip || m_isDart)) {
            PlayerObject::releaseButton(p0);
            return;
        }
        PlayerObject::pushButton(p0);
    }

    void releaseButton(PlayerButton p0) {
        // When upside down and playing as Ship or Wave, invert release to act as a hold (push)
        if (m_isUpsideDown && (m_isShip || m_isDart)) {
            PlayerObject::pushButton(p0);
            return;
        }
        PlayerObject::releaseButton(p0);
    }
};
