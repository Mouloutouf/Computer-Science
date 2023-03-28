#include <vector>
#include <iostream>

// This code does not work
// Need to check geek for geeks article on that

int GetUniqueWaysToClimb(int stairs, std::vector<int> possibleSteps)
{
    int result = 0;
    
    SumRecursive(result, possibleSteps, stairs, std::vector<int>());

    return result;
}

void SumRecursive(int& count, std::vector<int> numbers, int target, std::vector<int> partialSum)
{
    int solution = 0;
    for (int p : partialSum)
        solution += p;
    
    if (solution == target)
        count++;
    
    if (solution >= target)
        return;

    for (int i = 0; i < numbers.size(); ++i)
    {
        std::vector<int> remainingNumbers;
        for (int j = i + 1; j < numbers.size(); ++j)
            remainingNumbers.push_back(numbers[j]);
        
        std::vector<int> newPartialSum(partialSum);
        newPartialSum.push_back(numbers[i]);

        SumRecursive(count, remainingNumbers, target, newPartialSum);
    }
}