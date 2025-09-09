#pragma once

#include <string>
#include <string_view>

#include "MessageType.h"

class Message {
   public:
    Message(MessageType mType, int mId) noexcept;

    virtual ~Message() noexcept = default;

   public:
    MessageType msgType;
    int msgId;
};

class RegistrationMessage final : public Message {
   public:
    RegistrationMessage(int msgId, std::string_view phoneNum) noexcept;

    ~RegistrationMessage() noexcept = default;

    StepResult validate() const noexcept;

   public:
    std::string phoneNumber;
};

class OrderMessage final : public Message {
   public:
    OrderMessage(int msgId, std::string_view sym, int qty, double prc) noexcept;

    ~OrderMessage() noexcept = default;

    StepResult validate() const noexcept;

   public:
    std::string symbol;
    int quantity;
    double price;
};

class CancelMessage final : public Message {
   public:
    CancelMessage(int msgId, int cId) noexcept;

    ~CancelMessage() noexcept = default;

    StepResult validate() const noexcept;

   public:
    int cancelId;
};
