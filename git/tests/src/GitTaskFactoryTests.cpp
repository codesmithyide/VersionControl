/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#include "GitTaskFactoryTests.hpp"
#include "CodeSmithy/VersionControl/Git/GitTaskFactory.h"
#include <boost/filesystem/operations.hpp>

using namespace Ishiko;

GitTaskFactoryTests::GitTaskFactoryTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "GitTaskFactory tests", context)
{
    append<HeapAllocationErrorsTest>("CreateInitTask test 1", CreateInitTaskTest1);
    append<HeapAllocationErrorsTest>("CreateCloneTask test 1", CreateCloneTaskTest1);
    append<HeapAllocationErrorsTest>("CreateCloneTask test 2", CreateCloneTaskTest2);
    append<HeapAllocationErrorsTest>("CreateOpenTask test 1", CreateOpenTaskTest1);
}

void GitTaskFactoryTests::CreateInitTaskTest1(Test& test)
{
    boost::filesystem::path outputPath(test.context().getTestOutputDirectory() /
        "GitTaskFactoryTests_CreateInitTaskTest1");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    std::unique_ptr<UserTask> task = CodeSmithy::GitTaskFactory::CreateInitTask(repository, outputPath.string());
    task->run();

    // TODO : some way to compare directories and make sure it looks good.
    // Or run some checks on the repo, I don't know.
    ISHIKO_TEST_PASS();
}

void GitTaskFactoryTests::CreateCloneTaskTest1(Test& test)
{
    boost::filesystem::path inputPath(test.context().getTestOutputDirectory() /
        "GitTaskFactoryTests_CreateInitTaskTest1");
    boost::filesystem::path outputPath(test.context().getTestOutputDirectory() /
        "GitTaskFactoryTests_CreateCloneTaskTest1");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    std::unique_ptr<UserTask> task = CodeSmithy::GitTaskFactory::CreateCloneTask(repository, inputPath.string(),
        outputPath.string());
    task->run();

    // TODO : some way to compare directories and make sure it looks good.
    // Or run some checks on the repo, I don't know.
    ISHIKO_TEST_FAIL_IF_NEQ(task->status(), UserTask::EStatus::eCompleted);
    ISHIKO_TEST_PASS();
}

void GitTaskFactoryTests::CreateCloneTaskTest2(Test& test)
{
    boost::filesystem::path inputPath(test.context().getTestOutputDirectory() / "doesnotexist");
    boost::filesystem::path outputPath(test.context().getTestOutputDirectory() /
        "GitTaskFactoryTests_CreateCloneTaskTest1");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    std::unique_ptr<UserTask> task = CodeSmithy::GitTaskFactory::CreateCloneTask(repository, inputPath.string(),
        outputPath.string());
    task->run();

    ISHIKO_TEST_FAIL_IF_NEQ(task->status(), UserTask::EStatus::eFailed);
    ISHIKO_TEST_PASS();
}

void GitTaskFactoryTests::CreateOpenTaskTest1(Test& test)
{
    boost::filesystem::path inputPath(test.context().getTestOutputDirectory() /
        "GitTaskFactoryTests_CreateInitTaskTest1");

    CodeSmithy::GitRepository repository;
    std::unique_ptr<UserTask> task = CodeSmithy::GitTaskFactory::CreateOpenTask(repository, inputPath.string());
    task->run();

    // TODO : some way to compare directories and make sure it looks good. Or run some checks on the repo, I don't know.
    ISHIKO_TEST_PASS();
}
