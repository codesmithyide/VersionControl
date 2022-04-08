/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITTASKFACTORYTESTS_HPP_
#define _CODESMITHYIDE_VERSIONCONTROL_GIT_TESTS_GITTASKFACTORYTESTS_HPP_

#include <Ishiko/TestFramework.hpp>

class GitTaskFactoryTests : public Ishiko::TestSequence
{
public:
    GitTaskFactoryTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CreateInitTaskTest1(Ishiko::Test& test);
    static void CreateCloneTaskTest1(Ishiko::Test& test);
    static void CreateCloneTaskTest2(Ishiko::Test& test);
    static void CreateOpenTaskTest1(Ishiko::Test& test);
};

#endif
