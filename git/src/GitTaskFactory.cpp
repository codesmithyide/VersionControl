// SPDX-FileCopyrightText: 2015-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "GitTaskFactory.h"
#include <Ishiko/Workflows.hpp>

using namespace Ishiko;

namespace CodeSmithy
{
    
std::unique_ptr<UserTask> GitTaskFactory::CreateInitTask(GitRepository& repository, const std::string& path)
{
    return std::unique_ptr<UserTask>(
        new SyncFunctionTask(
            [&repository, path]() mutable
            {
                repository.init(path);
            }
        ));
}

std::unique_ptr<UserTask> GitTaskFactory::CreateCloneTask(GitRepository& repository, const std::string& url,
    const std::string& clonePath)
{
    return std::unique_ptr<UserTask>(
        new SyncFunctionTask(
            [&repository, url, clonePath]() mutable
            {
                repository.clone(url, clonePath);
            }
        ));
}

std::unique_ptr<UserTask> GitTaskFactory::CreateOpenTask(GitRepository& repository, const std::string& path)
{
    return std::unique_ptr<UserTask>(
        new SyncFunctionTask(
            [&repository, path]() -> void
            {
                repository.open(path);
            }
        ));
}

}
