#pragma once

//描述 ：给一个由数字组成的字符串，求出其可能恢复为的所有IP地址
//样例 ：给出字符串 "25525511135"，所有可能的IP地址为
//			{ 
//			"255.255.11.135"
//			"255.255.111.35"
//			}
#include <iostream>
#include <vector>

using namespace std;

class restoreIp
{
private:
	vector<string> ret;
	int pos[4];

public:
	bool check(string ip)
	{
		if (ip.size() == 1)
		{
			return "0" <= ip && ip <= "9";
		}
		if (ip.size() == 2)
		{
			return "10" <= ip && ip <= "99";
		}
		if (ip.size() == 3)
		{
			return "100" <= ip && ip <= "255";
		}
		return false;
	}

	void dfs(int dep, int maxDep, string &s, int start)
	{
		if (dep == maxDep)
		{
			if (start == s.size())
			{
				int beg = 0;
				string addr;
				for (int i = 0; i < maxDep; i++)
				{
					string ip(s, beg, pos[i] - beg + 1);
					beg = pos[i] + 1;
					addr += i == 0 ? ip : "." + ip;
				}
				ret.push_back(addr);
			}
			return;
		}

		for (int i = start; i < s.size(); i++)
		{
			string ip(s, start, i - start + 1);
			if (check(ip)){
				pos[dep] = i;
				dfs(dep + 1, 4, s, i + 1);
			}
			
		}
	}
	
	vector<string> restoreIpAddresses(string s)
	{
		ret.clear();
		dfs(0, 4, s, 0);
		return ret;
	}
};

