//
// Created by romka on 22.09.2023.
//
#include "catch2.hpp"

#define CATCH_CONFIG_MAIN

#include "../liblab2/include/Message.h"
#include "../liblab2/include/Queue.h"

TEST_CASE("Message Constructors") {
    SECTION("Default Constructor") {
        Message message;
        REQUIRE(message.getTime() == 0LL);
        Message message1{99999LL};
        REQUIRE(message1.getTime() == 99999LL);
    }

    SECTION("Initializing Constructor") {
        Message message{"kasimov", "oop", 9999LL};
        REQUIRE(message.getTime() == 9999LL);
        REQUIRE(message.getChatName() == "oop");
        REQUIRE(message.getText() == "kasimov");
        Message message1{"kezin", "aisd"};
        REQUIRE(message1.getTime() == time(nullptr));
    }

    SECTION("Test exception") {
        REQUIRE_THROWS(Message{-100LL});
        REQUIRE_THROWS(Message{std::numeric_limits<long long>::max() - 170208002LL});
        REQUIRE_THROWS(Message{"roman", "vk", -100LL});
    }
}

TEST_CASE("Message setters") {
    SECTION("Set time") {
        Message message;
        message.setTime(9999L);
        REQUIRE(message.getTime() == 9999L);
        srand(time(nullptr));
        int a = rand();
        a = (a < 0) ? -a : a;
        REQUIRE_NOTHROW(message.setTime(a));
    }

    SECTION("Set text of message") {
        Message message;
        message.setText("kasimov");
        REQUIRE(message.getText() == "kasimov");
    }

    SECTION("Set chat name") {
        Message message;
        message.setChatName("oop");
        REQUIRE(message.getChatName() == "oop");
    }

    SECTION("Test exception") {
        Message message;
        REQUIRE_THROWS(message.setTime(-100LL));
    }
}

TEST_CASE("Message methods and operators") {
    SECTION("Find test") {
        Message message("kasimov roman elmirovich the best football player", "champions league");
        REQUIRE(message.find("best"));
        REQUIRE_FALSE(message.find("romik"));
    }

    SECTION("Operator <") {
        Message message("kasimov", "oop");
        Message message1("kasimov", "aisd");
        Message message2("kasimov", "oop", 7LL);
        REQUIRE(message1 < message);
        REQUIRE(message2 < message);
    }

    SECTION("Operator ==") {
        Message message("kasimov", "oop");
        Message message1("kezin", "oop");
        Message messgae2("kezin", "oop", 8LL);
        REQUIRE(message1 == message);
        REQUIRE_FALSE(messgae2 == message1);
    }

    SECTION("Operator +") {
        Message message("kasimov ", "oop");
        Message message1("roman", "oop", 9LL);
        Message mergedMessage = message + message1;
        REQUIRE(mergedMessage.getText() == "kasimov roman");
        REQUIRE(mergedMessage.getTime() == time(nullptr));
    }

    SECTION("Test exception") {
        Message message("kasimov", "oop");
        Message message1("roman", "aisd");
        REQUIRE_THROWS(message + message1);
    }
}