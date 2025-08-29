/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MY_APP_MESSAGES_IDENTITYMESSAGE_CXX_H_
#define _MY_APP_MESSAGES_IDENTITYMESSAGE_CXX_H_

#if __cplusplus >= 201103L
#define SBE_CONSTEXPR constexpr
#define SBE_NOEXCEPT noexcept
#else
#define SBE_CONSTEXPR
#define SBE_NOEXCEPT
#endif

#if __cplusplus >= 201703L
#include <string_view>
#define SBE_NODISCARD [[nodiscard]]
#if !defined(SBE_USE_STRING_VIEW)
#define SBE_USE_STRING_VIEW 1
#endif
#else
#define SBE_NODISCARD
#endif

#if __cplusplus >= 202002L
#include <span>
#if !defined(SBE_USE_SPAN)
#define SBE_USE_SPAN 1
#endif
#endif

#if !defined(__STDC_LIMIT_MACROS)
#define __STDC_LIMIT_MACROS 1
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
#define SBE_BIG_ENDIAN_ENCODE_16(v) _byteswap_ushort(v)
#define SBE_BIG_ENDIAN_ENCODE_32(v) _byteswap_ulong(v)
#define SBE_BIG_ENDIAN_ENCODE_64(v) _byteswap_uint64(v)
#define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define SBE_BIG_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define SBE_LITTLE_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#define SBE_LITTLE_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#define SBE_LITTLE_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#define SBE_BIG_ENDIAN_ENCODE_16(v) (v)
#define SBE_BIG_ENDIAN_ENCODE_32(v) (v)
#define SBE_BIG_ENDIAN_ENCODE_64(v) (v)
#else
#error \
    "Byte Ordering of platform not determined. Set __BYTE_ORDER__ manually before including this file."
#endif

#if !defined(SBE_BOUNDS_CHECK_EXPECT)
#if defined(SBE_NO_BOUNDS_CHECK)
#define SBE_BOUNDS_CHECK_EXPECT(exp, c) (false)
#elif defined(_MSC_VER)
#define SBE_BOUNDS_CHECK_EXPECT(exp, c) (exp)
#else
#define SBE_BOUNDS_CHECK_EXPECT(exp, c) (__builtin_expect(exp, c))
#endif

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

#include "Char64str.h"
#include "MessageHeader.h"

namespace messages {

class IdentityMessage {
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
        static_cast<std::uint16_t>(512);
    static constexpr std::uint16_t SBE_TEMPLATE_ID =
        static_cast<std::uint16_t>(1);
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

    IdentityMessage() = default;

    IdentityMessage(char *buffer, const std::uint64_t offset,
                    const std::uint64_t bufferLength,
                    const std::uint64_t actingBlockLength,
                    const std::uint64_t actingVersion)
        : m_buffer(buffer),
          m_bufferLength(bufferLength),
          m_offset(offset),
          m_position(sbeCheckPosition(offset + actingBlockLength)),
          m_actingBlockLength(actingBlockLength),
          m_actingVersion(actingVersion) {}

    IdentityMessage(char *buffer, const std::uint64_t bufferLength)
        : IdentityMessage(buffer, 0, bufferLength, sbeBlockLength(),
                          sbeSchemaVersion()) {}

