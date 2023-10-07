/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/version-control/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_VERSIONCONTROL_GIT_GITERRORCATEGORY_H_
#define _CODESMITHY_VERSIONCONTROL_GIT_GITERRORCATEGORY_H_

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
    std::ostream& streamOut(int value, std::ostream& os) const override;

private:
    GitErrorCategory() noexcept = default;
};

void Throw(GitErrorCategory::Value value, const std::string& message, const char* file, int line);
bool operator==(const Ishiko::ErrorCondition& error, GitErrorCategory::Value value);
bool operator!=(const Ishiko::ErrorCondition& error, GitErrorCategory::Value value);

}

#endif
