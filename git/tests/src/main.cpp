// SPDX-FileCopyrightText: 2015-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "GitRepositoryTests.hpp"
#include "GitTaskFactoryTests.hpp"
#include <Ishiko/TestFramework.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyGit");

    theTestHarness.context().setOutputDirectory("../../output");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<GitRepositoryTests>();
    theTests.append<GitTaskFactoryTests>();

    return theTestHarness.run();
}
