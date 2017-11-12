/*	�������ƣ����������������
	��Ҫ���ܣ����������������鿴������Ϣ����ӡ���¹����������ӣ�ѹ���ļ�����ѹ�ļ�
	��׳��  ����һЩ�Ƿ�������������˿��ƣ���ȻӦ�û��кܶ಻��ĵط��д��Ľ�
	������  ��������һ������������зֽ��棬����������ֽ���֮�����������ת
																			Ҷ�ݷ�
																			���пƼ���ѧͨ�Ź���     */

#include "all_header.h"            //�Լ���֯������Ԥ����ͷ�ļ�

int main()
{
	double *w;                   //���ÿ���ַ�����
	char *content;               //����ַ�����w��Ӧ
	int n;                      //���Ҷ����     
	HuffmanTree HT;                  //HT�����������
	HuffmanCode HC;                  //���ÿһ��Ҷ�ӵĹ���������
	
	printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
	count(w, n, content);               //ͳ�Ƹ����ı��ĸ����ַ��ĸ��ʣ��õ�w��ÿ���ַ���Ȩ�أ���content�����ݣ����ַ���Ŀ��
	CreatHuffman(HT, w, n);        //����w������һ����n��Ҷ�ӵĹ�������HT
	HuffmanCoding(HT, HC, n);          //�����Ѿ�����õĹ�������HT���ÿһ��Ҷ�ӵĹ��������룬�Ҵ洢��HC����

	while (1)
	{//����������
		printf("                             << =================== ��   ��   ѡ   �� ================ >>  \n\n");
		printf("                    ��1�� �� ��ʾ��ǰ������������ϸ��Ϣ ��  \n");
		printf("                    ��2�� �� ��ӡ���������������Ĵ������� �� \n");
		printf("                    ��3�� �� �ļ�ѹ�� �����ݵ�ǰ��������������һƪ����ת��Ϊ�������� �� \n");
		printf("                    ��4�� �� �ļ���ѹ�� (���ݵ�ǰ����������ָ���Ķ��������ļ����� ��  \n");
		printf("                    ��5�� �� �˳�����                                               \n\n\n");
		printf("��ѡ���� �� ");
		char ch;
		scanf("%c", &ch);
		char c = getchar();
		while (c!= '\n')       //��������
		{
			c=getchar();
		}
		switch (ch)
		{
			case '1':                     //��ʾ��ǰ������������ϸ��Ϣ
			{
				HuffmanImformation(n,w,content,HC);        //���ú�����ӡ��ϸ��Ϣ
				while (1)
				{//����1�ĵ���ѡ��
					printf("						��a�� �� ������һ�� �� \n");
					printf("						��b�� �� �˳�����   �� \n\n");
					printf("			��ѡ���� :");
					char ch1;
					scanf("%c", &ch1);
					c = getchar();
					while (c != '\n')       //��������
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
							printf("������������������!   \n");
							continue;
						}
					}//switch
					system("cls");
					printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
					break;
				}//����1�ĵ���ѡ��                       
			break;
			}//case '1'

			case '2':                    //��ӡ���������������Ĵ������� 
			{
				PrintTree(2*n-1,HT);     //��ӡ��HT[2*n-1]Ϊ���ڵ�Ĺ�������
				while (1)
				{//����2�ĵ���ѡ��
					printf("					��a�� �� ������һ�� ��\n");
					printf("					��b�� �� �˳�����   ��\n\n\n");
					printf("			 ��ѡ���� :");
					char ch2;
					scanf("%c", &ch2);
					c = getchar();
					while (c != '\n')       //��������
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
							printf("������������������!\n");
							continue;
						}
					}//switch
					system("cls");
					printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
					break;
				}//����2�ĵ���ѡ��
				break;
			}//case '2'

			case '3':                     //�ļ�ѹ��
			{
				CompressTxt(n, w, content, HC);          //�ļ�ѹ��
				while (1)
				{//����3�ĵ���ѡ��
					printf("             ��a�� �� ������һ�� ��\n");
					printf("             ��b�� �� �˳�����   ��\n");
					printf("   ��ѡ���� :");
					char ch3;
					scanf("%c", &ch3);
					c = getchar();
					while (c != '\n')       //��������
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
						printf("������������������! \n");
						continue;
					}
					}//switch
					system("cls");
					printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
					break;
				}//����3�ĵ���ѡ��
				break;
			}//case '3'

			case '4':                    //�ļ���ѹ�� 
			{
				system("cls");           //����
				printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
				HuffmanDecoding(HT, n, content);     //����

				while (1)
				{//����4�ĵ���ѡ��
					printf("             ��a�� �� ������һ�� �� \n");
					printf("             ��b�� �� �˳�����   �� \n");
					printf("   ��ѡ���� :");
					char ch4;
					scanf("%c", &ch4);
					c = getchar();
					while (c != '\n')       //��������
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
						printf("������������������!");
						continue;
					}
					}//switch
					system("cls");
					printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
					break;
				}//����4�ĵ���ѡ��
				break;
			}//case '4'

			case '5':                   //�˳�����
				exit(0);
			default:                     //�������봦��
			{
				system("cls");           //����
				printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
				printf("����ѡ�����������ѡ����ȷ��ѡ�� ! \n");
				break;
			}//default

		}//������switch

	}//������

	system("pause");       //��ֹ����
	return 0;
}

