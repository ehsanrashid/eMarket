#pragma once

#include <string>
#include <vector>

#include "aeron_wrapper.h"

class RequestHandler final {
   public:
    RequestHandler() noexcept;
    ~RequestHandler() noexcept;

    std::vector<char> respond(
        const aeron_wrapper::FragmentData &fragmentData) noexcept;
};
