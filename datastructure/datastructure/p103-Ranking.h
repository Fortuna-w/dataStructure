#pragma once
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student {
	char id[15];		//׼��֤��
	int score;			//����
	int location_number;			//������
	int location_rank;				//��������
}stu[30010];
bool cmp(Student a, Student b) {
	if (a.score != b.score)
		return a.score > b.score;		//�Ȱ������Ӹߵ�������
	return strcmp(a.id , b.id) < 0;		//������ͬ��׼��֤�Ŵ�С��������
}
void test_ranking() {
	int n, k, num = 0;		//numΪ�ܿ�����
	scanf("%d", &n);		//nΪ������
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);		//�ÿ���������
		for (int j = 0; j < k; j++) {
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;		//�ÿ����Ŀ�����Ϊi
			num++;		//�ܿ�������1
		}
		sort(stu + num - k, stu + num, cmp);		//���ÿ����Ŀ�������
		stu[num - k].location_rank = 1;			//�ÿ�����1����location_rank��Ϊ1
		for (int j = num - k + 1; j < num; j++) {			//�Ըÿ���ʣ��Ŀ���
			if (stu[j].score == stu[j - 1].score) {			//�����ǰһλ����ͬ��
				//location_rankҲ��ͬ
				stu[j].location_rank = stu[j - 1].location_rank;
			}
			else {			//�����ǰһλ������ͬ��
				//location_rankΪ�ÿ���ǰ������
				stu[j].location_rank = j + 1 - (num - k);
			}
		}
	}
	printf("%d\n", num);			//����ܿ�����
	sort(stu, stu + num, cmp);		//�����п�������
	int r = 1;			//��ǰ����������
	for (int i = 0; i < num; i++) {
		if (i > 0 && stu[i].score != stu[i - 1].score) {
			r = i + 1;		//��ǰ��������һ������������ͬʱ����r����Ϊ����+1
		}
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].location_rank);
	}
}
/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

*/