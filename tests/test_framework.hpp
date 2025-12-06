/**
 * @file test_framework.hpp
 * @brief Simple test framework for unit testing
 * @author Ermurachi Dmitri
 * @date 2025
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

namespace test {

class TestResult {
public:
    bool passed;
    std::string testName;
    std::string message;
    
    TestResult(bool p, const std::string& name, const std::string& msg = "")
        : passed(p), testName(name), message(msg) {}
};

class TestSuite {
private:
    std::string suiteName;
    std::vector<TestResult> results;
    int passedCount;
    int failedCount;

public:
    TestSuite(const std::string& name) : suiteName(name), passedCount(0), failedCount(0) {}
    
    void addResult(const TestResult& result) {
        results.push_back(result);
        if (result.passed) {
            passedCount++;
        } else {
            failedCount++;
        }
    }
    
    void printSummary() const {
        std::cout << "\n=== Test Suite: " << suiteName << " ===\n";
        std::cout << "Passed: " << passedCount << "\n";
        std::cout << "Failed: " << failedCount << "\n";
        std::cout << "Total: " << (passedCount + failedCount) << "\n";
        
        if (failedCount > 0) {
            std::cout << "\nFailed Tests:\n";
            for (const auto& result : results) {
                if (!result.passed) {
                    std::cout << "  - " << result.testName;
                    if (!result.message.empty()) {
                        std::cout << ": " << result.message;
                    }
                    std::cout << "\n";
                }
            }
        }
        std::cout << "\n";
    }
    
    bool allPassed() const {
        return failedCount == 0;
    }
    
    int getPassedCount() const { return passedCount; }
    int getFailedCount() const { return failedCount; }
};

// Test assertion macros
#define ASSERT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            throw std::string("ASSERT_TRUE failed: " #condition); \
        } \
    } while(0)

#define ASSERT_FALSE(condition) \
    do { \
        if (condition) { \
            throw std::string("ASSERT_FALSE failed: " #condition); \
        } \
    } while(0)

#define ASSERT_EQ(expected, actual) \
    do { \
        auto exp_val = (expected); \
        auto act_val = (actual); \
        if (exp_val != act_val) { \
            throw std::string("ASSERT_EQ failed: values are not equal"); \
        } \
    } while(0)

#define ASSERT_EQ_STR(expected, actual) \
    do { \
        std::string exp_str = (expected); \
        std::string act_str = (actual); \
        if (exp_str != act_str) { \
            throw std::string("ASSERT_EQ_STR failed: expected '" + exp_str + \
                            "', got '" + act_str + "'"); \
        } \
    } while(0)

#define ASSERT_NE(expected, actual) \
    do { \
        if ((expected) == (actual)) { \
            throw std::string("ASSERT_NE failed: values are equal"); \
        } \
    } while(0)

#define RUN_TEST(suite, testName, testFunc) \
    do { \
        try { \
            testFunc(); \
            suite.addResult(TestResult(true, testName)); \
            std::cout << "  [PASS] " << testName << "\n"; \
        } catch (const std::string& msg) { \
            suite.addResult(TestResult(false, testName, msg)); \
            std::cout << "  [FAIL] " << testName << " - " << msg << "\n"; \
        } catch (...) { \
            suite.addResult(TestResult(false, testName, "Unknown exception")); \
            std::cout << "  [FAIL] " << testName << " - Unknown exception\n"; \
        } \
    } while(0)

} // namespace test

