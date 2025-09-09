/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBE_APPHEADER_CXX_H_
#define _SBE_APPHEADER_CXX_H_

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

namespace SBE {

class AppHeader {
   private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_actingVersion = 0;

   public:
    enum MetaAttribute { EPOCH, TIME_UNIT, SEMANTIC_TYPE, PRESENCE };

    union sbe_float_as_uint_u {
        float fp_value;
        std::uint32_t uint_value;
    };

    union sbe_double_as_uint_u {
        double fp_value;
        std::uint64_t uint_value;
    };

    AppHeader() = default;

    AppHeader(char *buffer, const std::uint64_t offset,
              const std::uint64_t bufferLength,
              const std::uint64_t actingVersion)
        : m_buffer(buffer),
          m_bufferLength(bufferLength),
          m_offset(offset),
          m_actingVersion(actingVersion) {
        if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 16) > m_bufferLength),
                                    false)) {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
    }

    AppHeader(char *buffer, const std::uint64_t bufferLength,
              const std::uint64_t actingVersion)
        : AppHeader(buffer, 0, bufferLength, actingVersion) {}

    AppHeader(char *buffer, const std::uint64_t bufferLength)
        : AppHeader(buffer, 0, bufferLength, sbeSchemaVersion()) {}

    AppHeader &wrap(char *buffer, const std::uint64_t offset,
                    const std::uint64_t actingVersion,
                    const std::uint64_t bufferLength) {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingVersion = actingVersion;

        if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 16) > m_bufferLength),
                                    false)) {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }

        return *this;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t encodedLength()
        SBE_NOEXCEPT {
        return 16;
    }

    SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT { return m_offset; }

    SBE_NODISCARD const char *buffer() const SBE_NOEXCEPT { return m_buffer; }

    SBE_NODISCARD char *buffer() SBE_NOEXCEPT { return m_buffer; }

    SBE_NODISCARD std::uint64_t bufferLength() const SBE_NOEXCEPT {
        return m_bufferLength;
    }

    SBE_NODISCARD std::uint64_t actingVersion() const SBE_NOEXCEPT {
        return m_actingVersion;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId()
        SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(1);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion()
        SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(1);
    }

    SBE_NODISCARD static const char *versionMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t versionId() SBE_NOEXCEPT { return -1; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t versionSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool versionInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t versionEncodingOffset()
        SBE_NOEXCEPT {
        return 0;
    }

    static SBE_CONSTEXPR std::uint16_t versionNullValue() SBE_NOEXCEPT {
        return SBE_NULLVALUE_UINT16;
    }

    static SBE_CONSTEXPR std::uint16_t versionMinValue() SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(0);
    }

    static SBE_CONSTEXPR std::uint16_t versionMaxValue() SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(65534);
    }

    static SBE_CONSTEXPR std::size_t versionEncodingLength() SBE_NOEXCEPT {
        return 2;
    }

    SBE_NODISCARD std::uint16_t version() const SBE_NOEXCEPT {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(val);
    }

    AppHeader &version(const std::uint16_t value) SBE_NOEXCEPT {
        std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint16_t));
        return *this;
    }

    SBE_NODISCARD static const char *sequenceMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sequenceId() SBE_NOEXCEPT { return -1; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sequenceSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool sequenceInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sequenceEncodingOffset()
        SBE_NOEXCEPT {
        return 2;
    }

    static SBE_CONSTEXPR std::uint32_t sequenceNullValue() SBE_NOEXCEPT {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR std::uint32_t sequenceMinValue() SBE_NOEXCEPT {
        return UINT32_C(0x0);
    }

    static SBE_CONSTEXPR std::uint32_t sequenceMaxValue() SBE_NOEXCEPT {
        return UINT32_C(0xfffffffe);
    }

    static SBE_CONSTEXPR std::size_t sequenceEncodingLength() SBE_NOEXCEPT {
        return 4;
    }

    SBE_NODISCARD std::uint32_t sequence() const SBE_NOEXCEPT {
        std::uint32_t val;
        std::memcpy(&val, m_buffer + m_offset + 2, sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    AppHeader &sequence(const std::uint32_t value) SBE_NOEXCEPT {
        std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 2, &val, sizeof(std::uint32_t));
        return *this;
    }

    SBE_NODISCARD static const char *timestampMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t timestampId() SBE_NOEXCEPT { return -1; }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t timestampSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool timestampInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t timestampEncodingOffset()
        SBE_NOEXCEPT {
        return 6;
    }

    static SBE_CONSTEXPR std::uint64_t timestampNullValue() SBE_NOEXCEPT {
        return SBE_NULLVALUE_UINT64;
    }

    static SBE_CONSTEXPR std::uint64_t timestampMinValue() SBE_NOEXCEPT {
        return UINT64_C(0x0);
    }

    static SBE_CONSTEXPR std::uint64_t timestampMaxValue() SBE_NOEXCEPT {
        return UINT64_C(0xfffffffffffffffe);
    }

    static SBE_CONSTEXPR std::size_t timestampEncodingLength() SBE_NOEXCEPT {
        return 8;
    }

    SBE_NODISCARD std::uint64_t timestamp() const SBE_NOEXCEPT {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset + 6, sizeof(std::uint64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AppHeader &timestamp(const std::uint64_t value) SBE_NOEXCEPT {
        std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 6, &val, sizeof(std::uint64_t));
        return *this;
    }

    SBE_NODISCARD static const char *statusCodeMetaAttribute(
        const MetaAttribute metaAttribute) SBE_NOEXCEPT {
        switch (metaAttribute) {
            case MetaAttribute::PRESENCE:
                return "required";
            default:
                return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t statusCodeId() SBE_NOEXCEPT {
        return -1;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t statusCodeSinceVersion()
        SBE_NOEXCEPT {
        return 0;
    }

    SBE_NODISCARD bool statusCodeInActingVersion() SBE_NOEXCEPT { return true; }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t statusCodeEncodingOffset()
        SBE_NOEXCEPT {
        return 14;
    }

    static SBE_CONSTEXPR std::uint16_t statusCodeNullValue() SBE_NOEXCEPT {
        return SBE_NULLVALUE_UINT16;
    }

    static SBE_CONSTEXPR std::uint16_t statusCodeMinValue() SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(0);
    }

    static SBE_CONSTEXPR std::uint16_t statusCodeMaxValue() SBE_NOEXCEPT {
        return static_cast<std::uint16_t>(65534);
    }

    static SBE_CONSTEXPR std::size_t statusCodeEncodingLength() SBE_NOEXCEPT {
        return 2;
    }

    SBE_NODISCARD std::uint16_t statusCode() const SBE_NOEXCEPT {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset + 14, sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(val);
    }

    AppHeader &statusCode(const std::uint16_t value) SBE_NOEXCEPT {
        std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        std::memcpy(m_buffer + m_offset + 14, &val, sizeof(std::uint16_t));
        return *this;
    }

    template <typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> &operator<<(
        std::basic_ostream<CharT, Traits> &builder, AppHeader &writer) {
        builder << '{';
        builder << R"("version": )";
        builder << +writer.version();

        builder << ", ";
        builder << R"("sequence": )";
        builder << +writer.sequence();

        builder << ", ";
        builder << R"("timestamp": )";
        builder << +writer.timestamp();

        builder << ", ";
        builder << R"("statusCode": )";
        builder << +writer.statusCode();

        builder << '}';

        return builder;
    }
};

}  // namespace SBE

#endif
