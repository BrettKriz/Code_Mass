/*
ID: krizba1
PROG: gift1
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

int get_index(string, string [], int);

int main()
{
        ifstream input("gift1.in");
        ofstream output("gift1.out");

        int friends_num = 0;
        input >> friends_num;

        string	friends[100];
        int acount[100];
	
        for (int i = 0; i < friends_num; i++)
        {
                input >> friends[i];
                acount[i] = 0;
        }

        for (; !input.eof() ;)
        {
                string name;
                input >> name;
                int index = get_index(name, friends, friends_num);
                int mony, to;
                input >> mony >> to;

                for (int i = 0; i < to; i++)
                {
                        string to_friend;
                        input >> to_friend;
                        acount[get_index(to_friend, friends, friends_num)] += (int) mony / (int) to;
                }
                acount[index] -= (to == 0 ? 0 : to * ((int) mony / (int) to));
        }

        for (int i = 0; i < friends_num; i++)
                output << friends[i] << " " << acount[i] << endl;
		
        return 0;
}

int get_index(string name, string friends[], int friends_num)
{
        int index = 0;
        for (int i = 0; i < friends_num ; i++)
                if (friends[i] == name)
                {
                        index = i;
                        break;
                }
         return index;
}