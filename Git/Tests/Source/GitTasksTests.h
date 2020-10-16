/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITTASKSTESTS_H_
#define _CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITTASKSTESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class GitTasksTests : public Ishiko::Tests::TestSequence
{
public:
    GitTasksTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void CreateInitTaskTest1(Ishiko::Tests::Test& test);

};

#endif
