#include "Node.h"
#include "GMAssert.h"



Node::Node(NodeTypes type)
	:IteratorSolutioner(m_childList),
	m_v2AnchontPoint(),
	m_v2Position(),
	m_v2Scale(),
	m_v3Rotate(),
	m_siContentSize(),
	m_bVisiable(true),
	m_bEnable(true),
	m_iLocalZ(0),
	m_iGlobalZ(0),
	m_gsName(""),
	m_iTag(0),
	m_childList(),
	m_parent(nullptr),
	mMatrix(),
	needUpdate(true),
	m_eType(type)
{
	D3DXMatrixIdentity(&mMatrix);
}

Node::Node(const Node& node)
	:IteratorSolutioner(m_childList),
	m_v2AnchontPoint(node.m_v2AnchontPoint),
	m_v2Position(node.m_v2Position), 
	m_v2Scale(node.m_v2Scale),
	m_v3Rotate(node.m_v3Rotate),
	m_siContentSize(node.m_siContentSize),
	m_bVisiable(node.m_bVisiable),
	m_bEnable(node.m_bEnable),
	m_iLocalZ(node.m_iLocalZ),
	m_iGlobalZ(node.m_iGlobalZ),
	m_gsName(node.m_gsName),
	m_iTag(node.m_iTag),
	m_childList(node.m_childList),
	m_parent(nullptr),
	mMatrix(node.mMatrix),
	needUpdate(true),
	m_eType(node.m_eType)
{
	if (node.m_parent)
		node.m_parent->addChild(this);
}

Node::~Node()
{
	m_childList.clear();
}

void Node::setAnchontPoint(const Vec2& point)
{
	m_v2AnchontPoint = point;
}

void Node::setAnchontPoint(float x, float y)
{
	m_v2AnchontPoint.x = x;
	m_v2AnchontPoint.y = y;
}

void Node::setAnchontPointX(float x)
{
	m_v2AnchontPoint.x = x;
}

void Node::setAnchontPointY(float y)
{
	m_v2AnchontPoint.y = y;
}

const Vec2& Node::getAnchontPoint() const
{
	return m_v2AnchontPoint;
}

void Node::setPosition(const Vec2& pos)
{
	m_v2Position = pos;
}

void Node::setPosition(float x, float y)
{
	m_v2Position.x = x;
	m_v2Position.y = y;
}

void Node::setPositionX(float x)
{
	m_v2Position.x = x;
}

void Node::setPositionY(float y)
{
	m_v2Position.y = y;
}

const Vec2& Node::getPosition() const
{
	return m_v2Position;
}

void Node::setScale(const Vec2& scale)
{
	m_v2Scale = scale;
}

void Node::setScale(float x, float y)
{
	m_v2Scale.x = x;
	m_v2Scale.y = y;
}

void Node::setScaleX(float x)
{
	m_v2Scale.x = x;
}

void Node::setScaleY(float y)
{
	m_v2Scale.y = y;
}

const Vec2& Node::getScale() const
{
	return m_v2Scale;
}

void Node::setRotate(const Vec3& rotate)
{
	m_v3Rotate = rotate;
}

void Node::setRotate(float x, float y, float z)
{
	m_v3Rotate.x = x;
	m_v3Rotate.y = y;
	m_v3Rotate.z = z;
}

void Node::setRotateX(float x)
{
	m_v3Rotate.x = x;
}

void Node::setRotateY(float y)
{
	m_v3Rotate.y = y;
}

void Node::setRotateZ(float z)
{
	m_v3Rotate.z = z;
}

const Vec3& Node::getRotate() const
{
	return m_v3Rotate;
}

void Node::setContentSize(const Size& size)
{
	m_siContentSize = size;
}

void Node::setContentSize(float width, float height)
{
	m_siContentSize.width = width;
	m_siContentSize.height = height;
}

void Node::setContentSizeX(float width)
{
	m_siContentSize.width = width;
}

void Node::setContentSizeY(float height)
{
	m_siContentSize.height = height;
}

const Size& Node::getContentSize() const
{
	return m_siContentSize;
}

void Node::setName(const GString& name)
{
	m_gsName = name;
}

const GString& Node::getName() const
{
	return m_gsName;
}

void Node::setTag(int tag)
{
	m_iTag = tag;
}

int Node::getTag() const
{
	return m_iTag;
}

void Node::setLocalZ(int z)
{
	m_iLocalZ = z;
}

int Node::getLocalZ() const
{
	return m_iLocalZ;
}

