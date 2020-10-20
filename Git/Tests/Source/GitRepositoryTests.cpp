/*
    Copyright (c) 2018-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/VersionControl/blob/master/LICENSE.txt
*/

#include "GitRepositoryTests.h"
#include "CodeSmithy/VersionControl/Git/GitRepository.h"
#include "CodeSmithy/VersionControl/Git/GitErrorCategory.h"
#include <Ishiko/Errors/Exception.h>
#include <boost/filesystem/operations.hpp>

using namespace Ishiko::Tests;

GitRepositoryTests::GitRepositoryTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "GitRepository tests", environment)
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
    ISHTF_PASS();
}

void GitRepositoryTests::InitTest1(Test& test)
{
    boost::filesystem::path outputPath(test.environment().getTestOutputDirectory() / "GitRepositoryTests_InitTest1");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    repository.init(outputPath.string());

    // TODO : some way to compare directories and make sure it looks good. Or run some checks on the repo, I don't know.
    ISHTF_PASS();
}

void GitRepositoryTests::CloneTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestOutputDirectory() / "GitRepositoryTests_InitTest1");
    boost::filesystem::path outputPath(test.environment().getTestOutputDirectory() / "GitRepositoryTests_CloneTest1");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    repository.clone(inputPath.string(), outputPath.string());

    // TODO : some way to compare directories and make sure it looks good. Or run some checks on the repo, I don't know.
    ISHTF_PASS();
}

void GitRepositoryTests::CloneTest2(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestOutputDirectory() / "doesnotexist");
    boost::filesystem::path outputPath(test.environment().getTestOutputDirectory() / "GitRepositoryTests_CloneTest2");
    boost::filesystem::remove_all(outputPath);

    CodeSmithy::GitRepository repository;
    try
    {
        repository.clone(inputPath.string(), outputPath.string());

        ISHTF_FAIL();
    }
    catch (const Ishiko::Exception& e)
    {
        ISHTF_FAIL_IF_NEQ(e.condition().value(), CodeSmithy::GitErrorCategory::eGeneric);
    }

    ISHTF_PASS();
}

void GitRepositoryTests::OpenTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestOutputDirectory() / "GitRepositoryTests_InitTest1");

    CodeSmithy::GitRepository repository;
    repository.open(inputPath.string());

    // TODO : some way to compare directories and make sure it looks good. Or run some checks on the repo, I don't know.
    ISHTF_PASS();
}

void GitRepositoryTests::CheckIfRepositoryTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestOutputDirectory() / "GitRepositoryTests_InitTest1");

    CodeSmithy::GitRepository repository;
    bool isRepository = repository.checkIfRepository(inputPath.string());

    ISHTF_FAIL_IF_NOT(isRepository);
    ISHTF_PASS();
}

void GitRepositoryTests::CheckIfRepositoryTest2(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestOutputDirectory());

    CodeSmithy::GitRepository repository;
    bool isRepository = repository.checkIfRepository(inputPath.string());
    
    ISHTF_FAIL_IF(isRepository);
    ISHTF_PASS();
}
