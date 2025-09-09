#include "RequestHandler.h"

#include <exception>

#include "Message.h"
#include "MessageFlow.h"
#include "SBE/MessageHeader.h"
#include "SBE/RegistrationRequest.h"
#include "loggerlib.h"

RequestHandler::RequestHandler() noexcept {}

RequestHandler::~RequestHandler() noexcept {}

std::vector<char> RequestHandler::respond(
    const aeron_wrapper::FragmentData &fragmentData) noexcept {
    std::vector<char> buffer;

    try {
        std::unique_ptr<Message> message = nullptr;

        SBE::MessageHeader sbeMessageHeader;
        auto *base = reinterpret_cast<char *>(
            const_cast<uint8_t *>(fragmentData.atomicBuffer.buffer()));
        auto *start = base + fragmentData.offset;

        auto bufferLength = fragmentData.length;
        sbeMessageHeader.wrap(start, 0, 0, bufferLength);
        auto offset = sbeMessageHeader.encodedLength();
        auto blockLength = sbeMessageHeader.blockLength();
        auto version = sbeMessageHeader.version();

        switch (sbeMessageHeader.templateId()) {
            case SBE::RegistrationRequest::sbeTemplateId(): {
                SBE::RegistrationRequest sbeRegistrationRequest;
                sbeRegistrationRequest.wrapForDecode(start, offset, blockLength,
                                                     version, bufferLength);

                auto phoneNumber =
                    sbeRegistrationRequest.phoneNumber().getVAsStringView();

                // TODO::should pass message id
                int msgId = 0;
                // message = std::make_unique<RegistrationMessage>(msgId);
            } break;

            default:;
        }

        if (message != nullptr) {
            MessageFlow::execute(*message);
        }
    } catch (const std::exception &e) {
        qLogger::get().error_fast("Error: {}", e.what());
    }

    return buffer;
}
