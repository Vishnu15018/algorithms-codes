#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


string Longest_c_subseq(string &str1, string &str2)
{
	int x = str1.length();
	int n = str2.length();

	int L[x+1][n+1];


	for (int i=0; i<=x; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (str1[i-1] == str2[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}


	int index = L[x][n];


	string Longest_c_subseq(index+1, '\0');

	int i = x, j = n;
	while (i > 0 && j > 0)
	{

		if (str1[i-1] == str2[j-1])
		{
			Longest_c_subseq[index-1] = str1[i-1];
			i--;
			j--;


			index--;
		}


		else if (L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}

	return Longest_c_subseq;
}


string long_palindr_Sub(string &str)
{

	string rev = str;
	reverse(rev.begin(), rev.end());


	return Longest_c_subseq(str, rev);
}

int main()
{
	string str1 = "";
    cout<<"Please enter the string : ";
    cin>>str1;
    cout<<"Longest palindrome subsequence : "<<endl;
	cout << long_palindr_Sub(str1);
	return 0;
}