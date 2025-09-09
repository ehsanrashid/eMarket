/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBE_REGISTRATIONRESPONSE_CXX_H_
#define _SBE_REGISTRATIONRESPONSE_CXX_H_

#if __cplusplus >= 201103L
#  define SBE_CONSTEXPR constexpr
#  define SBE_NOEXCEPT noexcept
#else
#  define SBE_CONSTEXPR
#  define SBE_NOEXCEPT
#endif

#if __cplusplus >= 201703L
#  include <string_view>
#  define SBE_NODISCARD [[nodiscard]]
#  if !defined(SBE_USE_STRING_VIEW)
#    define SBE_USE_STRING_VIEW 1
#  endif
#else
#  define SBE_NODISCARD
#endif

#if __cplusplus >= 202002L
#  include <span>
#  if !defined(SBE_USE_SPAN)
#    define SBE_USE_SPAN 1
#  endif
#endif

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <cstring>
#include <iomanip>
#include <limits>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

#if defined(WIN32) || defined(_WIN32)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) _byteswap_ushort(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) _byteswap_ulong(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) _byteswap_uint64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#  define SBE_BIG_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) (v)
#else
#  error \
      "Byte Ordering of platform not determined. Set __BYTE_ORDER__ manually before including this file."
#endif

#if !defined(SBE_BOUNDS_CHECK_EXPECT)
#  if defined(SBE_NO_BOUNDS_CHECK)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (false)
#  elif defined(_MSC_VER)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (exp)
#  else
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (__builtin_expect(exp, c))
#  endif

#endif

#define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()

#include "AppHeader.h"
#include "Char16str.h"
#include "Char32str.h"
#include "Char64str.h"
#include "MessageHeader.h"

namespace SBE {

class RegistrationResponse {
   private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_position = 0;
    std::uint64_t m_actingBlockLength = 0;
    std::uint64_t m_actingVersion = 0;

    inline std::uint64_t *sbePositionPtr() SBE_NOEXCEPT { return &m_position; }

   public:
    static constexpr std::uint16_t SBE_BLOCK_LENGTH =
        static_cast<std::uint16_t>(420);
    static constexpr std::uint16_t SBE_TEMPLATE_ID =
        static_cast<std::uint16_t>(102);
    static constexpr std::uint16_t SBE_SCHEMA_ID =
        static_cast<std::uint16_t>(1);
    static constexpr std::uint16_t SBE_SCHEMA_VERSION =
        static_cast<std::uint16_t>(1);
    static constexpr const char *SBE_SEMANTIC_VERSION = "1.0.0";

    enum MetaAttribute { EPOCH, TIME_UNIT, SEMANTIC_TYPE, PRESENCE };

    union sbe_float_as_uint_u {
        float fp_value;
        std::uint32_t uint_value;
    };

    union sbe_double_as_uint_u {
        double fp_value;
        std::uint64_t uint_value;
    };

    using messageHeader = MessageHeader;

    RegistrationResponse() = default;

    RegistrationResponse(char *buffer, const std::uint64_t offset,
                         const std::uint64_t bufferLength,
                         const std::uint64_t actingBlockLength,
                         const std::uint64_t actingVersion)
        : m_buffer(buffer),
          m_bufferLength(bufferLength),
          m_offset(offset),
          m_position(sbeCheckPosition(offset + actingBlockLength)),
          m_actingBlockLength(actingBlockLength),
          m_actingVersion(actingVersion) {}

    RegistrationResponse(char *buffer, const std::uint64_t bufferLength)
        : RegistrationResponse(buffer, 0, bufferLength, sbeBlockLength(),
                               sbeSchemaVersion()) {}

    RegistrationResponse(char *buffer, const std::uint64_t bufferLength,
                         const std::uint64_t actingBlockLength,
                         const std::uint64_t actingVersion)
        : RegistrationResponse(buffer, 0, bufferLength, actingBlockLength,
                               actingVersion) {}

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength()
        SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(420);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength()
        SBE_NOEXCEPT {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId()
        SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(102);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId()
        SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(1);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion()
        SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(1);
    }

    SBE_NODISCARD static const char *sbeSemanticVersion() SBE_NOEXCEPT {
        return "1.0.0";
    }

    SBE_NODISCARD static SBE_CONSTEXPR const char *sbeSemanticType()
        SBE_NOEXCEPT {
        return "";
    }

    SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT { return m_offset; }

