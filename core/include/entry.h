#pragma once
#include <soliplay_sdk/iplugin_object.h>

#include <string>

extern SoliHostAPI host;

class Neko {
public:
	void setName(std::string name);
	void meow(void);
	void pick(void);
	void dead(void);
private:
	std::string name_ = "普通猫猫";
};