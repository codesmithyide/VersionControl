/*
    Copyright (c) 2020-2022 Xavier Leclercq
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
    enum EErrorValues
    {
        eGeneric = -1
    };

    static const GitErrorCategory& Get() noexcept;

    const char* name() const noexcept override;

private:
    GitErrorCategory() noexcept = default;
};

void Throw(GitErrorCategory::EErrorValues value, const std::string& message, const char* file, int line);

}

#endif
