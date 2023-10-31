#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "iconhandler.h"

using namespace geode::prelude;

class $modify(MenuLayer) {

    bool init() {

        if (!MenuLayer::init())
            return false;
        
        auto profileMenu = this->getChildByID("profile-menu");
        auto profileBtn = profileMenu->getChildByID("profile-button");
        auto profileSpr = (CCSprite*)profileBtn->getChildByID("");
        auto customLayout = AxisLayout::create();
        auto gameManager = GameManager::sharedState();
        auto iconProfile = SimplePlayer::create(0);
        iconProfile->updatePlayerFrame(iconhandler::getFrameIcon(gameManager->getPlayerIconType()), gameManager->getPlayerIconType()),
            iconProfile->setColor(gameManager->colorForIdx(gameManager->getPlayerColor())),
            iconProfile->setSecondColor(gameManager->colorForIdx(gameManager->getPlayerColor2())),
            iconProfile->setGlowOutline(gameManager->getPlayerGlow()),
            iconProfile->setScale({1.150}),
            profileSpr->addChild(iconProfile),
            profileSpr->setDisplayFrame(iconProfile->displayFrame()),
            profileMenu->setLayout(customLayout),
            profileMenu->setPositionX(this->getChildByID("player-username")->getPositionX());

        return true;
    }
};