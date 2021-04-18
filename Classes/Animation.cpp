#include"Animation.h"
USING_NS_CC;

float HeroWidth = 137;
float HeroHeight = 131;

 void Aright() {
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
	 Animate* animate = Animate::create(animation);
}
 void Aleft() {
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
	 Animate* animate1 = Animate::create(animation1);
 }


