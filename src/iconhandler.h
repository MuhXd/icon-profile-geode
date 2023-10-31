#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace iconhandler {
    int getFrameIcon(IconType type) {
        auto gameManager = GameManager::sharedState();
        switch(type) {
        default: return gameManager->getPlayerFrame();
        case IconType::Ship: return gameManager->getPlayerShip();
        case IconType::Ball: return gameManager->getPlayerBall();
        case IconType::Ufo: return gameManager->getPlayerBird();
        case IconType::Wave: return gameManager->getPlayerDart();
        case IconType::Robot: return gameManager->getPlayerRobot();
        case IconType::Spider: return gameManager->getPlayerSpider();
        }
    }
}