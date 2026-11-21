
#include "clubhub/ConsoleOutput.h"

#include <cstdlib>
#include <string>

namespace clubhub {

std::string_view statusLabel(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered:
            return "REGISTERED";

        case RegistrationStatus::Cancelled:
            return "CANCELLED";

        case RegistrationStatus::CheckedIn:
            return "CHECKED IN";

        case RegistrationStatus::Waitlisted:
            return "WAITLISTED";
    }

    return "UNKNOWN";
}

bool colourEnabled(bool noColorFlag) {
    if (noColorFlag) {
        return false;
    }

    return std::getenv("NO_COLOR") == nullptr;
}

std::string formatStatus(RegistrationStatus s, bool colour) {
    std::string label = "[" + std::string(statusLabel(s)) + "]";

    if (!colour) {
        return label;
    }

    switch (s) {
        case RegistrationStatus::Registered:
            return "\033[32m" + label + "\033[0m";

        case RegistrationStatus::Cancelled:
            return "\033[31m" + label + "\033[0m";

        case RegistrationStatus::CheckedIn:
            return "\033[36m" + label + "\033[0m";

        case RegistrationStatus::Waitlisted:
            return "\033[33m" + label + "\033[0m";
    }

    return label;
}

std::string formatError(
    std::string_view what,
    std::string_view why,
    std::string_view next
) {
    return "Error: " + std::string(what)
           + ": " + std::string(why)
           + ".\nNext step: " + std::string(next);
}

} 
