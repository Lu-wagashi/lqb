![image](https://user-images.githubusercontent.com/72455267/230156751-181ffd66-13fc-4f8d-9f80-49a37951b2b0.png)
做C题、D题、I题、

DFS模版、STL的sort、全排列next_generation、set容器、优先队列容器


DFS模版：讲解：https://zhuanlan.zhihu.com/p/368452751

void dfs(int x, ... )
{
    if( 递归结束条件 )
        .... 逻辑语句
    for( ... ) //选择
    {
        if( ... ) continue; / break;   //剪枝
         {
            ...记录
            dfs()
            ... 回溯
          }
     }
 }
