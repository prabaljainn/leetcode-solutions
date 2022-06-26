class Solution
{
    
/*
UP -> 0
Down ->1

LEFT ->2
Right ->3
*/
    public:

        int dx[4]  { 0,0,-1,1};
    int dy[4]  { 1,-1,0,0};

    int moveLeft(int dir)
    {
        if (dir == 2)
            return 1;
        else if (dir == 3)
            return 0;
        else if (dir == 1)
            return 3;
        else return 2;
    }
    int moveRight(int dir)
    {
        if (dir == 0)
            return 3;
        else if (dir == 1)
            return 2;
        else if (dir == 3)
            return 1;
        else return 0;
    }
    bool isRobotBounded(string ins)
    {
        int x = 0, y = 0, dir = 0;
        ins += ins +ins+ins;

        for (char val: ins)
        {
            if (val == 'L')
                dir = moveLeft(dir);
            else if (val == 'R')
                dir = moveRight(dir);
            else
            {
                x += dx[dir];
                y += dy[dir];
                
               
            }
            
        }
        if (x == 0 and y == 0)
            return true;
        else return false;
    }
};
