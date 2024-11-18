// SPDX-FileCopyrightText: 2016-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHY_VERSIONCONTROL_GIT_GITERRORCATEGORY_H
#define GUARD_CODESMITHY_VERSIONCONTROL_GIT_GITERRORCATEGORY_H

#include <Ishiko/Errors.hpp>

namespace CodeSmithy
{
    
class GitErrorCategory : public Ishiko::ErrorCategory
{
public:
    enum class Value
    {
        generic_error = -1
    };

    static const GitErrorCategory& Get() noexcept;

    const char* name() const noexcept override;
    const char* message(int ev, char* buffer, size_t len) const noexcept override;

private:
    GitErrorCategory() noexcept = default;
};

void Throw(GitErrorCategory::Value value, const std::string& message, const char* file, int line);
bool operator==(const Ishiko::ErrorCode& error, GitErrorCategory::Value value);
bool operator!=(const Ishiko::ErrorCode& error, GitErrorCategory::Value value);

}

#endif
