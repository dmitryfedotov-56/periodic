    /***********************************************************/
    /*                        Periodic Line                    */
    /***********************************************************/

    #include <iostream>
    using namespace std;

    #include "stdio.h"

    /***********************************************************/

    bool same(unsigned n, char* s1, char* s2)
    {
        for (unsigned i = 0; i < n; i++)
            if (s1[i] != s2[i]) return false;
        return true;
    };

    /***********************************************************/

    void show(unsigned p, string s)
    {
        cout << p << " ";
        for (unsigned i = 0; i < p; i++)putchar(s[i]);
        cout << endl;
    };

    /***********************************************************/

    unsigned candidate(unsigned p, string s)
    {
        unsigned half = s.size() / 2;
        for (unsigned n = p + 1; n <= half; n++)
            if (same(n, &s[0], &s[n])) return n;
        return 0;
    };

    /***********************************************************/

    bool isPeriod(unsigned p, string s)
    {
        if ((s.size() % p) != 0)return false;
        for (unsigned n = 2 * p; n < s.size(); n += p)
            if (!same(p, &s[0], &s[n]))return false;
        return true;
    };

    /***********************************************************/

    unsigned IsKPeriodic(string s)
    {
        unsigned p = candidate(0, s);
        while (p != 0)
        {
            show(p, s);
            if (isPeriod(p, s))return p;
            p = candidate(p, s);
        };
        return 0;
    };

    /***********************************************************/
    /*
        int main()
        {
            string s = "";

            // s = "AAAABBAAAABB";

            // s = "ABBAABB";

            // s = "ABABAB";

            // s = "QUEENQUEENQUEEN";

           // s = "MAGIC LINE";

           // s = "ABABBAABABBA";

            // s = "ABAB";

            // s = "AAAAAAAAAAAAAAAB";

            // s = "AAAAAAAAAAAAAAAA";

            unsigned k = IsKPeriodic(s);
            cout << k << endl;
            if (k != 0)show(k, s);

            return 0;
        };
    */

    /***********************************************************/
