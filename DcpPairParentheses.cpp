#include <stack>
#include <map>
#include <string>

// complicated solution

int isClosed(char symbol)
{
    // open brace
    if (symbol == '{' || symbol == '(' || symbol == '[')
        return 0;
    // closed brace
    else if (symbol == '}' || symbol == ')' || symbol == ']')
        return 1;
    // other character
    else
        return -1;
}

bool match(char current, char previous)
{
    // first type of pair
    if (current == '}' && previous == '{')
        return true;
    // second type of pair
    if (current == ')' && previous == '(')
        return true;
    // third type of pair
    if (current == ']' && previous == '[')
        return true;
    // no pair
    return false;
}

bool balance(std::string parentheses)
{
    // no characters
    if (parentheses.length() == 0)
        return false;
    
    std::stack<char> order;
    
    for (int i = 0; i < parentheses.length(); ++i)
    {
        char cur = parentheses[i];

        int closed = isClosed(cur);

        // wrong character
        if (closed == -1)
            return false;
        
        // closed brace
        if (closed == 1)
        {
            // first character is a closed brace
            if (i == 0)
                return false;

            // closed brace matches previous character
            char prev = order.top();
            if (match(cur, prev) == true)
                order.pop();
        }
        // open brace
        else
            order.push(parentheses[i]);
    }

    return order.empty();
}

// clean solution

// Explanation : This problem can only be solved through the use of a stack, making it easy to write and run in O(n) time.
// You can compare these braces as plates and their respective lids, piled up, or as russian dolls (even better).
// The whole process is to go through the string, and keep adding plates to the stack, piling them up.
// And whenever you encounter a lid, try to match it with the plate on top of the stack that was just added.
// If they match, remove the plate from the stack, then continue. If not, then the string is not valid.
// Keep doing that until you reach the end of the string. If all plates and lids matched to one another in the process, the stack will be empty.
// At the end, check if the stack is empty to know if the string is valid

bool valid(std::string s)
{
    std::stack<char> stack;
    std::map<char, char> braces = {{'}', '{'}, {')', '('}, {']', '['}};

    for (char c : s)
    {
        // closed brace -> check if can be matched with previous character
        if (braces.count(c))
        {
            // closed brace matches previous character in stack -> great, continue
            if (stack.empty() == false && stack.top() == braces[c])
                stack.pop();
            // if no character in stack or wrong character -> string is invalid
            else
                return false;
        }
        // open brace (or any other character) -> add it to the stack to be matched later
        else
            stack.push(c);
    }
    // return if all braces matched -> otherwise string is invalid
    return stack.empty();
}