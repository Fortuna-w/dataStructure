#pragma once
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student {
	char id[15];		//准考证号
	int score;			//分数
	int location_number;			//考场号
	int location_rank;				//考场排名
}stu[30010];
bool cmp(Student a, Student b) {
	if (a.score != b.score)
		return a.score > b.score;		//先按分数从高到低排序
	return strcmp(a.id , b.id) < 0;		//分数相同按准考证号从小到大排序
}
void test_ranking() {
	int n, k, num = 0;		//num为总考生数
	scanf("%d", &n);		//n为考场数
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);		//该考场内人数
		for (int j = 0; j < k; j++) {
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;		//该考生的考场号为i
			num++;		//总考生数加1
		}
		sort(stu + num - k, stu + num, cmp);		//将该考场的考试排序
		stu[num - k].location_rank = 1;			//该考场第1名的location_rank记为1
		for (int j = num - k + 1; j < num; j++) {			//对该考场剩余的考生
			if (stu[j].score == stu[j - 1].score) {			//如果与前一位考生同分
				//location_rank也相同
				stu[j].location_rank = stu[j - 1].location_rank;
			}
			else {			//如果与前一位考生不同分
				//location_rank为该考生前的人数
				stu[j].location_rank = j + 1 - (num - k);
			}
		}
	}
	printf("%d\n", num);			//输出总考生数
	sort(stu, stu + num, cmp);		//将所有考生排序
	int r = 1;			//当前考生的排名
	for (int i = 0; i < num; i++) {
		if (i > 0 && stu[i].score != stu[i - 1].score) {
			r = i + 1;		//当前考生与上一个考生分数不同时，让r更新为人数+1
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