// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 1, ITC Club Hub contributors
#include "clubhub/Student.h"

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

using clubhub::Student;
using clubhub::maskId;

// Invented test data only: never real students.
TEST(StudentPrivacy, RedactedHidesPersonalData) {
    Student s("e20990417", "Test Student", "test@example.edu");
    s.giveSmsConsent("012 345 678");
    const std::string r = s.redacted();
    EXPECT_EQ(r, "Student{id=e2*******7}");
    EXPECT_EQ(r.find("Test"), std::string::npos);
    EXPECT_EQ(r.find("example.edu"), std::string::npos);
    EXPECT_EQ(r.find("345"), std::string::npos);
}

TEST(StudentPrivacy, OptionalConsentsStartOff) {
    Student s("e20990417", "Test Student", "test@example.edu");
    EXPECT_FALSE(s.remindersByEmail());
    EXPECT_FALSE(s.phone().has_value());
}

TEST(StudentPrivacy, WithdrawingSmsConsentErasesPhone) {
    Student s("e20990417", "Test Student", "test@example.edu");
    s.giveSmsConsent("+855 12 345 678");
    ASSERT_TRUE(s.phone().has_value());

    s.withdrawSmsConsent();
    EXPECT_FALSE(s.phone().has_value());
}

TEST(StudentPrivacy, RejectsEmailWithoutAt) {
    EXPECT_THROW((Student("e20990417", "A", "no-at-sign")), std::invalid_argument);
}

TEST(StudentPrivacy, RejectsPhoneWithLetters) {
    Student s("e20990417", "Test Student", "test@example.edu");
    EXPECT_THROW(s.giveSmsConsent("012-abc-678"), std::invalid_argument);
    EXPECT_FALSE(s.phone().has_value());
}

TEST(StudentPrivacy, MaskIdHidesShortIdsCompletely) {
    EXPECT_EQ(maskId(""), "");
    EXPECT_EQ(maskId("a"), "*");
    EXPECT_EQ(maskId("ab"), "**");
    EXPECT_EQ(maskId("abc"), "***");
    EXPECT_EQ(maskId("e20990417"), "e2*******7");
}