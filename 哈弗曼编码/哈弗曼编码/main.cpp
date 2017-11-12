/*	程序名称：哈夫曼编码与解码
	主要功能：创建哈夫曼树，查看编码信息，打印大致哈夫曼树样子，压缩文件，解压文件
	健壮性  ：对一些非法输入输出进行了控制，当然应该还有很多不足的地方有待改进
	交互性  ：设置了一个主界面和四中分界面，在主界面与分界面之间可以自由跳转
																			叶逸凡
																			华中科技大学通信工程     */

#include "all_header.h"            //自己组织的所有预编译头文件

int main()
{
	double *w;                   //存放每个字符概率
	char *content;               //存放字符，与w对应
	int n;                      //存放叶子数     
	HuffmanTree HT;                  //HT代表哈弗曼树
	HuffmanCode HC;                  //存放每一个叶子的哈弗曼编码
	
	printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
	count(w, n, content);               //统计给定文本的各个字符的概率，得到w（每个字符的权重）和content（内容）和字符数目。
	CreatHuffman(HT, w, n);        //根据w构造了一颗有n个叶子的哈弗曼树HT
	HuffmanCoding(HT, HC, n);          //根据已经构造好的哈弗曼树HT求出每一个叶子的哈弗曼编码，且存储在HC里面

	while (1)
	{//程序主窗口
		printf("                             << =================== 功   能   选   择 ================ >>  \n\n");
		printf("                    【1】 ： 显示当前哈夫曼编码详细信息 。  \n");
		printf("                    【2】 ： 打印出“哈夫曼树”的大致样子 。 \n");
		printf("                    【3】 ： 文件压缩 （根据当前哈夫曼树把另外一篇文章转化为二进制码 。 \n");
		printf("                    【4】 ： 文件解压缩 (根据当前哈夫曼树把指定的二进制码文件解码 。  \n");
		printf("                    【5】 ： 退出程序。                                               \n\n\n");
		printf("请选择功能 ： ");
		char ch;
		scanf("%c", &ch);
		char c = getchar();
		while (c!= '\n')       //清理缓冲区
		{
			c=getchar();
		}
		switch (ch)
		{
			case '1':                     //显示当前哈夫曼编码详细信息
			{
				HuffmanImformation(n,w,content,HC);        //调用函数打印详细信息
				while (1)
				{//功能1的弹出选项
					printf("						【a】 ： 返回上一级 。 \n");
					printf("						【b】 ： 退出程序   。 \n\n");
					printf("			请选择功能 :");
					char ch1;
					scanf("%c", &ch1);
					c = getchar();
					while (c != '\n')       //清理缓冲区
					{
						c = getchar();
					}
					switch (ch1)
					{
						case 'a':
							break;
						case 'b':
							exit(0);
						default:
						{
							system("cls");
							printf("输入有误，请重新输入!   \n");
							continue;
						}
					}//switch
					system("cls");
					printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
					break;
				}//功能1的弹出选项                       
			break;
			}//case '1'

			case '2':                    //打印出“哈夫曼树”的大致样子 
			{
				PrintTree(2*n-1,HT);     //打印以HT[2*n-1]为根节点的哈夫曼树
				while (1)
				{//功能2的弹出选项
					printf("					【a】 ： 返回上一级 。\n");
					printf("					【b】 ： 退出程序   。\n\n\n");
					printf("			 请选择功能 :");
					char ch2;
					scanf("%c", &ch2);
					c = getchar();
					while (c != '\n')       //清理缓冲区
					{
						c = getchar();
					}
					switch (ch2)
					{
						case 'a':
							break;
						case 'b':
							exit(0);
						default:
						{
							system("cls");
							printf("输入有误，请重新输入!\n");
							continue;
						}
					}//switch
					system("cls");
					printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
					break;
				}//功能2的弹出选项
				break;
			}//case '2'

			case '3':                     //文件压缩
			{
				CompressTxt(n, w, content, HC);          //文件压缩
				while (1)
				{//功能3的弹出选项
					printf("             【a】 ： 返回上一级 。\n");
					printf("             【b】 ： 退出程序   。\n");
					printf("   请选择功能 :");
					char ch3;
					scanf("%c", &ch3);
					c = getchar();
					while (c != '\n')       //清理缓冲区
					{
						c = getchar();
					}
					switch (ch3)
					{
					case 'a':
						break;
					case 'b':
						exit(0);
					default:
					{
						system("cls");
						printf("输入有误，请重新输入! \n");
						continue;
					}
					}//switch
					system("cls");
					printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
					break;
				}//功能3的弹出选项
				break;
			}//case '3'

			case '4':                    //文件解压缩 
			{
				system("cls");           //清屏
				printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
				HuffmanDecoding(HT, n, content);     //解码

				while (1)
				{//功能4的弹出选项
					printf("             【a】 ： 返回上一级 。 \n");
					printf("             【b】 ： 退出程序   。 \n");
					printf("   请选择功能 :");
					char ch4;
					scanf("%c", &ch4);
					c = getchar();
					while (c != '\n')       //清理缓冲区
					{
						c = getchar();
					}
					switch (ch4)
					{
					case 'a':
						break;
					case 'b':
						exit(0);
					default:
					{
						system("cls");
						printf("输入有误，请重新输入!");
						continue;
					}
					}//switch
					system("cls");
					printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
					break;
				}//功能4的弹出选项
				break;
			}//case '4'

			case '5':                   //退出程序
				exit(0);
			default:                     //错误输入处理
			{
				system("cls");           //清屏
				printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
				printf("功能选择错误，请重新选择正确的选项 ! \n");
				break;
			}//default

		}//主界面switch

	}//主界面

	system("pause");       //防止闪退
	return 0;
}

