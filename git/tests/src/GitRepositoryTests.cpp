/*
    Copyright (c) 2018-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#include "GitRepositoryTests.hpp"
#include "CodeSmithy/VersionControl/Git/GitRepository.h"
#include "CodeSmithy/VersionControl/Git/GitErrorCategory.h"
#include <Ishiko/Errors.hpp>
#include <boost/filesystem/operations.hpp>

using namespace Ishiko;

GitRepositoryTests::GitRepositoryTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "GitRepository tests", context)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("init test 1", InitTest1);
    append<HeapAllocationErrorsTest>("clone test 1", CloneTest1);
    append<HeapAllocationErrorsTest>("clone test 2", CloneTest2);
    append<HeapAllocationErrorsTest>("open test 1", OpenTest1);
    append<HeapAllocationErrorsTest>("checkIfRepository test 1", CheckIfRepositoryTest1);
    append<HeapAllocationErrorsTest>("checkIfRepository test 2", CheckIfRepositoryTest2);
}

void GitRepositoryTests::CreationTest1(Test& test)
{
    CodeSmithy::GitRepository repository;

    ISHIKO_TEST_PASS();
}

void GitRepositoryTests::InitTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath("GitRepositoryTests_InitTest1");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    repository.init(outputPath.string());

    // TODO : some way to compare directories and make sure it looks good. Or run some checks on the repo, I don't know.
    ISHIKO_TEST_PASS();
}

void GitRepositoryTests::CloneTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getOutputPath("GitRepositoryTests_InitTest1");
    boost::filesystem::path outputPath = test.context().getOutputPath("GitRepositoryTests_CloneTest1");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    repository.clone(inputPath.string(), outputPath.string());

    // TODO : some way to compare directories and make sure it looks good. Or run some checks on the repo, I don't know.
    ISHIKO_TEST_PASS();
}

void GitRepositoryTests::CloneTest2(Test& test)
{
    boost::filesystem::path inputPath = test.context().getOutputPath("doesnotexist");
    boost::filesystem::path outputPath = test.context().getOutputPath("GitRepositoryTests_CloneTest2");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    try
    {
        repository.clone(inputPath.string(), outputPath.string());

        ISHIKO_TEST_FAIL();
    }
    catch (const Ishiko::Exception& e)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(e.code(), CodeSmithy::GitErrorCategory::Value::generic_error);
    }

    ISHIKO_TEST_PASS();
}

void GitRepositoryTests::OpenTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getOutputPath("GitRepositoryTests_InitTest1");

    CodeSmithy::GitRepository repository;
    repository.open(inputPath.string());

    // TODO : some way to compare directories and make sure it looks good. Or run some checks on the repo, I don't know.
    ISHIKO_TEST_PASS();
}

void GitRepositoryTests::CheckIfRepositoryTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getOutputPath("GitRepositoryTests_InitTest1");

    CodeSmithy::GitRepository repository;
    bool isRepository = repository.checkIfRepository(inputPath.string());

    ISHIKO_TEST_FAIL_IF_NOT(isRepository);
    ISHIKO_TEST_PASS();
}

void GitRepositoryTests::CheckIfRepositoryTest2(Test& test)
{
    boost::filesystem::path inputPath = test.context().getOutputDirectory();

    CodeSmithy::GitRepository repository;
    bool isRepository = repository.checkIfRepository(inputPath.string());
    
    ISHIKO_TEST_FAIL_IF(isRepository);
    ISHIKO_TEST_PASS();
}