    RegistrationResponse &wrapForEncode(char *buffer,
                                        const std::uint64_t offset,
                                        const std::uint64_t bufferLength) {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    RegistrationResponse &wrapAndApplyHeader(char *buffer,
                                             const std::uint64_t offset,
                                             const std::uint64_t bufferLength) {
        messageHeader hdr(buffer, offset, bufferLength, sbeSchemaVersion());

        hdr.blockLength(sbeBlockLength())
            .templateId(sbeTemplateId())
            .schemaId(sbeSchemaId())
            .version(sbeSchemaVersion());

        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset + messageHeader::encodedLength();
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    RegistrationResponse &wrapForDecode(char *buffer,
                                        const std::uint64_t offset,
                                        const std::uint64_t actingBlockLength,
                                        const std::uint64_t actingVersion,
                                        const std::uint64_t bufferLength) {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = actingBlockLength;
        m_actingVersion = actingVersion;
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    RegistrationResponse &sbeRewind() {
        return wrapForDecode(m_buffer, m_offset, m_actingBlockLength,
                             m_actingVersion, m_bufferLength);
    }

    SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT {
        return m_position;
    }

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    std::uint64_t sbeCheckPosition(const std::uint64_t position) {
        if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false)) {
            throw std::runtime_error("buffer too short [E100]");
        }
        return position;
    }

    void sbePosition(const std::uint64_t position) {
        m_position = sbeCheckPosition(position);
    }

    SBE_NODISCARD std::uint64_t encodedLength() const SBE_NOEXCEPT {
        return sbePosition() - m_offset;
    }

    SBE_NODISCARD std::uint64_t decodeLength() const {
        RegistrationResponse skipper(m_buffer, m_offset, m_bufferLength,
                                     m_actingBlockLength, m_actingVersion);
        skipper.skip();
        return skipper.encodedLength();
    }

    SBE_NODISCARD const char *buffer() const SBE_NOEXCEPT { return m_buffer; }

    SBE_NODISCARD char *buffer() SBE_NOEXCEPT { return m_buffer; }

    SBE_NODISCARD std::uint64_t bufferLength() const SBE_NOEXCEPT {
        return m_bufferLength;
    }

    SBE_NODISCARD std::uint64_t actingVersion() const SBE_NOEXCEPT {
        return m_actingVersion;
    }

    SBE_NODISCARD static const char *headerMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t headerId() SBE_NOEXCEPT { return 1; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t headerSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool headerInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t headerEncodingOffset()
        SBE_NOEXCEPT {
        return 0;
    }

   private:
    AppHeader m_header;

   public:
    SBE_NODISCARD AppHeader &header() {
        m_header.wrap(m_buffer, m_offset + 0, m_actingVersion, m_bufferLength);
        return m_header;
    }

    SBE_NODISCARD static const char *messageMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t messageId() SBE_NOEXCEPT { return 2; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t messageSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool messageInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t messageEncodingOffset()
        SBE_NOEXCEPT {
        return 288;
    }

   private:
    Char64str m_message;

   public:
    SBE_NODISCARD Char64str &message() {
        m_message.wrap(m_buffer, m_offset + 288, m_actingVersion,
                       m_bufferLength);
        return m_message;
    }

    SBE_NODISCARD static const char *tokenMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t tokenId() SBE_NOEXCEPT { return 3; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t tokenSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool tokenInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t tokenEncodingOffset()
        SBE_NOEXCEPT {
        return 352;
    }

   private:
    Char32str m_token;

   public:
    SBE_NODISCARD Char32str &token() {
        m_token.wrap(m_buffer, m_offset + 352, m_actingVersion, m_bufferLength);
        return m_token;
    }

    SBE_NODISCARD static const char *expiresInMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::SEMANTIC_TYPE:
                return "Duration";
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t expiresInId() SBE_NOEXCEPT { return 4; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t expiresInSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool expiresInInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t expiresInEncodingOffset()
        SBE_NOEXCEPT {
        return 384;
    }

    static SBE_CONSTEXPR std::uint32_t expiresInNullValue() SBE_NOEXCEPT {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR std::uint32_t expiresInMinValue() SBE_NOEXCEPT {
        return UINT32_C(0x0);
    }

    static SBE_CONSTEXPR std::uint32_t expiresInMaxValue() SBE_NOEXCEPT {
        return UINT32_C(0xfffffffe);
    }

    static SBE_CONSTEXPR std::size_t expiresInEncodingLength() SBE_NOEXCEPT {
        return 4;
    }

    SBE_NODISCARD std::uint32_t expiresIn() const SBE_NOEXCEPT {
        std::uint32_t val;
        std::memcpy(&val, m_buffer + m_offset + 384, sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    RegistrationResponse &expiresIn(const std::uint32_t value) SBE_NOEXCEPT {
        std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 384, &val, sizeof(std::uint32_t));
        return *this;
    }

    SBE_NODISCARD static const char *refreshTokenMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t refreshTokenId() SBE_NOEXCEPT {
        return 5;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t refreshTokenSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool refreshTokenInActingVersion() SBE_NOEXCEPT {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t refreshTokenEncodingOffset()
        SBE_NOEXCEPT {
        return 388;
    }

   private:
    Char32str m_refreshToken;

   public:
    SBE_NODISCARD Char32str &refreshToken() {
        m_refreshToken.wrap(m_buffer, m_offset + 388, m_actingVersion,
                            m_bufferLength);
        return m_refreshToken;
    }

    template <typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> &operator<<(
        std::basic_ostream<CharT, Traits> &builder,
        const RegistrationResponse &_writer) {
        RegistrationResponse writer(
            _writer.m_buffer, _writer.m_offset, _writer.m_bufferLength,
            _writer.m_actingBlockLength, _writer.m_actingVersion);

        builder << '{';
        builder << R"("Name": "RegistrationResponse", )";
        builder << R"("sbeTemplateId": )";
        builder << writer.sbeTemplateId();
        builder << ", ";

        builder << R"("header": )";
        builder << writer.header();

        builder << ", ";
        builder << R"("message": )";
        builder << writer.message();

        builder << ", ";
        builder << R"("token": )";
        builder << writer.token();

        builder << ", ";
        builder << R"("expiresIn": )";
        builder << +writer.expiresIn();

        builder << ", ";
        builder << R"("refreshToken": )";
        builder << writer.refreshToken();

        builder << '}';

        return builder;
    }

    void skip() {}

    SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT {
        return true;
    }

    SBE_NODISCARD static std::size_t computeLength() {
#if defined(__GNUG__) && !defined(__clang__)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wtype-limits"
#endif
        std::size_t length = sbeBlockLength();

        return length;
#if defined(__GNUG__) && !defined(__clang__)
#  pragma GCC diagnostic pop
#endif
    }
};
}  // namespace SBE
#endif