    IdentityMessage(char *buffer, const std::uint64_t bufferLength,
                    const std::uint64_t actingBlockLength,
                    const std::uint64_t actingVersion)
        : IdentityMessage(buffer, 0, bufferLength, actingBlockLength,
                          actingVersion) {}

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength()
        SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(512);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength()
        SBE_NOEXCEPT {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId()
        SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(1);
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

    IdentityMessage &wrapForEncode(char *buffer, const std::uint64_t offset,
                                   const std::uint64_t bufferLength) {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    IdentityMessage &wrapAndApplyHeader(char *buffer,
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

    IdentityMessage &wrapForDecode(char *buffer, const std::uint64_t offset,
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

    IdentityMessage &sbeRewind() {
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
        IdentityMessage skipper(m_buffer, m_offset, m_bufferLength,
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

    SBE_NODISCARD static const char *msgMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t msgId() SBE_NOEXCEPT { return 1; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t msgSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool msgInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t msgEncodingOffset()
        SBE_NOEXCEPT {
        return 0;
    }

   private:
    Char64str m_msg;

   public:
    SBE_NODISCARD Char64str &msg() {
        m_msg.wrap(m_buffer, m_offset + 0, m_actingVersion, m_bufferLength);
        return m_msg;
    }

    SBE_NODISCARD static const char *typeMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t typeId() SBE_NOEXCEPT { return 2; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t typeSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool typeInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t typeEncodingOffset()
        SBE_NOEXCEPT {
        return 64;
    }

   private:
    Char64str m_type;

   public:
    SBE_NODISCARD Char64str &type() {
        m_type.wrap(m_buffer, m_offset + 64, m_actingVersion, m_bufferLength);
        return m_type;
    }

    SBE_NODISCARD static const char *idMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t idId() SBE_NOEXCEPT { return 3; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t idSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool idInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t idEncodingOffset()
        SBE_NOEXCEPT {
        return 128;
    }

   private:
    Char64str m_id;

   public:
    SBE_NODISCARD Char64str &id() {
        m_id.wrap(m_buffer, m_offset + 128, m_actingVersion, m_bufferLength);
        return m_id;
    }

    SBE_NODISCARD static const char *nameMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t nameId() SBE_NOEXCEPT { return 4; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t nameSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool nameInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t nameEncodingOffset()
        SBE_NOEXCEPT {
        return 192;
    }

   private:
    Char64str m_name;

   public:
    SBE_NODISCARD Char64str &name() {
        m_name.wrap(m_buffer, m_offset + 192, m_actingVersion, m_bufferLength);
        return m_name;
    }

    SBE_NODISCARD static const char *dateOfIssueMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t dateOfIssueId() SBE_NOEXCEPT {
        return 5;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t dateOfIssueSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool dateOfIssueInActingVersion() SBE_NOEXCEPT {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t dateOfIssueEncodingOffset()
        SBE_NOEXCEPT {
        return 256;
    }

   private:
    Char64str m_dateOfIssue;

   public:
    SBE_NODISCARD Char64str &dateOfIssue() {
        m_dateOfIssue.wrap(m_buffer, m_offset + 256, m_actingVersion,
                           m_bufferLength);
        return m_dateOfIssue;
    }

    SBE_NODISCARD static const char *dateOfExpiryMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t dateOfExpiryId() SBE_NOEXCEPT {
        return 6;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t dateOfExpirySinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool dateOfExpiryInActingVersion() SBE_NOEXCEPT {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t dateOfExpiryEncodingOffset()
        SBE_NOEXCEPT {
        return 320;
    }

   private:
    Char64str m_dateOfExpiry;

   public:
    SBE_NODISCARD Char64str &dateOfExpiry() {
        m_dateOfExpiry.wrap(m_buffer, m_offset + 320, m_actingVersion,
                            m_bufferLength);
        return m_dateOfExpiry;
    }

    SBE_NODISCARD static const char *addressMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t addressId() SBE_NOEXCEPT { return 7; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t addressSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool addressInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t addressEncodingOffset()
        SBE_NOEXCEPT {
        return 384;
    }

   private:
    Char64str m_address;

   public:
    SBE_NODISCARD Char64str &address() {
        m_address.wrap(m_buffer, m_offset + 384, m_actingVersion,
                       m_bufferLength);
        return m_address;
    }

    SBE_NODISCARD static const char *verifiedMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t verifiedId() SBE_NOEXCEPT { return 8; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t verifiedSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool verifiedInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t verifiedEncodingOffset()
        SBE_NOEXCEPT {
        return 448;
    }

   private:
    Char64str m_verified;

   public:
    SBE_NODISCARD Char64str &verified() {
        m_verified.wrap(m_buffer, m_offset + 448, m_actingVersion,
                        m_bufferLength);
        return m_verified;
    }

    template <typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> &operator<<(
        std::basic_ostream<CharT, Traits> &builder,
        const IdentityMessage &_writer) {
        IdentityMessage writer(
            _writer.m_buffer, _writer.m_offset, _writer.m_bufferLength,
            _writer.m_actingBlockLength, _writer.m_actingVersion);

        builder << '{';
        builder << R"("Name": "IdentityMessage", )";
        builder << R"("sbeTemplateId": )";
        builder << writer.sbeTemplateId();
        builder << ", ";

        builder << R"("msg": )";
        builder << writer.msg();

        builder << ", ";
        builder << R"("type": )";
        builder << writer.type();

        builder << ", ";
        builder << R"("id": )";
        builder << writer.id();

        builder << ", ";
        builder << R"("name": )";
        builder << writer.name();

        builder << ", ";
        builder << R"("dateOfIssue": )";
        builder << writer.dateOfIssue();

        builder << ", ";
        builder << R"("dateOfExpiry": )";
        builder << writer.dateOfExpiry();

        builder << ", ";
        builder << R"("address": )";
        builder << writer.address();

        builder << ", ";
        builder << R"("verified": )";
        builder << writer.verified();

        builder << '}';

        return builder;
    }

    void skip() {}

    SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT {
        return true;
    }

    SBE_NODISCARD static std::size_t computeLength() {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
        std::size_t length = sbeBlockLength();

        return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    }
};
}  // namespace messages

#endif
