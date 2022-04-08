/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/version-control/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_VERSIONCONTROL_GIT_GITTASKFACTORY_H_
#define _CODESMITHY_VERSIONCONTROL_GIT_GITTASKFACTORY_H_

#include "GitRepository.h"
#include <Ishiko/UserTasks.hpp>
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
