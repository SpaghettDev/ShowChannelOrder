#include <Geode/modify/SetGroupIDLayer.hpp>

using namespace geode::prelude;

struct SCOSetGroupIDLayer : geode::Modify<SCOSetGroupIDLayer, SetGroupIDLayer>
{
	bool init(GameObject* obj, CCArray* objs)
	{
		this->m_showChannelOrder = true;

		return SetGroupIDLayer::init(obj, objs);
	}
};
