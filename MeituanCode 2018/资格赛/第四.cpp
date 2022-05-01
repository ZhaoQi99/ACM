#include <iostream>
#include <math.h>
#include<algorithm>
#define EPSILON 1e-6

using namespace std;
/*
*/
//为了使用sort降序排列
int cmp(float a, float b)
{
    return a > b;
}

int main()
{
    int n, m, k, C;
    int loseRow = -1;//丢失的下标 第loseRow位选手
    int loseCol = -1;//丢失的下标 第loseCol轮成绩
    int weightSum = 0;

    cin >> n >> m >> k >> C;
    if (n < k || n > 500 || C > 500 || m > 6 || k <= 0 || C <= 0 || m <= 0)
    {
        return -1;
    }
    int(*score)[6] = new int[n][6];
    int *weight = new int[m];
    float *weightScore = new float[n];
    float *weightScoreTemp = new float[n];
    int *indexsTemp = new int[n];
    int *indexs = new int[n];
    int *max = new int[m];//保存每轮最大值

    for (int i = 0; i < m; i++)
    {
        cin >> weight[i];
        weightSum += weight[i];
        if (weight[i] < 0)
        {
            return -1;
        }
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cin >> score[i][j];
            if (score[i][j] == -1)
            {
                if (loseRow != -1)
                {
                    return -1;
                }
                loseRow = i;
                loseCol = j;
                score[i][j] = 0;
            }
        }
    }
    if (weightSum > 1000 || weightSum < 1 || loseRow == -1)
    {
        return -1;
    }
    for (int j = 0; j < m; j++)
    {
        max[j] = 0;
        for (int i = 0; i < n; i++)
        {
            if (score[i][j] > max[j])
            {
                max[j] = score[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        weightScore[i] = 0;
        weightScoreTemp[i] = 0;
        indexs[i] = 2;
        indexsTemp[i] = 2;
        for (int j = 0; j < m; j++)
        {
            if (max[j] != 0)
            {
                weightScore[i] += (score[i][j] * 1.0 / max[j]) * (1.0 * weight[j] / weightSum);
                weightScoreTemp[i] += (score[i][j] * 1.0 / max[j]) * (1.0 * weight[j] / weightSum);
            }
        }
    }

    sort(weightScoreTemp, weightScoreTemp + n, cmp);

    float minS = weightScoreTemp[k - 1];//第k个数
    float minSNext = n > k ? weightScoreTemp[k] : -1;//第k+1个数
    if (fabs(minSNext - minS) <= EPSILON)
    {
        for (int i = 0; i < n; i++)
        {
            if (fabs(weightScore[i] - minS) <= EPSILON)
            {
                indexs[i] = 3;
            }
            else if (weightScore[i] > minS)
            {
                indexs[i] = 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (weightScore[i] >= minS)
            {
                indexs[i] = 1;
            }
        }
    }

    if (max[loseCol] <= C)
    {
        for (int index = max[loseCol] + 1; index <= C; index++)
        {

            max[loseCol] = index;
            score[loseRow][loseCol] = index;
            for (int i = 0; i < n; i++)
            {
                weightScore[i] = 0;
                weightScoreTemp[i] = 0;
                for (int j = 0; j < m; j++)
                {
                    if (max[j] != 0)
                    {
                        weightScore[i] += (score[i][j] * 1.0 / max[j]) * (1.0 * weight[j] / weightSum);
                        weightScoreTemp[i] += (score[i][j] * 1.0 / max[j]) * (1.0 * weight[j] / weightSum);
                    }
                }
            }

            sort(weightScoreTemp, weightScoreTemp + n, cmp);

            float minS = weightScoreTemp[k - 1];//第k个数
            float minSNext = n > k ? weightScoreTemp[k] : -1;//第k+1个数
            if (fabs(minSNext - minS) <= EPSILON)
            {
                for (int i = 0; i < n; i++)
                {
                    if (fabs(weightScore[i] - minS) <= EPSILON)
                    {
                        indexsTemp[i] = 3;
                    }
                    else if (weightScore[i] > minS)
                    {
                        indexsTemp[i] = 1;
                    }
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (weightScore[i] >= minS)
                    {
                        indexsTemp[i] = 1;
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (indexs[i] ^ indexsTemp[i])
                {
                    indexs[i] = 3;
                }
                indexsTemp[i] = 2;//初始化
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << indexs[i] << endl;
    }
    delete[] max;
    delete[] indexs;
    delete[] indexsTemp;
    delete[] weightScoreTemp;
    delete[] weightScore;
    delete[] weight;
    delete[] score;


    return 0;
}
