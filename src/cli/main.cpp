#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "clubhub/event.hpp"
#include "clubhub/event_csv.hpp"

namespace {

std::string formatTimePoint(clubhub::TimePoint t) {
    using namespace std::chrono;
    const auto midnight = floor<days>(t);
    const year_month_day date{midnight};
    const hh_mm_ss time{t - midnight};
    std::ostringstream out;
    out << std::setfill('0') << static_cast<int>(date.year()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.month()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.day()) << ' '
        << std::setw(2) << time.hours().count() << ':'
        << std::setw(2) << time.minutes().count();
    return out.str();
}

int listEvents(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        std::cerr << "error: cannot open " << path << '\n';
        return 2;
    }

    auto [events, errors] = clubhub::loadEventsCsv(file);

    std::ranges::sort(events, {}, &clubhub::Event::start);

    std::cout << std::left << std::setw(18) << "START"
              << std::setw(25) << "TITLE"
              << std::setw(15) << "LOCATION"
              << "CAPACITY\n";

    for (const auto& e : events) {
        std::cout << std::left << std::setw(18) << formatTimePoint(e.start())
                  << std::setw(25) << e.title()
                  << std::setw(15) << e.location()
                  << e.capacity() << '\n';
    }

    std::cout << events.size() << " event(s)\n";

    for (const auto& err : errors) {
        std::cerr << path << ':' << err.line << ": skipped: " << err.message << '\n';
    }

    return errors.empty() ? 0 : 1;
}

void printUsage() {
    std::cerr << "usage: clubhub list-events [events.csv]\n";
}

} // namespace

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 2;
    }

    const std::string command = argv[1];
    if (command == "list-events") {
        return listEvents(argc > 2 ? argv[2] : "data/events.csv");
    }

    std::cerr << "unknown command: " << command << '\n';
    printUsage();
    return 2;
}