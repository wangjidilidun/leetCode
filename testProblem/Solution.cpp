#include "Solution.h"
#include <cmath>

bool judgeVowel(char c)
{
	char vowels[] = {'a', 'e', 'i', 'o', 'u','A','E','I','O','U'};
	for (int i = 0; i < 10; i++)
	{
		if (vowels[i]==c)
		{
			return true;
		}
	}
	return false;
}
string Solution::reverseVowels(string s)
{
	string strVowels;
	string strTemp;
	for(int i = 0; i < s.length();i++)
	{
		if (judgeVowel(s[i]))
		{
			strVowels+=s[i];
		}
	}
	
	for(int i = 0, k = strVowels.length()-1; i < s.length(); i++)
	{
		if (judgeVowel(s[i]) && k>=0)
		{
			strTemp += strVowels[k];
			k--;
		}
		else
		{
			strTemp += s[i];
		}
	}

	return strTemp;
}

string Solution::reverseString(string s)
{
	string strTemp;
	for (int i = s.length()-1; i >= 0; i--)
	{
		strTemp+=s[i];
	}
	return strTemp;
}

int Solution::integerBreak(int n)
{
	int nCount = 0, nYushu = 0;
	int nMax = 1;
	if (n==2)
		return 1;
	else if(n==3)
		return 2;
	else
	{
		nCount = n / 3;
		nYushu = n % 3;
		if (1==nYushu)
		{
			for (int i = 0; i < nCount - 1; i++)
			{
				nMax = nMax * 3;
			}
			nMax = nMax * (3 + 1);
		}
		else
		{
			for (int i = 0; i < nCount; i++)
			{
				nMax = nMax * 3;
			}
			if (0!=nYushu)
			{
				nMax = nMax * nYushu;
			}
		}
		return nMax;
	}
	
	
}

bool Solution::isPowerOfThree(int n)
{
	// return n > 0 && 1162261467 % n == 0;
	double nCishu;
	nCishu = log((double)n)/log(4.0);
	nCishu = nCishu - (int)nCishu;
	if (abs(nCishu - 1) < 0.0001 || abs(nCishu + 1) < 1.0001)
		return true;
	else
		return false;
}

