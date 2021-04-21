#include"Anime.h"
USING_NS_CC;

float HeroWidth = 137;
float HeroHeight = 131;

cocos2d::Animation* Anim::walkRight() {
	 Vector<SpriteFrame*> animRightWalk;
	 animRightWalk.reserve(8);
	 animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(1, 180, HeroWidth, HeroHeight)));
	 animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(150, 180, HeroWidth, HeroHeight)));
	 animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(305, 180, HeroWidth, HeroHeight)));
	 animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(460, 180, HeroWidth, HeroHeight)));
	 animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(613, 180, HeroWidth, HeroHeight)));
	 animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(768, 180, HeroWidth, HeroHeight)));
	 animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(920, 180, HeroWidth, HeroHeight)));
	 animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(1077, 180, HeroWidth, HeroHeight)));
	 Animation* animation = Animation::createWithSpriteFrames(animRightWalk, 0.05f);
	 return animation;
}
cocos2d::Animation* Anim::walkLeft() {
	 Vector<SpriteFrame*> animLeftWalk;
	 animLeftWalk.reserve(8);
	 animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(19, 1412, HeroWidth, HeroHeight)));
	 animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(172, 1412, HeroWidth, HeroHeight)));
	 animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(324, 1412, HeroWidth, HeroHeight)));
	 animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(478, 1412, HeroWidth, HeroHeight)));
	 animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(634, 1412, HeroWidth, HeroHeight)));
	 animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(787, 1412, HeroWidth, HeroHeight)));
	 animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(941, 1412, HeroWidth, HeroHeight)));
	 animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(1095, 1412, HeroWidth, HeroHeight)));
	 Animation* animation1 = Animation::createWithSpriteFrames(animLeftWalk, 0.05f);
	 return animation1;
 }
cocos2d::Animation* Anim::noLeftPunch()
 {
	Vector<SpriteFrame*> noLeftpunch;
	noLeftpunch.reserve(3);
	noLeftpunch.pushBack(SpriteFrame::create("Adv.png", Rect(1087, 1727, HeroWidth, HeroHeight)));
	noLeftpunch.pushBack(SpriteFrame::create("Adv.png", Rect(1244, 1727, HeroWidth, HeroHeight)));
	noLeftpunch.pushBack(SpriteFrame::create("Adv.png", Rect(1398, 1727, HeroWidth, HeroHeight)));
	Animation* noLeftpunchanimation = Animation::createWithSpriteFrames(noLeftpunch, 0.15f);
	return noLeftpunchanimation;
 }

cocos2d::Animation* Anim::noRightPunch()
 {
	 Vector<SpriteFrame*> nopunch;
	 nopunch.reserve(3);
	 nopunch.pushBack(SpriteFrame::create("Adv.png", Rect(1077, 344, HeroWidth, HeroHeight)));
	 nopunch.pushBack(SpriteFrame::create("Adv.png", Rect(1228, 344, HeroWidth, HeroHeight)));
	 nopunch.pushBack(SpriteFrame::create("Adv.png", Rect(1384, 344, HeroWidth, HeroHeight)));
	 Animation* nopunchanimation = Animation::createWithSpriteFrames(nopunch, 0.15f);
	 return nopunchanimation;
 }

cocos2d::Animation* Anim::rightPunch()
 {
	 Vector<SpriteFrame*> punch;
	 punch.reserve(7);//137.131
	 punch.pushBack(SpriteFrame::create("Adv.png", Rect(3, 344, HeroWidth, HeroHeight)));
	 punch.pushBack(SpriteFrame::create("Adv.png", Rect(165, 344, HeroWidth, HeroHeight)));
	 punch.pushBack(SpriteFrame::create("Adv.png", Rect(327, 344, HeroWidth, HeroHeight)));
	 punch.pushBack(SpriteFrame::create("Adv.png", Rect(475, 344, HeroWidth, HeroHeight)));
	 punch.pushBack(SpriteFrame::create("Adv.png", Rect(631, 344, HeroWidth, HeroHeight)));
	 punch.pushBack(SpriteFrame::create("Adv.png", Rect(785, 344, HeroWidth, HeroHeight)));
	 punch.pushBack(SpriteFrame::create("Adv.png", Rect(935, 344, HeroWidth, HeroHeight)));
	 Animation* punchanimation = Animation::createWithSpriteFrames(punch, 0.15f);
	 return punchanimation;
 }

