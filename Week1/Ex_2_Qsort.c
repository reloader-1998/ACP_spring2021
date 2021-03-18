#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 512

typedef struct student {
    int seat;
    char sid[100];
    char firstName[100];
    int score;
};

int idGenerator(int length, char* output)
{
    int i = 0;

	output[i] = 'A' + rand() % 26;
	for (i = 1; i < length - 1; i++)
	{
		output[i] = '0' + rand() % 10;
	}
	return 0;
}

int nameGenerator(int length, char* output)
{
    int i = 0;

	output[i] = 'A' + rand() % 26;
	for (i = 1; i < length - 1; i++)
	{
		output[i] = 'a' + rand() % 26;
	}
	return 0;
}

int scriptBuilder()
{
    srand((unsigned)time(NULL));

    int i;

    FILE* fp = fopen("script.txt", "w");
    if(!fp) {
        perror("無法開啟來源檔案");
        return EXIT_FAILURE;
    }

    // storing information
    for (i = 0; i < 512; ++i) {
        char id[100] = {};
        int name_length = rand() % 5 + 3;
        char name[100] = {};
        idGenerator(10, id);
        nameGenerator(name_length, name);
        int score = rand() % 101;
        int seat = i + 1;
        fprintf(fp,"%d",seat);
        fprintf(fp,"\t%s", id);
        fprintf(fp,"\t%s", name);
        fprintf(fp,"\t%d\n", score);
    }

    fclose(fp);
    return 0;
}

void readdata(struct student s[],int *n,FILE *fp) {
    int i = 0;
    if(fp == NULL) {
        printf("error: no data to read\n");
        exit(2);
    }
    *n = 0;
    while(!feof(fp) && i < N) {
        fscanf(fp,"%d %s %s %d",&s[i].seat, s[i].sid, s[i].firstName, &s[i].score);
        ++i;
        ++(*n);
    }
}

void show(struct student s[],int n) {
    int i;
    for(i = 0; i < n; ++i) {
        printf("%d\t%s\t%s\t%d\n",s[i].seat, s[i].sid, s[i].firstName,s[i].score);
    }
}

int compare_id(const void *p1, const void *p2)
{
    const struct student* ps1 = p1;
	const struct student* ps2 = p2;

	return(strcmp((char *)ps1->sid,(char *)ps2->sid));
}

int compare_name( const void *p1, const void *p2)

{
    const struct student* ps1 = p1;
	const struct student* ps2 = p2;

	return(strcmp((char *)ps1->firstName,(char *)ps2->firstName));

}

int compare_score( const void *p1, const void *p2)

{
    const struct student* ps1 = p1;
	const struct student* ps2 = p2;

	if (ps1->score < ps2->score) {
     return +1;
    } else if (ps1->score > ps2->score) {
     return -1;
    }
    return 0;
}

void sorting(struct student s[], int flag, int n)
{
    switch(flag){
    case 1:
        printf("----score sorting line----\n");
        qsort(s, N, sizeof(struct student),compare_score);
        show(s,n);
        break;
    case 2:
        printf("----id sorting line----\n");
        qsort(s, N, sizeof(struct student),compare_id);
        show(s,n);
        break;
    case 3:
        printf("----name sorting line----\n");
        qsort(s, N, sizeof(struct student),compare_name);
        show(s,n);
        break;
    default:
        printf("Wrong sorting type!!\n");
    }

}


void scriptSaver(struct student s[])
{
    FILE* fp = fopen("sorted_script.txt", "w");
    if (!fp) {
        printf("txt file open error...\n");
        exit(1);
    }
    int i = 0;
    while(i<512){
        fprintf(fp,"%d",s[i].seat);
        fprintf(fp,"\t%s", s[i].sid);
        fprintf(fp,"\t%s", s[i].firstName);
        fprintf(fp,"\t%d\n", s[i].score);
        i++;
    }
    fclose(fp);

}


int main() {
    scriptBuilder();
    int n = 0;
    FILE *fptr;
    struct student s[N];
    char datafile[] = "script.txt";
    if((fptr = fopen(datafile,"rt")) == NULL) {
        printf("error:%s\n",datafile);
        exit(3);
    }
    readdata(s,&n,fptr);
    show(s,n);


    int flag = 0;
    printf("Enter a num to sort the data. (1 for score; 2 for id ; 3 for name):\t");

    scanf("%d", &flag);

    sorting(s,flag, n);

    scriptSaver(s);

    fclose(fptr);
    return 0;
}

