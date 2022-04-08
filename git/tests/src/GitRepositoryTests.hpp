/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITREPOSITORYTESTS_HPP_
#define _CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITREPOSITORYTESTS_HPP_

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
