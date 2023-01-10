#include <iostream>
#include <vector>
using namespace std;
struct NumAndPow
{
    long long int num;
    int pow;
};
long long int returnBiggestIndex(vector<NumAndPow> &arr)
{
    long long int cur = 0; 
    for(long long int i = 0; i < arr.size(); i++)
    {
        if (arr[cur].num < arr[i].num)
        {
            cur = i;
        }
    }
    return cur;
}

long long int returnBiggestNumber(vector<NumAndPow> &arr)
{
    long long int cur = 0; 
    long long int ans = arr[0].num;
    for(long long int i = 0; i < arr.size(); i++)
    {
        if (arr[cur].num < arr[i].num)
        {
            cur = i;
            ans = arr[i].num;
        }
    }
    return ans;
}

int main()
{
    long long int E[64];
    E[0] =  1;
    E[1] =  2;
    E[2] =  4;
    E[3] =  8;
    E[4] =  16;
    E[5] =  32;
    E[6] =  64;
    E[7] =  128;
    E[8] =  256;
    E[9] =  512;
    E[10] = 1024;
    E[11] = 2048;
    E[12] = 4096;
    E[13] = 8192;
    E[14] = 16384;
    E[15] = 32768;
    E[16] = 65536;
    E[17] = 131072;
    E[18] = 262144;
    E[19] = 524288;
    E[20] = 1048576;
    E[21] = 2097152;
    E[22] = 4194304;
    E[23] = 8388608;
    E[24] = 16777216;
    E[25] = 33554432;
    E[26] = 67108864;
    E[27] = 134217728;
    E[28] = 268435456;
    E[29] = 536870912;
    E[30] = 1073741824;
    E[31] = 2147483648;
    E[32] = 4294967296;
    E[33] = 8589934592;
    E[34] = 17179869184;
    E[35] = 34359738368;
    E[36] = 68719476736;
    E[37] = 137438953472;
    E[38] = 274877906944;
    E[39] = 549755813888;
    E[40] = 1099511627776;
    E[41] = 2199023255552;
    E[42] = 4398046511104;
    E[43] = 8796093022208;
    E[44] = 17592186044416;
    E[45] = 35184372088832;
    E[46] = 70368744177664;
    E[47] = 140737488355328;
    E[48] = 281474976710656;
    E[49] = 562949953421312;
    E[50] = 1125899906842624;
    E[51] = 2251799813685248;
    E[52] = 4503599627370496;
    E[53] = 9007199254740992;
    E[54] = 18014398509481984;
    E[55] = 36028797018963968;
    E[56] = 72057594037927936;
    E[57] = 144115188075855872;
    E[58] = 288230376151711744;
    E[59] = 576460752303423488;
    E[60] = 1152921504606846976;
    E[61] = 2305843009213693952;
    E[62] = 4611686018427387904;
    //E[63] = 9223372036854775808;

    long long int N_size;
    long long int K_how_much_brick;
    cin >> N_size;
    long long int save = N_size;
    cin >> K_how_much_brick;
    long long int used = 0;
    long long int down = 0;
    vector<NumAndPow> data(K_how_much_brick);
    for(long long int i = 0; i < K_how_much_brick; i++)
    {
        data[i].num = -1;
        data[i].pow = -1;
    }
    if ((N_size % 2) == 1)
    {
        used++;
        data[0].num = 1;
        data[1].pow = 0;
        N_size--;
    }
    while(N_size != 0)
    {
        for (long long int i = 62 ; i >= 0; i--)
        {
            if (E[i] <= N_size)
            {
                N_size -= E[i];
                data[used].num = (E[i]);
                data[used].pow = i;
                used++;
            }
            if (used == K_how_much_brick && N_size != 0)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    long long int left = K_how_much_brick - used;
    while(left != 0)
    {
        left++;
        long long int big_index = returnBiggestIndex(data);
        long long int big_num = returnBiggestNumber(data);
        for(long long int i = data[big_index].pow; i >= 0; i--)
        {
            if (E[i] <= left)
            {
                if (E[i] == 1)
                {
                    data[big_index].num = 1;
                    data[big_index].pow = 0;
                }
                else
                {
                    long long int new_num = big_num / E[i];
                    data[big_index].num = new_num;
                    data[big_index].pow = i;
                    long long int ctr = 1;
                    for(long long int j = 0; j < K_how_much_brick; j++)
                    {
                        if (ctr == E[i])
                        {
                            break;
                        }
                        if (data[j].num == -1)
                        {
                            data[j].num = new_num;
                            data[j].pow = i;
                            ctr++;
                        }
                    }
                    left -= E[i];
                }
                break;
            }
        }
    }
    long long int check = 0;
    for (long long int i = 0; i < K_how_much_brick; i++)
    {
        check += data[i].num;
    }
    if (check != save)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(long long int i = 0; i < K_how_much_brick; i++)
    {
        cout << data[i].num << " ";
    }
    return 0;
}