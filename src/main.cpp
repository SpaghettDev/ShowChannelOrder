#include <functional>

#include <Geode/modify/SetGroupIDLayer.hpp>

using namespace geode::prelude;

template <typename T>
bool areAllObjects(CCArray* arr, std::function<bool(T*)>&& predicate)
{
	for (auto c : CCArrayExt<T*>(arr))
		if (c && !predicate(c)) return false;

	return true;
}

struct SCOSetGroupIDLayer : geode::Modify<SCOSetGroupIDLayer, SetGroupIDLayer>
{
	bool init(GameObject* obj, CCArray* objs)
	{
		auto isTrigger = [](GameObject* go) {
			return go->m_classType == GameObjectClassType::Effect;
		};

		this->m_showChannelOrder = obj
			? isTrigger(obj)
			: areAllObjects<GameObject>(objs, std::move(isTrigger));

		return SetGroupIDLayer::init(obj, objs);
	}
};
