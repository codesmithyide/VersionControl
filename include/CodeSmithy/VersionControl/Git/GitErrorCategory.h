/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHY_VERSIONCONTROL_GIT_GITERRORCATEGORY_H_
#define _CODESMITHY_VERSIONCONTROL_GIT_GITERRORCATEGORY_H_

#include <Ishiko/Errors/ErrorCategory.h>
#include <Ishiko/Errors/Exception.h>

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
