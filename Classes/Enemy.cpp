#include "Enemy.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "Anime.h"
#include "Scene2.h"

USING_NS_CC;
//class Enemy
//{
//
//
//};


void Enemy::enemyPhysics(cocos2d::Sprite* enemySprite) {
	auto spriteBody = PhysicsBody::createBox(enemySprite->getContentSize() / 1.5, PhysicsMaterial(0, 0, 0));
	
	enemySprite->setPhysicsBody(spriteBody);
	spriteBody->setCollisionBitmask(2);
	spriteBody->setContactTestBitmask(true);
	spriteBody->setDynamic(false);
	
}
void Enemy::enemyAttack(cocos2d::Sprite* enemySprite) {
	
}