#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesDigit1character) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
}

TEST(SoundexTest, HandlesDigit2Character) {
    EXPECT_EQ(generateSoundex("Ashcroft"), "A261");
}

TEST(SoundexTest, HandlesDigit5Character) {
    EXPECT_EQ(generateSoundex("Honeyman"), "H555");
}

