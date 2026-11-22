
#include "clubhub/Student.h"

#include <stdexcept>
#include <utility>

namespace clubhub {

Student::Student(std::string id, std::string name, std::string email)
    : id_(std::move(id)),
      name_(std::move(name)),
      email_(std::move(email)) {

    if (id_.empty()) {
        throw std::invalid_argument("Student ID cannot be empty");
    }

    if (name_.empty()) {
        throw std::invalid_argument("Student name cannot be empty");
    }

    if (email_.find('@') == std::string::npos) {
        throw std::invalid_argument("Invalid student email");
    }
}

void Student::giveSmsConsent(std::string phone) {
    if (phone.empty()) {
        throw std::invalid_argument("Phone number cannot be empty");
    }

    for (char c : phone) {
        if ((c < '0' || c > '9') && c != '+' && c != ' ') {
            throw std::invalid_argument("Invalid phone number");
        }
    }

    phone_ = std::move(phone);
}

void Student::withdrawSmsConsent() noexcept {
    phone_.reset();
}

std::string Student::redacted() const {
    return "Student{id=" + maskId(id_) + "}";
}

std::string maskId(std::string_view id) {
    if (id.size() <= 3) {
        return std::string(id.size(), '*');
    }

    return std::string(id.substr(0, 2))
           + std::string(id.size() - 2, '*')
           + std::string(id.substr(id.size() - 1));
}

}
