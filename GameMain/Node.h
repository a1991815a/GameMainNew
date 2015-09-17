#ifndef __NODE__
#define __NODE__
#include "Ref.h"
#include "Vec.h"
#include "Vector.h"
#include "UtilsHeader.h"
#include "IteratorSolutioner.h"

enum NodeTypes
{
	NT_UNKNKOWN,
	NT_SPRITE,
	NT_SCENE,
	NT_LAYER,
	NT_GUIOBJECT,
	NT_GFRAME
};

class Node : public Ref, private IteratorSolutioner<Vector<Node*>>{
public:
	Node(NodeTypes type);
	Node(const Node& node);
	~Node();
public:
	virtual void visit() const = 0;
	void update();
	void updateChild();

	void setAnchontPoint(const Vec2& point);
	void setAnchontPoint(float x, float y);
	void setAnchontPointX(float x);
	void setAnchontPointY(float y);
	const Vec2& getAnchontPoint() const;

	void setPosition(const Vec2& pos);
	void setPosition(float x, float y);
	void setPositionX(float x);
	void setPositionY(float y);
	const Vec2& getPosition() const;

	void setScale(const Vec2& scale);
	void setScale(float x, float y);
	void setScaleX(float x);
	void setScaleY(float y);
	const Vec2& getScale() const;

	void setRotate(const Vec3& rotate);
	void setRotate(float x, float y, float z);
	void setRotateX(float x);
	void setRotateY(float y);
	void setRotateZ(float z);
	const Vec3& getRotate() const;

	void setContentSize(const Size& size);
	void setContentSize(float width, float height);
	void setContentSizeX(float width);
	void setContentSizeY(float height);
	const Size& getContentSize() const;

	void setName(const GString& name);
	const GString& getName() const;

	void setTag(int tag);
	int getTag() const;

	void setLocalZ(int z);
	int getLocalZ() const;

	void setGlobalZ(int z);
	int getGlobalZ() const;

	void setType(NodeTypes type);
	NodeTypes getType() const;

	void setVisiable(bool visiable);
	bool isVisiable() const;

	void setEnable(bool enable);
	bool isEnable() const;
private:
	Vec2 m_v2AnchontPoint;
	Vec2 m_v2Position;
	Vec2 m_v2Scale;
	Vec3 m_v3Rotate;
	Size m_siContentSize;

	bool m_bVisiable;
	bool m_bEnable;

	int m_iLocalZ;
	int m_iGlobalZ;

	GString m_gsName;
	int m_iTag;

	NodeTypes m_eType;
public:
	Node* getParent();
	const Node* getParent() const;
	const Vector<Node*>& getChilds() const;
	Node* searchChild(const GString& name);
	Node* searchChild(int tag);
	const Node* searchChild(const GString& name)const;
	const Node* searchChild(int tag)const;

	void addChild(Node* node, int local_z = 0);
	void removeChild(Node* node);
	void removeChild(const GString& name);
	void removeChild(int tag);
	void removeThis();
private:
	Vector<Node*> m_childList;
	Node* m_parent;
	//±‰ªªæÿ’Û
private:
	D3DXMATRIX mMatrix;
	bool needUpdate;
	void setUpdate(bool needUpdate);
};
#endif