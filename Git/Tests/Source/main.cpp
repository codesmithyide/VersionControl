/*
    Copyright (c) 2015-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#include "Ishiko/TestFramework/TestFrameworkCore.h"

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyGit");

    return theTestHarness.run();
}
