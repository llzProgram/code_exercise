// /*---------------------1. 敏感字符串加密--------------------------*/
// #include <iostream>
// #include <string>
// #include <sstream>
// #include <vector>
// using namespace std;

// vector<string> splitStr(string str)
// {
//     int len = str.length();
//     bool flag = false;
//     vector<string> res;
//     string tmp = "";

//     for(int i = 0; i < len; i++)
//     {
//         if(str[i] == '"')
//         {
//             tmp += str[i];
//             flag = !flag;
//         }
//         else if ((str[i] == '_') && (!flag))
//         {
//             if(tmp.size() != 0)
//             {
//                 res.push_back(tmp);
//                 tmp = "";
//             }
//             continue;
//         }
//         else
//         {
//             tmp += str[i];
//         }
//     }
//     if(tmp.size() != 0)
//     {
//         res.push_back(tmp);
//     }
//     return res;
// }

// int main()
// {
//     int index;
//     cin >> index;

//     string input;
//     cin >> input;

//     vector<string> strs = splitStr(input);

//     if(index > strs.size() - 1)
//     {
//         cout << "ERROPR" << endl;
//         return 0;
//     }
//     else
//     {
//         string output = "";
//         for(int i = 0; i < strs.size(); i++)
//         {
//             if (i == index)
//             {
//                 output += "******";
//             }
//             else
//             {
//                 output += strs[i];
//             }
//             if (i != strs.size() - 1) output += "_";
//         }
//         cout << output << endl;
//     }
    
//     return 0;
// } 


// /*---------------------2. 评委评分/比赛 --------------------------*/
// #include <iostream>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <algorithm>
// using namespace std;

// typedef struct _SCORE{
//     int index;
//     long int score_sum;
//     int score_cnt[11] = {0};
// }SCORE;

// vector<int> getNum(string s)
// {
//     vector<int> res;
//     stringstream ss(s);
//     string tmp;
//     while(getline(ss, tmp, ','))
//     {
//         res.push_back(stoi(tmp));
//     }
//     return res;
// }

// bool cmp (SCORE a, SCORE b)
// {
//     if (a.score_sum != b.score_sum)
//     {
//         return a.score_sum > b.score_sum;
//     }
//     else
//     {
//         for(int i = 10; i > 0; i--)
//         {
//             if (a.score_cnt[i] != b.score_cnt[i])
//             {
//                 return a.score_cnt[i] > b.score_cnt[i];
//             }
//         }
//     }
//     return false;
// }

// int main()
// {
//     int m, n;
//     string strMN;
//     getline(cin, strMN);
//     vector<int> vecMN = getNum(strMN);
//     if (vecMN.size() != 2)
//     {
//         cout << -1 << endl;
//         return 0;
//     }
//     else
//     {
//         m = vecMN[0];
//         n = vecMN[1];
//     }
//     if(m < 3 || m > 100 || n < 3 || n > 10)
//     {
//         cout << -1 << endl;
//         return 0;
//     }

//     vector<vector<int>> score_num;
//     vector<SCORE> all_score(n);
//     for(int i = 0; i < m; i++)
//     {
//         string input;
//         getline(cin, input);
//         vector<int> scoreVec = getNum(input);
//         if(scoreVec.size() != n)
//         {
//             cout << -1 << endl;
//             return 0;
//         }

//         for(int k = 0; k < scoreVec.size(); k++)
//         {
//             if(scoreVec[k] < 1 || scoreVec[k] > 10)
//             {
//                 cout << -1 << endl;
//                 return 0;
//             }
//             all_score[k].index = k + 1;
//             all_score[k].score_sum += scoreVec[k];
//             all_score[k].score_cnt[scoreVec[k]] ++;
//         }
//     }

//     sort(all_score.begin(), all_score.end(), cmp);

//     cout << all_score[0].index << ","
//         << all_score[1].index << ","
//         << all_score[2].index << endl;

//     return 0;
// }


/*---------------------3. 天然蓄水库 --------------------------*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);

    vector<int> input;
    int num;
    while(ss >> num)
    {
        input.push_back(num);
    }

    int n = input.size();
    if(n < 3)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> hight_sum(n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        hight_sum[i + 1] = hight_sum[i] + input[i];
    }

    int left = 0, right = n - 1;
    int best_left = -1, best_right = -1;
    long long int water_max = 0;

    while(left < right)
    {
        int min_hight = min(input[left], input[right]);
        int cnt_middle = right - left - 1;
        long long int water = cnt_middle * min_hight - (hight_sum[right] - hight_sum[left + 1]);

        if(water > water_max)
        {
            water_max = water;
            best_left = left;
            best_right = right;
        }
        else if (water == water_max)
        {
            if(right - left < best_right - best_left)
            {
                best_left = left;
                best_right = right;
            }
        }

        if(input[left] < input[right])
        {
            left++;
        }
        {
            right--;
        }
    }

    if (water_max <= 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << best_left << " " << best_right << ":" << water_max << endl;
    }

    return 0;
}
