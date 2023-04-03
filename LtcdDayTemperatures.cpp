#include <stack>
#include <vector>

// W.I.P
// Stack Problem

std::vector<int> solution(std::vector<int> temperatures)
{
    if (temperatures.size() == 0)
        return std::vector<int>(1, 0);

    std::vector<int> answer;

    std::stack<int> stack;
    stack.push(temperatures[0]);

    for (int i = 1; i < temperatures.size(); ++i)
    {
        if (temperatures[i] > stack.top())
        {
            answer.push_back(stack.size());
            stack.pop();
            stack.push(temperatures[i]);
        }
    }
}