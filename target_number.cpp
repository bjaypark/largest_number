#include <string>
#include <vector>

using namespace std;

vector<int> oldNum;
vector<int> newNum;

int solution(vector<int> numbers, int target) {

    const int MAX = 1 << 20;
    int answer = 0;
    
	newNum.reserve(MAX);
	oldNum.reserve(MAX);
	oldNum.emplace_back(0);

	for (const int num : numbers)
	{
		for (const int e : oldNum)
		{
			newNum.emplace_back(e + num);
			newNum.emplace_back(e - num);
		}
		oldNum = newNum;
		newNum.clear();
	}

	for (const int e : oldNum)
	{
		if (e == target)
			++answer;
	}

	return answer;
}