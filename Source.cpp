#include <string>
#include <vector>
#include <map>

using namespace std;

multimap<int, std::string> repo[10];

int get_index(int num)
{
	if (0 == num)
		return 0;

	int denominator = 1000;
	int index = num / denominator;

	while (index == 0)
	{
		denominator /= 10;
		index = num / denominator;
	}

	return index;
}

int make_key(int num)
{
	if (0 == num)
		return 0;

	if (num > 0 && num < 10)
	{
		return num * 1110;//(num * 1000) + (num * 100) + (num * 10);
	}
	else if (num >= 10 && num < 100)
	{
		return (num * 100) + num;
	}
	else if (num >= 100 && num < 1000)
	{
		return (num * 10) + (num / 100);
	}
	else
	{
		return num;
	}
}

string solution(vector<int> numbers) {

	bool isZero = true;

	//for (auto& e : repo)
	//	e.clear();

	for (const auto& e : numbers)
	{
		int key = make_key(e);
		if (key == 0)
		{
			repo[0].emplace(0, "0");
			continue;
		}

		int index = get_index(e);
		repo[index].emplace(key, to_string(e));

		isZero = false;
	}

	if (isZero)
		return "0";

	string answer = "";
	for (int i = 9; i >= 0; --i)
	{
		auto iterS = repo[i].rbegin();
		auto iterE = repo[i].rend();

		for (; iterS != iterE; ++iterS)
			answer += iterS->second;
	}

	return answer;
}

int main()
{
	solution({ 3, 30, 34, 5, 9 });

	return 0;
}