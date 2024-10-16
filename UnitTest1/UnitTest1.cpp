#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\admin\source\repos\Project_6.2_rec\Project_6.2_rec\lab.6.2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCreate)
        {
            const int n = 5;
            int arr[n];
            int Low = 1;
            int High = 10;

            Create(arr, n, Low, High, 0);

            for (int i = 0; i < n; i++) {
                Assert::IsTrue(arr[i] >= Low && arr[i] <= High);
            }
        }

        TEST_METHOD(TestMax)
        {
            const int n = 6;
            int arr[n] = { 3, 10, 2, 5, 8, 1 };

            int expectedMax = 10; 
            int actualMax = Max(arr, n, 1, arr[0]); 

            Assert::AreEqual(expectedMax, actualMax);
        }

        TEST_METHOD(TestMin)
        {
            const int n = 6;
            int arr[n] = { 3, 10, 2, 5, 8, 1 };

            int expectedMin = 1; 
            int actualMin = Min(arr, n, 1, arr[0]); 

            Assert::AreEqual(expectedMin, actualMin);
        }

        TEST_METHOD(TestMaxIndex)
        {
            const int n = 6;
            int arr[n] = { 3, 10, 2, 5, 8, 1 };
            int max = Max(arr, n, 1, arr[0]);
            int expectedIndex = 1; 
            int actualIndex = MaxIndex(arr, n, max, 0);

            Assert::AreEqual(expectedIndex, actualIndex);
        }

        TEST_METHOD(TestMinIndex)
        {
            const int n = 6;
            int arr[n] = { 3, 10, 2, 5, 8, 1 };
            int min = Min(arr, n, 1, arr[0]); 
            int expectedIndex = 5; 
            int actualIndex = MinIndex(arr, n, min, 0);

            Assert::AreEqual(expectedIndex, actualIndex);
        }

        TEST_METHOD(TestSwapMinMax)
        {
            const int n = 5;
            int arr[n] = { 6, 10, 2, 5, 8 }; 

            SwapMinMax(arr, n);

            Assert::AreEqual(10, arr[2]);
            Assert::AreEqual(2, arr[1]);  
        }
    };
}