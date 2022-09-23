/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    int n = 1000000000;
    vector<bool> is_prime(n + 1, true);// is_prime[i] = true if i is prime
    is_prime[0] = is_prime[1] = false;// 0 and 1 are not prime
    for (int i = 2; i <= n; i++)// loop from 2 to n
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
            /*  
                এখানে i^2 থেকে শুরু করবে , কারণ 
                i এর আগে যে প্রাইম নাম্বার থাকবে(i-1) সেটা 
                i পর্যন্ত composite number cover করবে । 
                কারণ কোন নাম্বার প্রাইম কিনা সেটা চেক করার জন্য 
                তার sqrt পর্যন্ত চেক করলেই হয় । এখানে তার opposite হবে । 
                ২ ,৩,৪,৫ এর উদাহরণ নেওয়া যায় যখন n=২৫। এখানে ,
                ২ কভার করবে = ৪,৬,৮,১০,১২,১৪,১৬,১৮,২০,২২,২৪,২৬,২৮,৩০,৩২,৩৪,৩৬,৩৮,৪০
                ৩ কভার করবে = ৯,১২,১৫,১৮,২১,২৪,২৭,৩০,৩৩,৩৬,৩৯
                ৪ কভার করবে = ১৬,২০,২৪
                ৫ কভার করবে = ২৫,৩০,৩৫,৪০
                এখানে দেখা যায় এ 
                ৩ এর আগের সব composite ২ কভার করে , আর 
                ৪ এর আগের সব composite ২,৩ কভার করে , আর
                ৫ এর আগের সব composite ২,৩,৪ কভার করে , আর

                j এর মান ১ করে বাড়বে আর i এর সাথে গুন হবে।
            */

            {
                is_prime[j] = false;
            }
        }
    }

    return 0;
}
/*
Number of data              Time(ms)
1                             0.001
10                            0.003
100                           0.009
1000                          0.089
10000                         0.937
100000                        9.093
1000000                      79.350
10000000                    728.234
100000000                  7666.980
1000000000                89301.500
*/ 