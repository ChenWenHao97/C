/*
算法训练 Lift and Throw  
问题描述
　　给定一条标有整点(1, 2, 3, ...)的射线. 定义两个点之间的距离为其下标之差的绝对值.
　　Laharl, Etna, Flonne一开始在这条射线上不同的三个点, 他们希望其中某个人能够到达下标最大的点.
　　每个角色只能进行下面的3种操作, 且每种操作不能每人不能进行超过一次.
　　1.移动一定的距离
　　2.把另一个角色高举过头
　　3.将举在头上的角色扔出一段距离
　　每个角色有一个movement range参数, 他们只能移动到没有人的位置, 并且起点和终点的距离不超过movement range.
　　如果角色A和另一个角色B距离为1, 并且角色B没有被别的角色举起, 那么A就能举起B. 同时, B会移动到A的位置,B原来所占的位置变为没有人的位置. 被举起的角色不能进行任何操作, 举起别人的角色不能移动.同时, 每个角色还有一个throwing range参数, 即他能把举起的角色扔出的最远的距离. 注意, 一个角色只能被扔到没有别的角色占据的位置. 我们认为一个角色举起另一个同样举起一个角色的角色是允许的. 这种情况下会出现3个人在同一个位置的情况. 根据前面的描述, 这种情况下上面的两个角色不能进行任何操作, 而最下面的角色可以同时扔出上面的两个角色. 你的任务是计算这些角色能够到达的位置的最大下标, 即最大的数字x, 使得存在一个角色能够到达x.
输入格式
　　输入共三行, 分别为Laharl, Etna, Floone的信息.
　　每一行有且仅有3个整数, 描述对应角色的初始位置, movement range, throwing range.
　　数据保证3个角色的初始位置两两不相同且所有的数字都在1到10之间.</div>
输出格式
　　仅有1个整数, 即Laharl, Etna, Flonne之一能到达的最大距离.
样例输入
9 3 3
4 3 1
2 3 3
样例输出
15
样例说明
　　一开始Laharl在位置9, Etna在位置4, Flonne在位置2.
　　首先, Laharl移动到6.
　　然后Flonne移动到位置5并且举起Etna.
　　Laharl举起Flonne将其扔到位置9.
　　Flonne把Etna扔到位置12.
　　Etna移动到位置15.
*/
#include<stdio.h>
#define false 0
#define true 1
#define NOONE -1
struct PERSON {
    int can_move, can_lift, can_throw;//可以移动，举起，扔人
    int becarried_by, carried_who; // 被举起来，举起谁
    int nowpos, moverange, throwrange;//现在位置，移动范围，扔人范围
} persons[3];

int ret = 0;

int distance(int a, int b)//a，b间的距离
{
    return (persons[a].nowpos > persons[b].nowpos) ? 
                persons[a].nowpos - persons[b].nowpos:
                persons[b].nowpos - persons[a].nowpos;
}

int dist(int a, int pos)//计算a到pos的距离
{
    return (persons[a].nowpos > pos) ? 
                persons[a].nowpos - pos:
                pos - persons[a].nowpos;
}

int occupied(int pos)//三个点是否在pos位置上
{
    return persons[0].nowpos == pos || persons[1].nowpos == pos || persons[2].nowpos == pos;
}

int has_someone_near(int pos)//三个点的附近是否有人
{
    return (dist(0, pos) <= 1 || dist(1, pos) <= 1 || dist(2, pos) <= 1);
}

void dfs()
{
    for (int i = 0; i < 3; i++)//找出现在距离最大
    {
        if (persons[i].nowpos > ret)
            ret = persons[i].nowpos;
    }
    //移动
    for (int i = 0; i < 3; i++)
    {
        if (persons[i].can_move && persons[i].becarried_by == NOONE && persons[i].carried_who == NOONE)
        {
            //如果人没有移动过，没有被举起来，没有举起人，就可以移动
            for (int k = -persons[i].moverange; k <= persons[i].moverange; k++)
            {
                //移动范围从负数到正数
                int newpos = persons[i].nowpos + k;
                if (occupied(newpos))//该点位置有人，所以不能移动
                    continue;
                if (!has_someone_near(newpos) && k != persons[i].moverange)
                //如果附近没有人，或者没有到最大极限，移动到该点不能使距离最大
                    continue;

                persons[i].can_move = false;//移动过了
                persons[i].nowpos += k;//跟新位置

                dfs();

                persons[i].can_move = true;//回溯
                persons[i].nowpos -= k;
            }
        }
    }
    //举人
    for (int i = 0; i < 3; i++)
    {//i表示谁举人，j表示被举起的人
        for (int j = 0; j < 3; j++)
        {
            if (i == j) continue;//自己不能举起自己
            if (persons[i].can_lift && distance(i, j) == 1 && persons[i].becarried_by == NOONE && persons[i].carried_who == NOONE)
            {
                int jpos = persons[j].nowpos;//保存被举起人的位置，方便回退
                persons[i].can_lift = false;//改变状态
                persons[i].carried_who = j;//i吧j举起来了
                persons[j].becarried_by = i;//j被举起来了
                persons[j].nowpos = persons[i].nowpos;//更新距离

                dfs();

                persons[i].can_lift = true;//回溯
                persons[i].carried_who = NOONE;
                persons[j].becarried_by = NOONE;
                persons[j].nowpos = jpos;
            }
        }
    }
    //扔人
    for (int i = 0; i < 3; i++)
    {
        if (persons[i].can_throw && persons[i].carried_who != NOONE && persons[i].becarried_by == NOONE)
        {//如果可以被扔，举着人，没有被举起，就可以扔人
            for (int k = -persons[i].throwrange; k <= persons[i].throwrange; k++)
            {
                int oricarry = persons[i].carried_who;//记录被扔的人
                int newpos = persons[oricarry].nowpos + k;//被扔的人计算新位置
                if (occupied(newpos))//如果扔的位置有人，从新选
                    continue;
                if (has_someone_near(newpos) || k == persons[i].throwrange)
                {
                //因为扔到有人的地方，还会扔的更远
                //扔到最远也符合
                    persons[i].can_throw = false;//改变状态
                    persons[i].carried_who = NOONE;
                    persons[oricarry].becarried_by = NOONE;
                    persons[oricarry].nowpos += k;

                    dfs();

                    persons[i].can_throw = true;//回溯
                    persons[i].carried_who = oricarry;
                    persons[oricarry].becarried_by = i;
                    persons[oricarry].nowpos -= k;
                }
            }
        }
    }
}

void init()//初始化
{
    ret = 0;
    for (int i = 0; i < 3; i++)
    {
        persons[i].can_lift = persons[i].can_move = persons[i].can_throw = true;
        persons[i].carried_who = persons[i].becarried_by = NOONE;
    }
}

int main(void)
{
    init();
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d %d", &persons[i].nowpos, &persons[i].moverange, &persons[i].throwrange);
    }

    dfs();
    printf("%d\n", ret);

    return 0;
}