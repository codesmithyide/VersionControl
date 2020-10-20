/*
    Copyright (c) 2017-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#include "GitRepository.h"
#include "GitErrorCategory.h"

namespace CodeSmithy
{

GitRepository::GitRepository()
    : m_repository(0)
{
    git_libgit2_init();
}

GitRepository::~GitRepository()
{
    git_repository_free(m_repository);

    git_libgit2_shutdown();
}

void GitRepository::init(const std::string& path)
{
    // TODO: error handling
    int err = git_repository_init(&m_repository, path.c_str(), 0);
}

void GitRepository::clone(const std::string& url, const std::string& clonePath)
{
    // TODO
    int err = git_clone(&m_repository, url.c_str(), clonePath.c_str(), 0);
    if (err < 0)
    {
        char* msg = giterr_last()->message;
        Throw(GitErrorCategory::eGeneric, msg, __FILE__, __LINE__);
    }
}

void GitRepository::open(const std::string& path)
{
    // TODO: error handling
    int err = git_repository_open(&m_repository, path.c_str());
}

void GitRepository::checkout()
{
    // TODO
}

void GitRepository::branch()
{
    // TODO
}

void GitRepository::fetch()
{
    // TODO
}

void GitRepository::merge()
{
    // TODO
}

void GitRepository::pull()
{
    // TODO
}

bool GitRepository::checkIfRepository(const std::string& path) const
{
    return (git_repository_open_ext(NULL, path.c_str(), GIT_REPOSITORY_OPEN_NO_SEARCH, NULL) == 0);
}

}