void Node::setGlobalZ(int z)
{
	m_iGlobalZ = z;
}

int Node::getGlobalZ() const
{
	return m_iGlobalZ;
}

void Node::setType(NodeTypes type)
{
	m_eType = type;
}

NodeTypes Node::getType() const
{
	return m_eType;
}

void Node::setVisiable(bool visiable)
{
	m_bVisiable = visiable;
}

bool Node::isVisiable() const
{
	return m_bVisiable;
}

void Node::setEnable(bool enable)
{
	m_bEnable = enable;
}

bool Node::isEnable() const
{
	return m_bEnable;
}

Node* Node::getParent()
{
	return m_parent;
}

const Node* Node::getParent() const
{
	return m_parent;
}

const Vector<Node*>& Node::getChilds() const
{
	return m_childList;
}

Node* Node::searchChild(const GString& name)
{
	auto itor = m_childList.begin();
	for (;itor != m_childList.end(); ++itor)
		if ((*itor)->getName() == name)
			return *itor;
	return nullptr;
}

Node* Node::searchChild(int tag)
{
	auto itor = m_childList.begin();
	for (;itor != m_childList.end(); ++itor)
		if ((*itor)->getTag() == tag)
			return *itor;
	return nullptr;
}

const Node* Node::searchChild(const GString& name) const
{
	auto itor = m_childList.begin();
	for (;itor != m_childList.end(); ++itor)
		if ((*itor)->getName() == name)
			return *itor;
	return nullptr;
}

const Node* Node::searchChild(int tag) const
{
	auto itor = m_childList.begin();
	for (;itor != m_childList.end(); ++itor)
		if ((*itor)->getTag() == tag)
			return *itor;
	return nullptr;
}

void Node::addChild(Node* node, int local_z /*= 0*/)
{
	removeThis();
	GMASSERT(m_parent == nullptr);
	m_childList.push_back(node);
}

void Node::removeChild(Node* node)
{
	auto itor = m_childList.begin();
	for (; itor != m_childList.end(); ++itor)
	{
		if (*itor == node)
		{
			updateItor(m_childList.erase(itor));
			return;
		}
	}
}

void Node::removeChild(const GString& name)
{
	auto itor = m_childList.begin();
	for (; itor != m_childList.end(); ++itor)
	{
		Node* node = *itor;
		if (node->getName() == name)
		{
			updateItor(m_childList.erase(itor));
			return;
		}
	}
}

void Node::removeChild(int tag)
{
	auto itor = m_childList.begin();
	for (; itor != m_childList.end(); ++itor)
	{
		Node* node = *itor;
		if (node->getTag() == tag)
		{
			updateItor(m_childList.erase(itor));
			return;
		}
	}
}

void Node::removeThis()
{
	if(m_parent)
	{
		m_parent->removeChild(this);
		m_parent = nullptr;
	}	
}

void Node::setUpdate(bool needUpdate)
{
	this->needUpdate = needUpdate;
}


void Node::update()
{
	if (!needUpdate) {
		updateChild();
		return;
	}

	D3DXMATRIX matrix;
	float tmp_ap_x = m_v2AnchontPoint.x * m_siContentSize.width;
	float tmp_ap_y = m_v2AnchontPoint.y * m_siContentSize.height;
	D3DXMatrixTranslation(&matrix, tmp_ap_x, tmp_ap_y, 0);
	mMatrix = mMatrix * matrix;
	D3DXMatrixScaling(&matrix, m_v2Scale.x, m_v2Scale.y, 1);
	mMatrix = mMatrix * matrix;
	D3DXMatrixRotationX(&matrix, m_v3Rotate.x);
	mMatrix = mMatrix * matrix;
	D3DXMatrixRotationY(&matrix, m_v3Rotate.y);
	mMatrix = mMatrix * matrix;
	D3DXMatrixRotationZ(&matrix, m_v3Rotate.z);
	mMatrix = mMatrix * matrix;
	D3DXMatrixTranslation(&matrix, m_v2Position.x, m_v2Position.y, 0);
	mMatrix = mMatrix * matrix;

	if (m_parent)
		mMatrix = mMatrix * (*m_parent->mMatrix);

	auto itor = m_childList.begin();
	for (; itor != m_childList.end(); ++itor)
		(*itor)->setUpdate(true);

	updateChild();
}

void Node::updateChild()
{
	auto itor = begin();
	while (itor != end())
	{
		(*itor)->update();
		itor = nextItor();
	}
}
