// SPDX-FileCopyrightText: 2015-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHY_VERSIONCONTROL_GIT_GITTASKFACTORY_H_
#define _CODESMITHY_VERSIONCONTROL_GIT_GITTASKFACTORY_H_

#include "GitRepository.h"
#include <Ishiko/Workflows.hpp>
#include <string>

namespace CodeSmithy
{

class GitTaskFactory
{
public:
    static std::unique_ptr<Ishiko::UserTask> CreateInitTask(GitRepository& repository, const std::string& path);
    static std::unique_ptr<Ishiko::UserTask> CreateCloneTask(GitRepository& repository, const std::string& url,
        const std::string& clonePath);
    static std::unique_ptr<Ishiko::UserTask> CreateOpenTask(GitRepository& repository, const std::string& path);
};

}

#endif
