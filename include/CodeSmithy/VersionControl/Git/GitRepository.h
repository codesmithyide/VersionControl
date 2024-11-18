// SPDX-FileCopyrightText: 2015-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHY_VERSIONCONTROL_GIT_GITREPOSITORY_H_
#define _CODESMITHY_VERSIONCONTROL_GIT_GITREPOSITORY_H_

#include <git2.h>
#include <string>

namespace CodeSmithy
{

/**
    This class is a wrapper around libgit2 to interact
    with Git repositories.
*/
class GitRepository
{
public:
    GitRepository();
    GitRepository(const GitRepository& other) = delete;
    ~GitRepository();

    void init(const std::string& path);
    // TODO url can actually be a file path, but in that case the clone may have 
    // hard links to the cloned repo, that may be some behavior I want to change
    void clone(const std::string& url, const std::string& clonePath);
    void open(const std::string& path);

    void checkout();
    void branch();

    void fetch();
    void merge();
    void pull();

    bool checkIfRepository(const std::string& path) const;

private:
    git_repository* m_repository;
};

}

#include "linkoptions.h"

#endif
