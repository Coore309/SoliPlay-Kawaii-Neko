#include <entry.h>

#include <format>
#include <vector>

void Neko::setName(std::string name) {
	name_ = name;
}

void Neko::meow(void) {
	host.log.info(std::format("{0}：你好哇喵 ~ 我是 {0} 喵 ~", name_).c_str());
}

void Neko::pick(void) {
	host.log.info(std::format("{0}：踩奶踩奶 ~", name_).c_str());
}

void Neko::dead(void) {
	host.log.info(std::format("{0}：唔 ~ 死掉了喵 ~", name_).c_str());
}