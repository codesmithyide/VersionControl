// SPDX-FileCopyrightText: 2015-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITREPOSITORYTESTS_HPP
#define GUARD_CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITREPOSITORYTESTS_HPP

#include <Ishiko/TestFramework.hpp>

class GitRepositoryTests : public Ishiko::TestSequence
{
public:
    GitRepositoryTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CreationTest1(Ishiko::Test& test);
    static void InitTest1(Ishiko::Test& test);
    static void CloneTest1(Ishiko::Test& test);
    static void CloneTest2(Ishiko::Test& test);
    static void OpenTest1(Ishiko::Test& test);
    static void CheckIfRepositoryTest1(Ishiko::Test& test);
    static void CheckIfRepositoryTest2(Ishiko::Test& test);
};

#endif
