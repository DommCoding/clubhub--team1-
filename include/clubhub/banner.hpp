#pragma once
#include <string>
#include <string_view>
namespace clubhub {

inline constexpr std::string_view kTeamName = "clubhub--team1-";

[[nodiscard]] std::string banner(std::string_view teamName);
}  