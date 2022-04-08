/*
    Copyright (c) 2015-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#include "GitRepositoryTests.hpp"
#include "GitTaskFactoryTests.hpp"
#include <Ishiko/TestFramework.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyGit");

    theTestHarness.context().setTestOutputDirectory("../../output");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<GitRepositoryTests>();
    theTests.append<GitTaskFactoryTests>();

    return theTestHarness.run();
}
