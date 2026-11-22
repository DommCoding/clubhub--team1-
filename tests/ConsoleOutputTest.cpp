// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 1, ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"

#include <gtest/gtest.h>
#include <string>

using clubhub::RegistrationStatus;
using clubhub::colourEnabled;
using clubhub::formatError;
using clubhub::formatStatus;
using clubhub::statusLabel;

TEST(ConsoleOutput, StatusIsReadableWithoutColour) {
    const std::string text = formatStatus(RegistrationStatus::Cancelled, false);
    EXPECT_EQ(text, "[CANCELLED]");
    EXPECT_NE(text.find("CANCELLED"), std::string::npos);
    EXPECT_EQ(text.find("\033["), std::string::npos);
}

TEST(ConsoleOutput, ColourOnlyRepeatsTheWord) {
    const std::string coloured = formatStatus(RegistrationStatus::CheckedIn, true);
    EXPECT_NE(coloured.find("CHECKED IN"), std::string::npos);
    EXPECT_NE(coloured.find("\033["), std::string::npos);
    EXPECT_NE(coloured.find("\033[0m"), std::string::npos);
    EXPECT_FALSE(colourEnabled(true));
    EXPECT_EQ(statusLabel(RegistrationStatus::Waitlisted), "WAITLISTED");
}

TEST(ConsoleOutput, ErrorSaysWhatWhyAndNextStep) {
    const std::string err = formatError(
        "cannot register for E-017",
        "the event is full (40 of 40 seats)",
        "clubhub waitlist E-017");
    EXPECT_EQ(err,
              "Error: cannot register for E-017: the event is full (40 of 40 seats).\n"
              "Next step: clubhub waitlist E-017");
    EXPECT_NE(err.find("Next step:"), std::string::npos);
}
