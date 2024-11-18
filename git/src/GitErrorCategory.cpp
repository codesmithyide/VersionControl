// SPDX-FileCopyrightText: 2016-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "GitErrorCategory.h"

using namespace Ishiko;

namespace CodeSmithy
{

const GitErrorCategory& GitErrorCategory::Get() noexcept
{
    static GitErrorCategory theCategory;
    return theCategory;
}

const char* GitErrorCategory::name() const noexcept
{
    return "CodeSmithy::GitErrorCategory";
}

const char* GitErrorCategory::message(int ev, char* buffer, size_t len) const noexcept
{
    switch (static_cast<Value>(ev))
    {
    case Value::generic_error:
        return "generic error";

    default:
        return "unknown value";
    }
}

void Throw(GitErrorCategory::Value value, const std::string& message, const char* file, int line)
{
    throw Exception(static_cast<int>(value), GitErrorCategory::Get(), message, file, line);
}

bool operator==(const Ishiko::ErrorCode& error, GitErrorCategory::Value value)
{
    return ((&error.category() == &GitErrorCategory::Get()) && (error.value() == static_cast<int>(value)));
}

bool operator!=(const Ishiko::ErrorCode& error, GitErrorCategory::Value value)
{
    return !(error == value);
}

}
