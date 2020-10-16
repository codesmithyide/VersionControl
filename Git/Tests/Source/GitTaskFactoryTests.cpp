/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#include "GitTaskFactoryTests.h"
#include "CodeSmithy/VersionControl/Git/GitTaskFactory.h"
#include <boost/filesystem/operations.hpp>

using namespace Ishiko::Tests;

GitTasksTests::GitTasksTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "GitTasks tests", environment)
{
    append<HeapAllocationErrorsTest>("CreateInitTask test 1", CreateInitTaskTest1);
}

void GitTasksTests::CreateInitTaskTest1(Test& test)
{
    boost::filesystem::path outputPath(test.environment().getTestOutputDirectory() /
        "GitTasksTests_CreateInitTaskTest1");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    std::unique_ptr<CodeSmithy::Task> task = CodeSmithy::GitTaskFactory::CreateInitTask(repository,
        outputPath.string());
    task->run();

    // TODO : some way to compare directories and make sure it looks good.
    // Or run some checks on the repo, I don't know.
    ISHTF_PASS();
}
