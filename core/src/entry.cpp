#include <entry.h>
#include <unordered_map>

SoliHostAPI host;

std::unordered_map<uint64_t, Neko> mapInstance;
static long long total = 0;

SOLI_PLUGIN_INSTANCE createInstance(const SoliHostAPI hostAPI) {
	host = hostAPI;

	uint64_t handle = ((uintptr_t)&mapInstance << 32) + (uint64_t)total;
	mapInstance.emplace(handle, Neko());
	++total;
	return handle;
}

extern "C" {
	SOLIPLAY_API void setName(const SOLI_PLUGIN_INSTANCE i, const char* name) {
		if (mapInstance.find(i) == mapInstance.end()) {
			host.log.error("实例 i 不存在");
			return;
		}

		mapInstance[i].setName(name);
	}

	SOLIPLAY_API void meow(const SOLI_PLUGIN_INSTANCE i) {
		if (mapInstance.find(i) == mapInstance.end()) {
			host.log.error("实例 i 不存在");
			return;
		}

		mapInstance[i].meow();
	}

	SOLIPLAY_API void pick(const SOLI_PLUGIN_INSTANCE i) {
		if (mapInstance.find(i) == mapInstance.end()) {
			host.log.error("实例 i 不存在");
			return;
		}

		mapInstance[i].pick();
	}

	SOLIPLAY_API void dead(const SOLI_PLUGIN_INSTANCE i) {
		if (mapInstance.find(i) == mapInstance.end()) {
			host.log.error("实例 i 不存在");
			return;
		}

		mapInstance[i].dead();
	}
}

void destroyInstance(const SOLI_PLUGIN_INSTANCE i) {
	if (mapInstance.find(i) == mapInstance.end()) {
		host.log.error("实例 i 不存在");
		return;
	}

	mapInstance.erase(i);
}