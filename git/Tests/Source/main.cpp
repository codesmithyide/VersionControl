/*
    Copyright (c) 2015-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#include "GitRepositoryTests.h"
#include "GitTaskFactoryTests.h"
#include <Ishiko/Tests.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyGit");

    theTestHarness.environment().setTestOutputDirectory("../../TestOutput");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<GitRepositoryTests>();
    theTests.append<GitTaskFactoryTests>();

    return theTestHarness.run();
}
