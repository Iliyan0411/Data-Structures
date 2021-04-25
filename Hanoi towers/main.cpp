#include <iostream>
#include <stack>

void playHanoi(int k, char from, char to, char temp)
{
    if(k == 1)
    {
        std::cout << "Move one disk from " << from << " to " << to << std::endl;
        return;
    }

    playHanoi(k-1, from, temp, to);
    playHanoi(1, from, to, temp);
    playHanoi(k-1, temp, to, from);
}

struct HanoiPar{
    int k;
    char from, to, temp;
};

void playHanoiIter(int k, char from, char to, char temp)
{
    std::stack<HanoiPar> s;
    s.push({k,from,to,temp});

    while(!s.empty())
    {
        HanoiPar current = s.top(); 
        s.pop();

        if(current.k == 1){
            std::cout << "Move one disk from " << current.from << " to " << current.to << std::endl;
        }else
        {
            s.push({current.k-1, current.temp, current.to, current.from});
            s.push({1, current.from, current.to, current.temp});
            s.push({current.k-1, current.from, current.temp, current.to});
        }

    }
}

int main()
{
    playHanoi(3, 'A', 'C', 'B');


    return 0;
}