cocos2d::Animation* Anim::leftPunch()
 {
	 Vector<SpriteFrame*> punchLeft;
	 punchLeft.reserve(7);
	 punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(18, 1571, HeroWidth, HeroHeight)));
	 punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(159, 1571, HeroWidth, HeroHeight)));
	 punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(309, 1571, HeroWidth, HeroHeight)));
	 punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(467, 1571, HeroWidth, HeroHeight)));
	 punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(620, 1571, HeroWidth, HeroHeight)));
	 punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(772, 1571, HeroWidth, HeroHeight)));
	 punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(929, 1571, HeroWidth, HeroHeight)));
	 Animation* punchLeftanimation = Animation::createWithSpriteFrames(punchLeft, 0.15f);
	 return punchLeftanimation;
 }

cocos2d::Animation* Anim::leftPunchi()
 {
	 Vector<SpriteFrame*> punchiLeft;
	 punchiLeft.reserve(13);
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(0, 1727, HeroWidth, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(152, 1727, HeroWidth - 10, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(316, 1727, HeroWidth - 10, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(470, 1727, HeroWidth - 10, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(623, 1727, HeroWidth - 10, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(774, 1727, HeroWidth - 10, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(18, 1882, HeroWidth, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(169, 1882, HeroWidth, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(297, 1882, HeroWidth, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(450, 1882, HeroWidth, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(604, 1882, HeroWidth, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(750, 1882, HeroWidth, HeroHeight)));
	 punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(922, 1882, HeroWidth, HeroHeight)));
	 Animation* punchiLeftanimation = Animation::createWithSpriteFrames(punchiLeft, 0.15f);
	 return punchiLeftanimation;
 }

cocos2d::Animation* Anim::rightPunchi()
 {
	 Vector<SpriteFrame*> punchi;
	 punchi.reserve(13);
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(18, 501, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(158, 501, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(305, 501, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(455, 501, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(610, 501, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(766, 501, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(0, 653, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(150, 653, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(332, 653, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(486, 653, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(640, 653, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(794, 653, HeroWidth, HeroHeight)));
	 punchi.pushBack(SpriteFrame::create("Adv.png", Rect(934, 653, HeroWidth, HeroHeight)));
	 Animation* punchianimation = Animation::createWithSpriteFrames(punchi, 0.15f);
	 return punchianimation;
 }

cocos2d::Animation* Anim::rightJump()
 {
	 Vector<SpriteFrame*> animRightJump;
	 animRightJump.reserve(7);
	 animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(3, 801, HeroWidth, HeroHeight)));
	 animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(152, 801, HeroWidth, HeroHeight)));
	 animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(304, 801, HeroWidth, HeroHeight)));
	 animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(594, 801, HeroWidth, HeroHeight)));
	 animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(613, 801, HeroWidth, HeroHeight)));
	 animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(765, 801, HeroWidth, HeroHeight)));
	 animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(1, 33, HeroWidth, HeroHeight)));
	 Animation* Jumpanimation = Animation::createWithSpriteFrames(animRightJump, 0.15f);
	 return Jumpanimation;
 }

cocos2d::Animation* Anim::leftJump()
 {
	 Vector<SpriteFrame*> animLeftJump;
	 animLeftJump.reserve(7);
	 animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(18, 2031, HeroWidth, HeroHeight)));
	 animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(173, 2031, HeroWidth, HeroHeight)));
	 animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(325, 2031, HeroWidth, HeroHeight)));
	 animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(474, 2031, HeroWidth, HeroHeight)));
	 animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(632, 2031, HeroWidth, HeroHeight)));
	 animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(786, 2031, HeroWidth, HeroHeight)));
	 animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(18, 1264, HeroWidth, HeroHeight)));
	 Animation* JumpLeftanimation = Animation::createWithSpriteFrames(animLeftJump, 0.15f);
	 return JumpLeftanimation;
 }