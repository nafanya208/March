#include "TimeManager.h"
float TimeManager::get_cur_time() {
	std::time_t time = std::time(nullptr);
	std::tm local;
	localtime_s(&local, &time);
	return local.tm_sec + 60 * local.tm_min + 3600 * local.tm_hour;
}