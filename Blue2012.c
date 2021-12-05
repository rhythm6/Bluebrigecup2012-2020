#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//第一题
//假设有两种微生物X和Y，X出生后每隔3分钟分裂一次（数目加倍），Y出生后每隔2分钟分裂一次（数目加倍）。
//一个新出生的X，半分钟之后吃掉1个Y，且从此开始每隔1分钟吃掉1个Y。已知新出生的X = 10，Y = 89，求60分钟后Y的数目。
//若X = 10，Y = 90呢？
//本题的要求就是写出这两种初始条件下，60分钟后Y的数目。
//题目的结果令你震惊吗？这不是简单的数字游戏！真实的生物圈有着同样脆弱的性质！
//也许因为你消灭的那只Y就是最终导致Y种群灭绝的最后一根稻草！

// i= 0,x = 10,y = 89| i = 1， x = 10, y = y-x| i=2， x = 10 ,y = 79 |
// i=3,x=10,y = 69   | i = 4,x = 10 y = 158| i=5,x = 10,y=158-x=148
// i=6,x=x*2=20 y = 148 | i = 7 ,x = 20,y = 148-x = 128
//由此可见 x的数量不用管 一到时间就翻倍即可 y的数量当i为奇数时就减去一个x(每隔一分钟) 这道题要是改为且从此开始每隔一分钟吃n个Y就难了(n!=1)
//int main() 
//{
//	int x = 10;
//	int y = 90;
//	int i = 0;
//	for (i = 0; i<120;i++)//i表示30s
//	{
//		if (i % 2 == 1)//判断是否为奇数 是的话 y就被x吃
//		{
//			y = y - x;
//		}
//		if (i % 4 == 0)//每俩分钟y的数量翻倍
//		{
//			y = 2 * y;
//		}
//		if (i % 6 == 0)//每三分钟x的数量翻倍
//		{
//			x = 2 * x;
//		}
//	}
//	printf("x = %d y = %d ",x,y);//x = 10485760 y = -979369984 //也就是说x = 10 y = 89时 y在60分钟结果为0
//	//若x = 10 y = 90 x = 10485760 y = 94371840
//	return 0;
//}

//第二题：古堡算式 福尔摩斯到某古堡探险，看到门上写着一个奇怪的算式：ABCDE* ? = EDCBA。
//他对华生说：“ABCDE应该代表不同的数字，问号也代表某个数字！” 华生：“我猜也是！”，于是，两人沉默了好久，还是没有算出合适的结果来。
//请你利用计算机的优势，找到破解的答案，把ABCDE所代表的数字写出来。
//暴力杯 雀氏暴力 没看到ABCDE代表不同的数字这个条件
//int main() 
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	int x = 0;
//	for (int a = 1; a <=9; a++)
//	{
//		for (int b = 0; b<=9; b++)
//		{
//			for (int c = 0; c<=9; c++)
//			{
//				for (int d = 0; d<=9; d++)
//				{
//					for (int e = 0; e<=9; e++)
//					{
//						for (int x = 0; x<=9; x++)
//						{
//							if ( ((a * 10000 + b * 1000 + c * 100 + d * 10 + e) * x) == (e * 10000 + d * 1000 + c * 100 + b * 10 + a))
//							{
//								if (a!=b &&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)
//								{
//									printf("a = %d  b = %d  c = %d d = %d e = %d ?= %d \n", a, b, c, d, e, x);
//									//巨笨的方法 算出结果为a = 2  b = 1  c = 9 d = 7 e = 8 ?= 4
//								}
//							}
//							
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//方法2
//由于这5个数分别是个位十位百位千位 所以可以用取余的方法表示这五个数 注意int型的最大长度是32767
//所以要用10w以上的数 不能用int型
//要细心细心在细心 每一步都要想清楚再打
//int main() 
//{
//	 int a,b,c,d,e ;//范围是 -2147483647~+2147483647
//	 long int i = 0;
//	for (i = 10000; i <= 99999; i++)//注意这个数一定>=10000 <=99999所以起始条件写上i=10000 终止条件<=999999
//	{
//		a = i / 10000;//a = i % 10000;错误 例如a=34000 %10000 = 4000
//		b = (i / 1000) % 10;
//		c = (i / 100) % 10;
//		d = (i / 10) % 10;
//		e = i % 10;
//		int x = 0;
//		for (x = 0; x <= 9; x++)
//		{
//			if ((e * 10000 + d * 1000 + c * 100 + b * 10 + a) == i*x)
//			{
//				if(a != b && a != c && a != d && a != e && b != c && b != d && b != e && c != d && c != e && d != e)
//				{
//					printf("%d %d", i,x);
//				}	
//			}
//		}
//	}
//}

