/*
    Copyright (c) 2020 Xavier Leclercq
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

void Throw(GitErrorCategory::EErrorValues value, const std::string& message, const char* file, int line)
{
    throw Exception(value, GitErrorCategory::Get(), message, file, line);
}

}
