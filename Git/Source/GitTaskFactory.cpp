/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#include "GitTaskFactory.h"
#include "CodeSmithy/Tasks/SyncFunctionTask.h"

namespace CodeSmithy
{
    
std::unique_ptr<Task> GitTaskFactory::CreateInitTask(GitRepository& repository, const std::string& path)
{
    return std::unique_ptr<Task>(new SyncFunctionTask(
        [&repository, path]() mutable
        {
            repository.init(path);
        }
    ));
}

std::unique_ptr<Task> GitTaskFactory::CreateCloneTask(GitRepository& repository, const std::string& url,
    const std::string& clonePath)
{
    return std::unique_ptr<Task>(new SyncFunctionTask(
        [&repository, url, clonePath]() mutable
        {
            repository.clone(url, clonePath);
        }
    ));
}

std::unique_ptr<Task> GitTaskFactory::CreateOpenTask(GitRepository& repository, const std::string& path)
{
    return std::unique_ptr<Task>(new SyncFunctionTask(
        [&repository, path]() -> void
        {
            repository.open(path);
        }
    ));
}

}
