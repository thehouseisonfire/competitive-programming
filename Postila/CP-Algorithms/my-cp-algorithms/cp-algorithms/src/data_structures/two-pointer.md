# Two Pointer Algorithm

## Overview

- Note: Added my me.

The Two Pointer Algorithm is a technique used for efficiently solving problems with linear data structures like arrays or linked lists. It involves using two pointers to traverse the data structure and perform operations based on certain conditions.

## Basic Idea

The basic idea behind the Two Pointer Algorithm is to maintain two pointers that traverse the data structure in a way that reduces the time complexity. The pointers move towards each other or in a specific pattern based on the problem requirements.

## Algorithm Steps

1. **Initialize Pointers:**
   - Initialize two pointers, usually at the beginning or end of the data structure.

2. **Move Pointers:**
   - Move the pointers towards each other, closer or farther based on the problem requirements.
   - Update pointers based on specific conditions.

3. **Check Conditions:**
   - Check conditions at each step to determine if the solution is found or if the pointers need to be adjusted.

4. **Repeat:**
   - Repeat steps 2 and 3 until the pointers meet or fulfill the problem requirements.

## Common Use Cases

1. **Array Sum/Pair Sum:**
   - Finding pairs in a sorted/unsorted array that sum up to a given target.

2. **Search in a Sorted Array:**
   - Searching for a target element efficiently in a sorted array.

3. **Palindrome Check:**
   - Checking if a given string or array is a palindrome.

4. **Trapping Rain Water:**
   - Calculating the amount of water that can be trapped between bars in an elevation map.

## Example

### Two Sum Problem

```cpp
int main() {
    // Example input vector
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    // Sorting the input vector
    std::sort(nums.begin(), nums.end());
    // Initializing two pointers
    int left = 0;
    int right = nums.size() - 1;
    // Two Pointer Algorithm
    while (left < right) {
        int currentSum = nums[left] + nums[right];
        if (currentSum == target) {
            // Solution found
            std::cout << "Pair found: [" << nums[left] << ", " << nums[right] << "]" << std::endl;
            return 0;
        } else if (currentSum < target) {
            // Move left pointer to the right
            ++left;
        } else {
            // Move right pointer to the left
            --right;
        }
    }
    // No solution found
    std::cout << "No pair found." << std::endl;
    return 0;
}
```

```cpp
#include <cassert>
#include <iostream>
#include <vector>

/**
 * @brief Calculates the maximum water that can be trapped between vertical
 * lines on a 2D plane.
 *
 * Given an array of non-negative integers representing vertical lines on a 2D
 * plane, where the width of each line is 1, the function finds two lines that,
 * together with the x-axis, form a container that can hold the most water.
 *
 * The problem can be efficiently solved using a two-pointer approach. We
 * initialize two pointers, 'left' and 'right', at the beginning and end of the
 * array, respectively. The width of the container is determined by the
 * difference between the 'right' and 'left' pointers. To maximize the water
 * trapped, we choose the minimum height between the lines at the 'left' and
 * 'right' positions. We then calculate the water trapped by multiplying the
 * width and height. We move the pointers towards each other, adjusting them
 * based on the shorter line, as moving the pointer with the smaller height has
 * the potential to increase the water volume.
 *
 * @param height Vector representing the heights of vertical lines.
 * @return int Maximum water that can be trapped.
 */

int maxArea(const std::vector<int>& height) {
    int maxWater = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int width = right - left;
        int h = std::min(height[left], height[right]);
        int currentWater = width * h;
        maxWater = std::max(maxWater, currentWater);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}
/**
 * @brief Tests the maxArea function with various test cases.
 *
 * The function iterates through each test case, calculates the result using the
 * maxArea function, checks if the result matches the expected result, and
 * prints a success message for each test case.
 */

void testContainerWithMostWater() {
    // Test cases with expected maximum water values
    std::vector<std::pair<std::vector<int>, int>> testCases = {
        { {1, 8, 6, 2, 5, 4, 8, 3, 7}, 49 },
        { {1, 1}, 1 },
        { {4, 3, 2, 1, 4}, 16 },
        { {1, 2, 1}, 2 },
    };
    for (const auto& testCase : testCases) {
        const std::vector<int>& input = testCase.first;
        int expected = testCase.second;

        // Calculate the result using the maxArea function
        int result = maxArea(input);
        assert(result == expected);
        std::cout << "Test passed!" << std::endl;
    }
}

int main() {
    testContainerWithMostWater();
    return 0;
}
```
