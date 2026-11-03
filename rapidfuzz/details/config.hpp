/* SPDX-License-Identifier: MIT */
/* Copyright © 2020 Max Bachmann */

#pragma once

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#    define RAPIDFUZZ_DEDUCTION_GUIDES
#endif

/* older versions of msvc have bugs in their if constexpr support
 * see https://github.com/rapidfuzz/rapidfuzz-cpp/issues/122
 * since we don't know the exact version this was fixed in, use the earliest we could test
 */
#if defined(_MSC_VER) && _MSC_VER < 1920
#    define RAPIDFUZZ_IF_CONSTEXPR_AVAILABLE 0
#    define RAPIDFUZZ_IF_CONSTEXPR if
#elif ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#    define RAPIDFUZZ_DEDUCTION_GUIDES
#    define RAPIDFUZZ_IF_CONSTEXPR_AVAILABLE 1
#    define RAPIDFUZZ_IF_CONSTEXPR if constexpr
#else
#    define RAPIDFUZZ_IF_CONSTEXPR_AVAILABLE 0
#    define RAPIDFUZZ_IF_CONSTEXPR if
#endif

#if defined(_MSC_VER) && !defined(__clang__) && _MSC_VER < 1910
#    define RAPIDFUZZ_CONSTEXPR_CXX14 inline
#elif ((defined(_MSVC_LANG) && _MSVC_LANG >= 201402L) || __cplusplus >= 201402L)
#    define RAPIDFUZZ_CONSTEXPR_CXX14 constexpr
#else
#    define RAPIDFUZZ_CONSTEXPR_CXX14 inline
#endif
