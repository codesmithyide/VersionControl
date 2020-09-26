/*
    Copyright (c) 2018-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITREPOSITORYTESTS_H_
#define _CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITREPOSITORYTESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class GitRepositoryTests : public Ishiko::Tests::TestSequence
{
public:
    GitRepositoryTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void CreationTest1(Ishiko::Tests::Test& test);
    static void InitTest1(Ishiko::Tests::Test& test);
    static void CloneTest1(Ishiko::Tests::Test& test);
    static void OpenTest1(Ishiko::Tests::Test& test);
    static void CheckIfRepositoryTest1(Ishiko::Tests::Test& test);
    static void CheckIfRepositoryTest2(Ishiko::Tests::Test& test);
};

#endif
