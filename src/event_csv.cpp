#include "clubhub/event_csv.hpp"
#include <sstream>
#include <stdexcept>

namespace clubhub {

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;

    std::getline(in, line); // Skip header

    while (std::getline(in, line)) {
        ++lineNo;
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        std::stringstream ss(line);
        std::string id, title, startStr, location, capacityStr;

        if (std::getline(ss, id, ',') &&
            std::getline(ss, title, ',') &&
            std::getline(ss, startStr, ',') &&
            std::getline(ss, location, ',') &&
            std::getline(ss, capacityStr, ',')) {

            try {
                TimePoint start = parseTimePoint(startStr);
                int capacity = std::stoi(capacityStr);
                result.events.emplace_back(id, title, start, location, capacity);
            } catch (const std::exception& e) {
                result.errors.push_back({lineNo, e.what()});
            }
        } else {
            result.errors.push_back({lineNo, "expected exactly 5 fields"});
        }
    }
    return result;
}

} // namespace clubhub