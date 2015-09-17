#ifndef __COORDSYSTEM__
#define __COORDSYSTEM__
#include "GameMainHeader.h"
#include "SingleInstance.h"
#include "Vec.h"


enum CoordTypes
{
	LEFT_HAND_COORD,
	RIGHT_HAND_COORD
};

#define _coordSystem				CoordSystem::getInstance()

class CoordSystem: public SingleInstance<CoordSystem>{
	DEFINE_PRIVATE_INSTANCE(CoordSystem);
public:
	void init();
	void setCoordModel(CoordTypes coord_type);
	CoordTypes getCoordType() const;


public:
//左右手坐标系转换
	Vec2 RightToLeft(const Vec2& point) const;
	Vec2 LeftToRight(const Vec2& point) const;

	Vec3 RightToLeft(const Vec3& point) const;
	Vec3 LeftToRight(const Vec3& point) const;

	void translateCoord(Vec2& point) const;
//坐标空间转换
/*
	Vec2 GlobalToLocal(const Node* node, const Vec2& point) const;
	Vec2 LocalToGlobal(const Node* node, const Vec2& point) const;*/



private:
	CoordTypes		m_coordType;
	Size			m_globalSize;
};
#endif