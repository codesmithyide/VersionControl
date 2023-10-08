/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

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

std::ostream& GitErrorCategory::streamOut(int value, std::ostream& os) const
{
    switch (static_cast<Value>(value))
    {
    case Value::generic_error:
        os << "generic error";
        break;

    default:
        os << "unknown value";
        break;
    }
    return os;
}

void Throw(GitErrorCategory::Value value, const std::string& message, const char* file, int line)
{
    throw Exception(static_cast<int>(value), GitErrorCategory::Get(), message, file, line);
}

bool operator==(const Ishiko::ErrorCondition& error, GitErrorCategory::Value value)
{
    return ((&error.category() == &GitErrorCategory::Get()) && (error.value() == static_cast<int>(value)));
}

bool operator!=(const Ishiko::ErrorCondition& error, GitErrorCategory::Value value)
{
    return !(error == value);
}

}
