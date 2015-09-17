#include "CoordSystem.h"
#include "Director.h"

CoordSystem::CoordSystem()
	:m_coordType(LEFT_HAND_COORD), m_globalSize()
{

}

CoordSystem::~CoordSystem()
{

}

void CoordSystem::init()
{
	m_globalSize = _director->getWindowSize();
}

void CoordSystem::setCoordModel(CoordTypes coord_type)
{
	m_coordType = coord_type;
}

CoordTypes CoordSystem::getCoordType() const
{
	return m_coordType;
}

Vec2 CoordSystem::RightToLeft(const Vec2& point) const
{
	Vec2 p;
	p.x = point.x;
	p.y = m_globalSize.height - point.y;
	return p;
}

Vec3 CoordSystem::RightToLeft(const Vec3& point) const
{
	Vec3 p;
	p.x = point.x;
	p.y = m_globalSize.height - point.y;
	p.z = point.z;
	return p;
}

Vec2 CoordSystem::LeftToRight(const Vec2& point) const
{
	Vec2 p;
	p.x = point.x;
	p.y = m_globalSize.height - point.y;
	return p;
}

Vec3 CoordSystem::LeftToRight(const Vec3& point) const
{
	Vec3 p;
	p.x = point.x;
	p.y = m_globalSize.height - point.y;
	p.z = point.z;
	return p;
}

void CoordSystem::translateCoord(Vec2& point) const
{
	switch (m_coordType)
	{
	case LEFT_HAND_COORD:
		point = RightToLeft(point);
		break;
	case RIGHT_HAND_COORD:
		point = LeftToRight(point);
		break;
	default:
		GMASSERT(false);
	}
}
