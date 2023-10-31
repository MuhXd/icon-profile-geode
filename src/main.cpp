#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <UIBuilder.hpp>

using namespace geode::prelude;

int getFrameIcon(IconType type) {
    auto gManager = GameManager::sharedState();
    switch(type) {
        default: return gManager->getPlayerFrame();
        case IconType::Ship: return gManager->getPlayerShip();
        case IconType::Ball: return gManager->getPlayerBall();
        case IconType::Ufo: return gManager->getPlayerBird();
        case IconType::Wave: return gManager->getPlayerDart();
        case IconType::Robot: return gManager->getPlayerRobot();
        case IconType::Spider: return gManager->getPlayerSpider();
    }
}

class $modify(MenuLayer) {

    bool init() {
        if (!MenuLayer::init())
            return false;

        auto gManager = GameManager::sharedState();

        auto profMenu = Build(this)
            .intoChildByID<CCMenu>("profile-menu")
            .layout(AxisLayout::create())
            .posX(this->getChildByID("player-username")->getPositionX());

        SimplePlayer* playerIcon;
        Build<SimplePlayer>::create(0)
            .store(playerIcon)
            .color(gManager->colorForIdx(gManager->getPlayerColor()))
            .secondColor(gManager->colorForIdx(gManager->getPlayerColor2()))
            .glowOutline(gManager->getPlayerGlow())
            .playerFrame(
                getFrameIcon(gManager->getPlayerIconType()),
                gManager->getPlayerIconType()
            )
            .scale(1.15)
            .intoNewParent(profMenu.intoChildByID<CCNode>("profile-button").intoChild<CCSprite>(0))
            .displayFrame(playerIcon->displayFrame());

        return true;
    }
};