//第三题：比酒量
//题目描述
//有一群海盗（不多于20人），在船上比拼酒量。过程如下：打开一瓶酒，所有在场的人平分喝下，有几个人倒下了。
//再打开一瓶酒平分，又有倒下的，再次重复----直到开了第4瓶酒，坐着的已经所剩无几，海盗船长也在其中。
//当第4瓶酒平分喝下后，大家都倒下了。等船长醒来，发现海盗船搁浅了。他在航海日志中写到：“…昨天，我正好喝了一瓶…奉劝大家，开船不喝酒，喝酒别开船…”
//请你根据这些信息，推断开始有多少人，每一轮喝下来还剩多少人。如果有多个可能的答案，请列出所有答案，每个答案占一行。格式是：人数，人数，…
//例如，有一种可能是：20, 5, 4, 2, 0
//题目分析:首先这群海盗最多有20人 每次最少要喝倒一个人 所以四轮最少有四个人 船长喝4轮加起来的酒刚好是一瓶(注意由于1瓶酒要均分 所以比较类型肯定要浮点型)  四轮全都喝完了
//int main() 
//{
//	int a, b, c, d;//分别代表海盗人数 第一轮喝完后的海盗人数 第二轮喝完后的海盗人数 第三轮喝完后的海盗人数 第四轮的喝完后为0不用管
//	for (a = 20; a >= 4; a--)
//	{
//		for (b = a - 1; b >= 3; b--) 
//		{
//			for (c = b - 1; c >=2; c--) 
//			{
//				for (d = c - 1; d >=1; d--)
//				{
//						if ((float)(1.0/a+1.0/b+1.0/c+1.0/d) == 1.0)
//						{
//							printf("%d %d %d %d，0\n", a, b, c, d);
//						}
//				}
//			}
//		}
//	}
//	return 0;
//}
// 
//第四题：奇怪的比赛
//题目描述
//某电视台举办了低碳生活大奖赛。题目的计分规则相当奇怪：每位选手需要回答10个问题（其编号为1到10）,
//越后面越有难度。答对的，当前分数翻倍；答错了则扣掉与题号相同的分数（选手必须回答问题，不回答按错误处理）。
//每位选手的起步分都是10分，某获胜选手最终得分刚好是100分，如果不让你看比赛过程，你能推断出他（她）哪个题目答对了，哪个题目答错了吗？
//如果把答对的记为1，答错的记为0，则10个题目的回答情况可用仅含1和0的串来表示，如0010110011就是可能的情况。
//你的任务是算出所有可能情况，每个答案占一行。
//一般来说递推(一步步向前推进得出结果)的效率是高于(递归的) 因为递归一次就要调用一次函数就要压栈一次
//方法一(笨方法)  先定义一个数组 然后用这个数组来存放每次判断的值0,1 采用穷举法 把所有结果列出 然后进行判断
//int main() 
//{
//	int arr[11] = { 0 };//要么初始到11 要不直接不写 因为写的下标是1开始的到10结束 实际上是0开始10结束 
//	for (arr[1] = 0; arr[1] <= 1; arr[1]++) 
//	{
//		for (arr[2] = 0; arr[2] <= 1; arr[2]++)
//		{
//			for (arr[3] = 0; arr[3] <= 1; arr[3]++)
//			{
//				for (arr[4] = 0; arr[4] <= 1; arr[4]++)
//				{
//					for (arr[5] = 0; arr[5] <= 1; arr[5]++)
//					{
//						for (arr[6] = 0; arr[6] <= 1; arr[6]++)
//						{
//							for (arr[7] = 0; arr[7] <= 1; arr[7]++)
//							{
//								for (arr[8] = 0; arr[8] <= 1; arr[8]++)
//								{
//									for (arr[9] = 0; arr[9] <= 1; arr[9]++)
//									{
//										for (arr[10] = 0; arr[10] <= 1; arr[10]++)
//										{
//											int i =1;
//											int grade = 10;//总共有2^10个结果 每次算结果时先初始化grade的值 必须写在这 否则grade不会被再次初始化为10
//											for (i = 1; i<=10;i++)
//											{
//												if (arr[i] == 1)
//												{
//													grade *= 2;
//												}
//												else 
//												{
//													grade -= i;
//												}
//											}
//											if (grade == 100)
//											{
//												for (i = 1; i <= 10; i++) 
//												{
//													printf("%d", arr[i]);
//												}
//												printf("\n");
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
 
//递归实现
//int i = 0;
//int arr[11] = { 0 };
////用递归最好把能定义在外面的变量都在递归外面定义
//void competition(int grade , int time) 
//{
//	//int arr[11] = { 0 };//若这条语句写在这里直接报栈溢出 因为最后有2^10个结果 每递归一次都会定义一个int arr[]的数组 而这个数组的长度是44个字节
//	if (time > 11) 
//	{
//		return;//没满足条件直接结束
//	}
//	if (grade == 100 && time == 11)
//	{
//
//		for (i = 1; i <= 10; i++)
//		{
//			printf("%d", arr[i]);
//		}
//		printf("\n");
//		return ;
//	}
//	arr[time] = 1;//注意这里不能写在if里面 因为不需要条件 必定要执行递归的
//	competition(grade *2, time + 1);//下一次递归的条件写成grade *= grade了 实际上递归的下一次是grade = 你传入的参数 所以你传grade *= grade他就懵了
//
//	arr[time] = 0;
//	competition(grade - time, time + 1);
//}
////用递归方式实现 开始传入初始分值和循环的次数
//int main() 
//{
//	competition(10, 1);
//	return 0;
//}