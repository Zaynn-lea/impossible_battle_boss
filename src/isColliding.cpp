

bool cEntity::isColliding(cEntity * other)
{
	bool vertAlign, horzAlign;

	olc::vi2d selfStart; selfEnd, compStart, compEnd;


	selfStart = this->pos + this->hitbox.topleft;
	selfEnd   = this->pos + this->hitbox.botright;
	compStart = other.getPos() + other.getHitbox().topleft;
	compEnd   = other.getPos() + other.getHitbox().botRight;

	vertAlign = max(selfStart.x, compStart.x) > min(selfEnd.x, compEnd.x);
	vertAlign = max(selfStart.y, compStart.y) > min(selfEnd.y, compEnd.y);


	return vertAlign && horzAlign;
}
