#include "Message.h"

#include <regex>

#include "loggerlib.h"

Message::Message(MessageType mType, int mId) noexcept
    : msgType(mType), msgId(mId) {}

RegistrationMessage::RegistrationMessage(int msgId,
                                         std::string_view phoneNum) noexcept
    : Message(MT_REGISTRATION, msgId), phoneNumber(phoneNum) {}

StepResult RegistrationMessage::validate() const noexcept {
    qLogger::get().info_fast("Registration {} Validate phoneNumber={}", msgId,
                             phoneNumber);

    std::regex phoneRegex("^\\+92\\d{10}$");

    if (!regex_match(phoneNumber, phoneRegex)) {
        return StepResult::FAILED;
    }
    return StepResult::SUCCESS;
}

OrderMessage::OrderMessage(int msgId, std::string_view sym, int qty,
                           double prc) noexcept
    : Message(MT_ORDER, msgId), symbol(sym), quantity(qty), price(prc) {}

StepResult OrderMessage::validate() const noexcept {
    qLogger::get().info_fast("Order {} Validate symbol={}", msgId, symbol);

    if (quantity <= 0 || price <= 0.0) {
        qLogger::get().error_fast("Order {} Invalid quantity/price", msgId);
        return StepResult::FAILED;
    }
    return StepResult::SUCCESS;
}

CancelMessage::CancelMessage(int msgId, int cId) noexcept
    : Message(MT_CANCEL, msgId), cancelId(cId) {}

StepResult CancelMessage::validate() const noexcept {
    qLogger::get().info_fast("Cancel {} Validate cancelId= {}", msgId,
                             cancelId);

    if (cancelId <= 0) {
        qLogger::get().error_fast("Cancel {} Invalid cancelId", msgId);
        return StepResult::FAILED;
    }
    return StepResult::SUCCESS;
}
