#pragma once
#include <string>
#include <filesystem>

namespace constants {
	inline std::string const INIT_PATH = std::filesystem::canonical("/proc/self/exe").parent_path().string() + "/game/init.json";
}